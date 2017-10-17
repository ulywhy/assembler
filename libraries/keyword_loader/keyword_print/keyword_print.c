
#define KEYWORD_PRINT_WIDTH 60

/*
 * print an element of keyword-table
 */
void keyword_print_row( Keyword_t * keyword )
{
  printf("|%-45s, t: %-5d, n: %-5d\n", keyword-> value, keyword-> type, keyword-> num_of_operands );
  return;
}

/*
 * print the entire keyword-table
 */
void keyword_print( KeywordTable table )
{
  char * keyword_title = "KEYWORD--TABLE";
  int index, title_start = KEYWORD_PRINT_WIDTH/2 - strlen(keyword_title)/2;
  char annotations [ KEYWORD_PRINT_WIDTH ];
  /*HEADER*/
  printf("\n\n");

  for( index = 0; index < title_start; index++ ) printf( "-" );

  printf( "%s", keyword_title );

  for( index += strlen( keyword_title ); index < KEYWORD_PRINT_WIDTH; index++ ) printf( "-" );

  printf("\n");
  /*ANNOTATIONS*/
  sprintf( annotations, "  tipo: %d=operador %d=directiva %d=registro \n", OPERATOR, DIRECTIVE, REGISTER );

  printf( "%s", annotations );

  /*BODY*/
  tree_map( table, (FUNCTION) keyword_print_row );

  /*FOOTER*/
  for( index = 0; index < KEYWORD_PRINT_WIDTH; index++ ) printf( "-" );

  printf("\n\n");

  return;
}
