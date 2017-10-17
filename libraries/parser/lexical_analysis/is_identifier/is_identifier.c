/*
 * analiza los caracteres iniciales y decide si hay un identificador,
 * devuelve apuntador a memoria dinámica (debe usar free() )
 */
Token * is_identifier( string * line_ptr ){

  char * identifier_start = VALUE( line_ptr );
  char * identifier_end = VALUE( line_ptr );
  Token * token = NULL;
  /* recorrer la linea hasta que se agoten los digitos hexadecimales */
  if( isalpha( VALUE( identifier_end ) ) ){
    do{
      /* avanzar un caracter sobre la linea */
      *identifier_end++;
      /* el formato de identificador admite el guión bajo como caracter, pero no al inicio */
    }while( isalnum( VALUE( identifier_end ) ) || VALUE( identifier_end ) == '_' );
  }
  if( DELIMITER( VALUE( identifier_end ) ) ){
    /* ¡¡¡es un identificador!!! */
    /* crear identificador */
    token = token_create( IDENTIFICADOR, identifier_start, identifier_end );
    /* mover linea de entrada al fin del identificador */
    *line_ptr = identifier_end;
  }else{
    /* el identificador tiene caracteres incvalidos */
  }
  return token;
}
