
#define KEYWORD_PRINT_WIDTH 60

/*
 * print an element of keyword-table
 */
void keyword_print_row( Keyword * keyword )
{
  printf("|%-50s, t: %-5c, n: %-5d\n", keyword-> value, keyword-> type, keyword-> num_of_operands );
  return;
}

/*
 * print the entire keyword-table
 */
void keyword_print( KeywordTable table )
{
  char * keyword_title = "KEYWORD--TABLE";
  int index, title_start = KEYWORD_PRINT_WIDTH/2 - strlen(keyword_title)/2;

  /*HEADER*/
  printf("\n\n");

  for( index = 0; index < title_start; index++ ) printf( "-" );

  printf( "%s", keyword_title );

  for( index += strlen( keyword_title ); index < KEYWORD_PRINT_WIDTH; index++ ) printf( "-" );

  printf("\n");

  /*BODY*/
  tree_map( table, (FUNCTION) keyword_print_row );

  /*FOOTER*/
  for( index = 0; index < KEYWORD_PRINT_WIDTH; index++ ) printf( "-" );

  printf("\n\n");

  return;
}
