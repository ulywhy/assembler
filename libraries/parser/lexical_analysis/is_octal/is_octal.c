/*
 * analiza los caracteres iniciales y decide si hay un numero octal,
 * devuelve apuntador a memoria dinámica (debe usar free() )
 */
Token * is_octal( string * line_ptr ){

  char * number_start = VALUE( line_ptr );
  char * number_end = VALUE( line_ptr );
  Token * token = NULL;
  /* recorrer la linea hasta que se agoten los digitos octales */
  while(  isdigit( VALUE( number_end ) ) && VALUE( number_end ) != '8' && VALUE ( number_end ) != '9' ) {
    /* avanzar un caracter sobre la linea */
    *number_end++;
  }
  /* comparar con el delimitador de número octales (o) */
  if( tolower( VALUE( number_end ) ) == 'o' ){/* hay un posible octal */
    /* avanzar un caracter sobre la linea */
    *number_end++;
    if( DELIMITER( VALUE( number_end ) ) ){
      /* ¡¡¡es un octal!!! */
      /* crear numero */
      token = token_create( CONSTANTE, number_start, number_end );
      
      *line_ptr = number_end;
    }else{
     /* error de formato, hay algo despues de 'o' que no es delimitador */
    }
  }else{
    /* no termina con 'o' */
  }
  return token;
}
