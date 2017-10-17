static BinaryTree * tree_new( void * data )
{
  BinaryTree * node_ptr = malloc( sizeof( BinaryTree ) );
  node_ptr-> data  = data;
  node_ptr-> left  = NULL;
  node_ptr-> right = NULL;

  return node_ptr;
}