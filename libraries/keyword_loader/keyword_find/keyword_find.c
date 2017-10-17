
/*
 * search keyword in table, returns 1 or 0 if keyword is in the table or not
 */
int keyword_find ( KeywordTable table, char * keyword )
{
  return (NULL == tree_find( table, keyword, (COMPARE_FUNC) strcasecmp ) );
}
