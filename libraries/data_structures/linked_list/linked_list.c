/* name: linked_list.h
 * provide a general propouse singly linked list
 */
#include <stdlib.h>

#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER
/*
 * STRUCTURES
 */

/*
 * definition of the core structure
 * defines the basic information of a node
 */
typedef struct elem{
	//pointer to the next node
	struct elem * next;
	//pointer to the data content
	void * data;
} Element;

/*
 * redefinition of an element (node) to be the head of the list
 * user souldnt lose track of it at any time
 */
typedef Element * List;

/*
 * FUNCTION STRUCTURE 
 */
/* custom compare function
 * returns 0 if values are equal and non 0 if values are different
 */
typedef  int (*COMPARE_FUNC) ( void *, void * );
/* 
 * custom function to call on user 'data' pointer to free the structure
*/
typedef void (*FREE_FUNC)    ( void * );

static Element * element_create( void * data )
{
  Element *element = malloc( sizeof( Element ) );
  element-> next = NULL;
  element-> data = data;
  return element;
}

#endif

/*
 * FUNCTION BODY
 */

/*
 * list_insert 
 * inserts an element 'data' as the last element of the linked list 'list'
 * RETURN VALUE a pointer to the head of the list where element was inserted
 */
Element * list_insert( Element * list, void * data )
{
	Element * element = element_create( data ),
          * temp;
	if( NULL == list )
  {//if list empty
		list = element;
	}
  else
  {
		temp = list;
    while( NULL != (temp-> next) )
    {
      temp = temp-> next;
    }
		temp-> next = element;
	}
 	return list;
}

/*
 * list_find
 * compare the structure 'data' with the 'data' on each element in the 'list'
 * using the 'compare_function'
 * RETURN VALUE if 'comapre_function' returns a matching result 
 * then returns a pointer to the matching data
 * else NULL is returned
 */
void * list_find( Element * list, void * data, const COMPARE_FUNC compare_function )
{
	Element * element = list;

  while( element != NULL && compare_function( data, element-> data ) )
  {
    element = element-> next;
  }
  if( element == NULL )
  {
    return NULL;
  }
  else
  {
    return element-> data;
  }
}

/*
 * list_free
 * frees all the elements on the 'list'
 * data is assumed to be dinamically allocated hence it is freed using custom free function
 */
void list_free ( Element * list, const FREE_FUNC free_function )
{
	Element * element = list, 
          * temp;
	
  while( element != NULL )
	{
    temp = element-> next;
		free_function( element-> data );
		free( element );
    element = temp;
    
	}
	return;
}