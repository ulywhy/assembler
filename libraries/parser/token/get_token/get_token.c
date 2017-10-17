
Token * get_token ( KeywordTable keyword_table )
{  
  Token * token = NULL;
  
  size_t line_size = 0;
  /*
   * BUSCAR TOKEN VÁLIDO
   */
  
  /* mientras no se encuentre token y haya lineas en el archivo */
  while( !feof( source_file ) && NULL == token )
  {
    if( NULL == line_ptr )
    {
      /* extraer una linea del archivo fuente */
      getline( &line_ptr, &line_size, source_file );
      /* preparar linea */
      line_ptr_backup = set_line ( line_ptr );
      /* contar linea */
      line_number++;
    }
    if( END_LINE( VALUE( line_ptr ) ) ){
      /* liberar memoria de la linea usando el respaldo */
      free( line_ptr_backup );
      /* hacer NULL para evitar acceder a memoria no reservada */
      line_ptr_backup = NULL;
      line_ptr = NULL;
      line_size = 0;
      /* como es fin de linea es un hecho que no hay token
       * lee linea nueva para analizar */
      continue;
    }
    /* avanzar todos los espacios */
    line_ptr = saltar_espacios( line_ptr );
    
    /* si es letra */
    if( NULL == token && isalpha( VALUE( line_ptr ) ) )
    {
      /* si es hexadeimal */
      token = is_hexadecimal( &line_ptr );
      if( NULL == token )
      {
        /* si ee identificador */
        token = is_identifier( &line_ptr );
        /* buscar en tabla de palabras reservadas */
        if( NULL == token )
        {
          /* error de identificador */
          /* mover al siguiente token */
          line_ptr++;
        }
      }
    }else
    /* 
     * NÚMERO
     */
    if( NULL == token && ( VALUE( line_ptr ) == '+' || 
                           VALUE( line_ptr ) == '-' ||
                           isdigit( VALUE( line_ptr ) ) 
                         ) ){
      /* si es decimal */
      token = is_decimal( &line_ptr);
      if( NULL == token ){
        /* si es binario */
        token = is_binary( &line_ptr);
        if( NULL == token ){
          /* si es octal */
          token = is_octal( &line_ptr);
          if( NULL == token ){
            /* si es hexadecimal */
            token = is_hexadecimal( &line_ptr );
            if( NULL == token ){ /* es hexadecimal */
              /* no hay token valido */
            }
          }
        }
      }
    }else
    /*
     * SÍMBOLO
     *           [ ] [ ! " # $ % & ' ( ) * + , . / : ; < = > ? @ \ ^ _ ` { | } ~ - ]
     * SIMPLE O DOBLE 
     */
    if( NULL == token && ispunct( VALUE( line_ptr ) ) )
    {
      /* analizar simbolo */
      token = is_symbol( &line_ptr );
      if( token != NULL ){
        switch( token-> value[0] ){
          
          case '"':
            free( token-> value );
            free( token );
            token = is_literal( &line_ptr );
            if( token != NULL ){
              token-> type = LITERAL;
            }
          break;

          case ';':
            token-> type = COMENTARIO;
            free(token-> value);
            line_ptr--; /* volver un simbolo para considerar el ';' */
            token-> value = strdup( line_ptr );
            /* apuntar al final de la linea */
            line_ptr = index( line_ptr, '\0' );
          break;

          case '.':
            free( token-> value );
            free( token );
            token = is_identifier( &line_ptr );
            if( token != NULL ){
              if( 0 <= keyword_find ( keyword_table, token-> value ) )
              {
                token-> type = DIRECTIVA;
              }
            }
          break;
        }
      }
    }
  }
  return token;
}