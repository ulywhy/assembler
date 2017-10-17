void keyword_free( Keyword * keyword )
{
  free( keyword-> value );
  free( keyword );
  return;
}
/*
 * free allocated memory for the tree
 */
void Keyword_table_free ( KeywordTable table )
{
  tree_free( table, (FREE_FUNC) keyword_free );
  return;
}
