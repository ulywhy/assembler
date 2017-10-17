/*
 * load keyword table into a binary ordered tree
 */
KeywordTable keyword_load ( char * filename )
{
  FILE * file;
  char type;
  int num_of_operands;
  Keyword_t * keyword;

  BinaryTree * tree = NULL;
  /* if file was not found then exit */
  if( !file_open( filename, "r", &file ) ) return NULL;

  while( !feof( file ) )
  {
    keyword = malloc( sizeof( Keyword_t ) );
    keyword-> value = NULL;

    if( EOF == fscanf( file, " %ms",  &(keyword-> value) ) ){
      free( keyword-> value);
      free( keyword );
      break;
    }

    fscanf( file, " %c %d", &type, &num_of_operands );

    printf("k: %s, t: %c, n: %d\n", keyword-> value, type, num_of_operands );
    if( !tree_find( tree, keyword-> value, (COMPARE_FUNC) keyword_cmp ) )
    {

      switch( num_of_operands )
      {
        case 0:
          keyword-> num_of_operands = NONE;
        break;

        case 1:
          keyword-> num_of_operands = IMEDIATE;
        break;

        case 2:
          keyword-> num_of_operands = DEST_AND_SOURCE;
        break;
      }

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
      tree = tree_insert( tree, keyword, (COMPARE_FUNC) key_2_key_cmp );
    }
  }
  fclose( file );
  return tree;
}
