/*
 * analiza los caracteres iniciales y devuelve el contenido de la cadena de caracteres,
 * devuelve apuntador a memoria dinámica (debe usar free() )
 */
Token * is_literal( string * line_ptr ){
  char * inicio_literal = VALUE( line_ptr );
  char * fin_literal = VALUE( line_ptr );
  Token * token = NULL;

  while( VALUE( fin_literal ) != '"' && !END_LINE( VALUE( fin_literal ) ) ){
    fin_literal++;
  }
  if( VALUE( fin_literal ) == '"'){
    /* es una literal valida */
    /* avanza otro caracter, copia las comillas de ciere pero
     * se escribe fin de cadena en su lugar */
    fin_literal++;
    /* crear numero */
    token = token_create( LITERAL, inicio_literal-1, fin_literal );
    *line_ptr = fin_literal;
    
  }else{
    /* error, literal invalida, no se encontro '\"' de cierre */
  }
  return token;
}

