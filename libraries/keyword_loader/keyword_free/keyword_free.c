void keyword_free( Keyword_t * keyword )
{
  free( keyword-> value );
  free( keyword );
  return;
}
/*
 * free allocated memory for the tree
 */
void keyword_table_free ( KeywordTable table )
{
  tree_free( table, (FREE_FUNC) keyword_free );
  return;
}
