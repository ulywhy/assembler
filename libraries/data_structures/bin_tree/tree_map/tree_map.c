
void tree_map( BinaryTree * root, FUNCTION function )
{
  if( NULL != root ){
    tree_map( root-> left, function );
    function( root-> data );
    tree_map( root-> right, function );
  }
  return;
}