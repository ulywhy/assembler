Token * token_create( TokenType type, string token_start, string token_end )
{
  Token * token;
  int lenght = ( token_end - token_start ) + 1;;

  token = malloc( sizeof( Token ) );
  token-> type     = type;
  token-> lenght = lenght;
  /* asignar memoria suficiente para el token y el caracter de fin de cadena */
  token-> value = malloc( sizeof( char ) * lenght );
  /* clonar el número */
  strncpy( token-> value, token_start, lenght );
  /* agregar fin de cadena */
  token-> value[ lenght - 1 ] = '\0';  
/* devolver token */
  return token;  
}
