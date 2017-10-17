
BinaryTree * tree_insert( BinaryTree * root, void * data, COMPARE_FUNC compare_fun )
{
  /* insert as unbalanced tree */
  int result;
  BinaryTree * node_ptr = root;

  if( NULL == root )
  {
    root = tree_new( data ); 
  }
  else
  {
    /* traverse tree */
    while(1)
    {
      result = compare_fun( data, node_ptr-> data );
      /* less or equal */
      if( 0 >= result )
      {
        if( NULL != node_ptr-> left )
        {
          /* go left */
          node_ptr = node_ptr-> left;
        }
        else{
          /* create node */
          node_ptr->left = tree_new( data );
          break;
        }
      } 
      else if( 0 < result )
      {
        if( NULL != node_ptr-> right )
        {
          /* go right */
          node_ptr = node_ptr-> right;
        }
        else
        {
          /* create node */
          node_ptr-> right = tree_new( data );
          break;
        }
      }
    }//while node_ptr not nul
    return root;
  }
}
