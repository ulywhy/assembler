/*
 * analiza los caracteres iniciales y decide si hay un numero decimal,
 * devuelve apuntador a memoria dinámica (debe usar free() )
 */
#define SIGNO_MENOS '-'
#define SIGNO_MAS   '+'

Token * is_decimal( string * line_ptr ){

  char * number_start = VALUE( line_ptr );
  char * number_end = VALUE( line_ptr );
  Token * token = NULL;
  /* se admite un signo */ 
  if( VALUE( number_end ) == SIGNO_MENOS || VALUE( number_end ) == SIGNO_MAS )
  {
    number_end++;
  }
  /* recorrer la linea hasta que se agoten los digitos */
  while(  isdigit( VALUE( number_end ) ) )
  {
    /* avanzar un caracter sobre la linea */
    number_end++;
  }
    if( DELIMITER( VALUE( number_end ) ) )
    {
      /* ¡¡¡es un decimal!!! */
      /* crear número */
      token = token_create( CONSTANTE, number_start, number_end );
      /* recorrer linea de entrada al fin del numero */
      *line_ptr = number_end;
  }else{
    /* no coincide con el formato de número decimal */
  }
  return token;
}
