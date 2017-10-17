/*
 * bucket_tree.c
 */

/*
 * buckets with linked lists
 */
#include "bin_tree.c"

#ifndef BUCKET_TREE_HEADER
#define BUCKET_TREE_HEADER

/*
 * GLOBAL VARIABLES
 */
/*
 * when compiled the scope of  bucket_size limits to the object file 
 */
static unsigned int bucket_size;

/*
 * TYPE DEFINITIONS
 */
/*
 * a Bucket tree is essentially an array of pointers to trees
 * array syntax can be used on a bucket tree
 */
typedef BinaryTree * BucketTree;//an array trees


/*
 * FUNCTION STRUCTURE 
 */

/*
 * custom function that assigns an index to each data with
 * a criteria defined by the user
 */
typedef unsigned int (*INDEX_CRITERIA_FUNC) (void * data);

#endif
/*
 * FUNCTION BODY
 */

BucketTree bucket_tree_init( unsigned int size )
{
  bucket_size = size;
  int local_index;
  BucketTree bucket_tree;
  
  bucket_tree = malloc( sizeof( BucketTree ) * bucket_size );//an array of list pointers
  
  for( local_index = 0; local_index < bucket_size; local_index++ )
  {
    //make NULL so each list is initialized correctly by list_insert()
    bucket_tree[ local_index ] = NULL;
  }
  return bucket_tree;
}

int bucket__tree_insert( BucketTree bucket_tree, void * data, const INDEX_CRITERIA_FUNC index_function, const COMPARE_FUNC compare_function )
{
  unsigned int local_index = index_function( data );

  if( local_index < bucket_size )
  {
    // insert data on the subyacent linked list
    bucket_tree[ local_index ] = tree_insert( bucket_tree[ local_index ], data, compare_function );
    return 1;
  }
  else
  {
    //fprintf( stderr, " index out of bounds, size of buckets is %d\n", bucket_size );
    return 0;
  }
}


void * bucket_tree_find( BucketTree bucket_tree, void * data, const INDEX_CRITERIA_FUNC index_function, const COMPARE_FUNC compare_function )
{
  int local_index = index_function( data );
  void * data_ptr = NULL;

  if( local_index < bucket_size )
  {
    data_ptr = tree_find( bucket_tree[ local_index ], data, compare_function );
  }
  return data_ptr;
}

void bucket_tree_free( BucketTree bucket_tree, const FREE_FUNC free_function )
{
  int local_index;
  for( local_index = 0; local_index < bucket_size; local_index++)
  {
    if( NULL != bucket_tree[ local_index ] )
    {
      list_free( bucket_tree[ local_index ], free_function );
    }
  }
  free( bucket_tree );
  return;
}

void bucket_tree_map( BucketTree bucket_tree, const FUNCTION function )
{
  int local_index;
  for( local_index = 0; local_index < bucket_size; local_index++)
  {
    tree_map( bucket_tree[ local_index ], function );
  }
  return;
}