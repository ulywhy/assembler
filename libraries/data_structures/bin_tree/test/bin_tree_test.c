/*
 * bin_tree_test.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "bin_tree.c"
/*
 * test 
 */
//test structure
typedef struct element_struct
{
  int value;
}Element;

//compare function
int element_cmp ( Element * e1, Element * e2 )
{
  int v1 = e1-> value;
  int v2 = e2-> value;
  return v2 - v1;
}

void element_print( Element * e )
{    
  printf( "value is %d\n", e-> value );
  return;
}

int main( void )
{
  /* important to make null */
  BinaryTree * tree = NULL;
  Element * array [20];
  int index;

  for(index = 0; index < 20; index++)
  {
    array [ index ] = malloc( sizeof( BinaryTree ) );
    array [ index ]-> value = (int) rand()%100;
    printf("%d\n",array[index]-> value);
  } 

  for(index = 0; index < 20; index++)
  {
    tree = tree_insert( tree, array[index], (COMPARE_FUNC) element_cmp );
  }
  
  tree_map( tree, (FUNCTION) element_print );
  
  Element * found = tree_find( tree, array[2], (COMPARE_FUNC) element_cmp );
  if( NULL != found ){
    puts("found");
    element_print( found );
  }

  tree_free( tree, free );
  exit(EXIT_SUCCESS);
}
