
/*
 * search keyword in table, returns the keyword if it is found or NULL otherwise
 */
Keyword_t * keyword_find ( KeywordTable table, char * keyword )
{
  return tree_find( table, keyword, (COMPARE_FUNC) keyword_cmp );
}
