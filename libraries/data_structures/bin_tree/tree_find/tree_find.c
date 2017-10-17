void * tree_find ( BinaryTree * root, void * data, COMPARE_FUNC compare_fun )
{
  int result;
  BinaryTree * node_ptr = root;
  void * found = NULL;
  /* traverse tree */
  while( NULL != node_ptr )
  {
    result = compare_fun( data, node_ptr-> data );
    if( 0 > result )
    {
      /* go left */
      node_ptr = node_ptr-> left;
    } 
    else if( 0 < result )
    {
      /* go right */
      node_ptr = node_ptr-> right;
    }
    else if( 0 == result )
    {
      /* found */
      found = node_ptr-> data;
      break;
    }
  }//while node_ptr not null
  return found;
}
