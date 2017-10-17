/*
 * analiza los caracteres iniciales y decide si hay un numero hexadecimal,
 * devuelve apuntador a memoria dinámica (debe usar free() )
 */
Token * is_hexadecimal( string * line_ptr ){

  char * number_start = VALUE( line_ptr );
  char * number_end = VALUE( line_ptr );
  Token * token = NULL;

  /* recorrer la linea hasta que se agoten los digitos hexadecimales */
  while( isxdigit( VALUE( number_end ) ) )
  {
    /* avanzar un caracter sobre la linea */
    *number_end++;
  }
  /* comparar con el delimitador de número hexadecimal (h) */
  if( tolower( VALUE( number_end ) ) == 'h' )/* hay un posible hexadecimal */
  {
    /* avanzar un caracter sobre la linea */
    *number_end++;
    if( DELIMITER( VALUE( number_end ) ) )
    {
      /* ¡¡¡es un hexadecimal!!! */
      /* crear numero */
      token = token_create( CONSTANTE, number_start, number_end );
      /* mover linea de entrada al fin de numero */
      *line_ptr = number_end;
    }else{
      /* error de formato hay algo despues de 'h' que no es delimitador */
    }
  }else{
    /*no es hexadecimal no termina con 'h' */
  }
  return token;
}
