/*
 * analiza los caracteres iniciales y decide si hay un numero hexadecimal,
 * devuelve apuntador a memoria dinámica (debe usar free() )
 */
Token * is_binary( string * line_ptr ){

  char * number_start = VALUE( line_ptr );
  char * number_end = VALUE( line_ptr );
  Token * token = NULL;
  /* recorrer la linea hasta que se agoten los digitos binarios */
  while(  VALUE( number_end ) == '0'|| VALUE ( number_end ) == '1' )
  {
    /* avanzar un caracter sobre la linea */
    *number_end++;
  }
  /* comparar con el delimitador de número binario (b) */
  if( tolower( VALUE( number_end ) ) == 'b' )/* hay un posible binario */
  {
    /* avanzar un caracter sobre la linea */
    *number_end++;
    if( DELIMITER( VALUE( number_end ) ) )
    {
      /* ¡¡¡es un binario!!! */
      /* crear numero */
      token = token_create( CONSTANTE, number_start, number_end );
      /* mover linea de entrada al fin de numero */
      *line_ptr = number_end;
    }else{
      /* error hay algo después de 'b' que no es delimitador */
    }
  }else{
    /* no es binario pues no termina con 'b' */
  }
  return token;
}
