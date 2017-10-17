
void tree_free( BinaryTree * root, FREE_FUNC free_func )
{
  if( NULL != root )
  {
    free_func( root-> data );

    tree_free( root-> left, free_func );
    tree_free( root-> right, free_func );
   
    free( root );
  }
  return;
}
