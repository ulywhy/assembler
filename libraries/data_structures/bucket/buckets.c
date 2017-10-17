/*
 * buckets with linked lists
 */
#include <linked_list.h>

#ifndef BUCKET_LIST_HEADER
#define BUCKET_LIST_HEADER

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
 * a Bucket list is essentially an array of pointers to lists
 * array syntax can be used on a bucket list
 */
typedef List * BucketList;//an array of lists


/*
 * FUNCTION STRUCTURE 
 */

/*
 * custom function that assigns an index to each data with
 * a criteria defined by the user
 */
typedef unsigned int (*INDEX_CRITERIA_FUNC)(void * data);

#endif
/*
 * FUNCTION BODY
 */

BucketList bucket_init( unsigned int size )
{
  bucket_size = size;
  int local_index;
  BucketList bucket_list;
  
  bucket_list = malloc( sizeof( List ) * bucket_size );//an array of list pointers
  
  for( local_index = 0; local_index < bucket_size; local_index++ )
  {
    //make NULL so each list is initialized correctly by list_insert()
    bucket_list[ local_index ] = NULL;
  }
  return bucket_list;
}

int bucket_insert( BucketList bucket_list, void * data, const INDEX_CRITERIA_FUNC index_function )
{
  unsigned int local_index = index_function( data );

  if( local_index < bucket_size )
  {
    // insert data on the subyacent linked list
    bucket_list[ local_index ] = list_insert( bucket_list[ local_index ], data );
    return 1;
  }
  else
  {
    //fprintf( stderr, " index out of bounds, size of buckets is %d\n", bucket_size );
    return 0;
  }
}


void * bucket_find( BucketList bucket_list, void * data, const INDEX_CRITERIA_FUNC index_function, const COMPARE_FUNC comapre_function )
{
  int local_index = index_function( data );
  void * data_ptr = NULL;
  if( local_index < bucket_size )
  {
    data_ptr = list_find( bucket_list[ local_index ], data, comapre_function );
  }
  return data_ptr;
}

void bucket_free( BucketList bucket_list, const FREE_FUNC free_function )
{
  int local_index;
  for( local_index = 0; local_index < bucket_size; local_index++)
  {
    if( NULL != bucket_list[ local_index ] )
    {
      list_free( bucket_list[ local_index ], free_function );
    }
  }
  free( bucket_list );
  return;
}
