/*
 * analiza los caracteres iniciales y decide si es simbolo de agrupación,
 * operador simple o de doble caracter
 * devuelve apuntador a memoria estática (no se usa free() )
 */

Token * is_symbol( string * line_ptr ){

  int local_index;
  bool es_doble = FALSE;
  string line = VALUE( line_ptr );
  char double_symbol[ LONGITUD_MAX_SIMBOLOS + 1 ];
  
  Token * token;

  /* copia los dos primeros caracteres de la line al arreglo double_symbol */
  strncpy( double_symbol, line, LONGITUD_MAX_SIMBOLOS + 1 );
  /* si el segundo caracter tambien es simbolo podemos tener un simbolo doble */
  if( ispunct( double_symbol[ 1 ] ) ){
    /* comparar para cada posible simbolo doble */
    for( local_index = 0; local_index < CANTIDAD_SIMBOLOS_DOBLES; local_index++ ){
      /* si la comparación es positiva, terminar de buscar
       * el simbolo doble ha sido encontrado */
      if( COINCIDENCIA_COMPARACION == strncmp( double_symbol, 
                                               SIMBOLOS_DOBLES[ local_index ], 
                                               LONGITUD_MAX_SIMBOLOS ) ){
        es_doble = TRUE;
        /* copiar */
        token = malloc( sizeof( Token ) );
        token-> type = SIMBOLO;
        token-> value = strdup( SIMBOLOS_DOBLES[ local_index ] );
        token-> lenght = strlen( token-> value );
        /* avanzar apuntador segun el lenght del operador doble */
        *line_ptr += LONGITUD_MAX_SIMBOLOS;
        break;
      }
    }
  }
  if(!es_doble)
  {
    /* buscar simbolo simple */
    for( local_index = 0; local_index < CANTIDAD_SIMBOLOS_SIMPLES; local_index++ ){
      /* si la comparación es positiva, terminar de buscar
       * el simbolo ha sido encontrado */
      if( COINCIDENCIA_COMPARACION == strncmp( line, 
                                               SIMBOLOS_SIMPLES[ local_index ], 
                                               1 ) ){
        /* devolver apuntador al simbolo en la tabla */
        token = malloc( sizeof( Token ) );
        token-> type = SIMBOLO;
        token-> value = strdup( SIMBOLOS_SIMPLES[ local_index ] );
        token-> lenght = 1;
        /* avanzar apuntador */
        (*line_ptr)++;
        break;
      }
    }
  }
  return token;
}
