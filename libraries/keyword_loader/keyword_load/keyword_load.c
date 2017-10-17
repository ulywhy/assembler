/*
 * load keyword table into a binary ordered tree
 */
KeywordTable keyword_load ( char * filename )
{
  FILE * file;
  char type;
  Keyword * keyword;

  BinaryTree * tree = NULL;

  if( !file_open( filename, "r", &file ) ) return NULL;

  while( !feof( file ) )
  {
    keyword = malloc( sizeof(keyword ) );

    fscanf( file, " %ms %c %ud", &(keyword-> value), &type, &(keyword-> num_of_operands) );
    printf("k: %s, t: %c, n: %d\n", keyword-> value, type, keyword-> num_of_operands );
    if( !tree_find( tree, keyword, (COMPARE_FUNC) keyword_cmp ) )
    {
      switch( tolower( type ) )
      {
        case 'r':
          keyword-> type = REGISTER;
        break;

        case 'd':
          keyword-> type = DIRECTIVE;
        break;

        case 'o':
          keyword-> type = OPERATOR;
        break;
      }
      tree = tree_insert( tree, keyword, (COMPARE_FUNC) keyword_cmp );
    }
  }
  fclose( file );
  return tree;
}
