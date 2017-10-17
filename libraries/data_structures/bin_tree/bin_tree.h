/*
 * bin_tree.h
 */
 /*
 * balanced trees have search time O(n)
 *                 -> stay ordered trough inserts
 *                 -> n : levels of branches
 *                 -> root node has level 0
 */

/* numbers in [0, 100]
 *                   root:   50 
 *                          /  \
 *                         /    \
 *                       25      60
 *                      /  \    /  \
 *                    15   45  55   80
 *                   /                \
 *               ___3___________________90___
 *these are ilegal-> \                /
 *branches in a       7             85
 *balanced tree
*/

#include <stdlib.h>

#ifndef BINARY_TREE_HEADER
#define BINARY_TREE_HEADER
/*
 * STRUCTURES
 */

/*
 * binary_tree_struct defines a node of a binary tree.
 * having only two branches left and right and a data pointer
 */
typedef struct binary_tree_struct 
{
  /* pointer to data of node */
  void * data;
  /* left branch */
  struct binary_tree_struct * left;
  /* right branch */
  struct binary_tree_struct * right;
}BinaryTree;
/*
 * FUNCTION STRUCTURE 
 */
/* custom compare function 
    It returns an integer less than, equal to, or greater than zero if  s1  is  found,
    respectively, to be less than, to match, or be greater than s2.
 */
typedef  int (*COMPARE_FUNC) ( void * s1, void * s2 );
/* 
 * custom function to call on user 'data' pointer to free the structure
*/

typedef void (*FREE_FUNC)    ( void * );

typedef void (*FUNCTION)     ( void * );
/*
 * finds the data in the given tree, retuns a pointer to data if it's found
 * and null if data doesnt exist in the tree
 */
void * tree_find ( BinaryTree * root, void * data, COMPARE_FUNC compare_fun );

/*
 * inserts the data in the right place of the ordered tree
 * if root has a NULL value then the tree is initialised and data is stored in root
 * returns a pointer to root 
 */
BinaryTree * tree_insert( BinaryTree * root, void * data, COMPARE_FUNC compare_fun );

void tree_free( BinaryTree * root, FREE_FUNC free_func );

void tree_map( BinaryTree * root, FUNCTION function );

/*
 * binary_tree function
 */

#include "tree_new/tree_new.c"
#include "tree_find/tree_find.c"
#include "tree_insert/tree_insert.c"
#include "tree_free/tree_free.c"
#include "tree_map/tree_map.c"

#endif