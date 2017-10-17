#include <stdio.h>
#include <string.h>
#include <ctype.h> //keyword_load (tolower, iscntrl)

#include "../data_type.h"
#include "../file_open.c"
#include "../data_structures/bin_tree/bin_tree.h"

#ifndef KEYWORD_LOAD_HEADER
#define KEYWORD_LOAD_HEADER

//a keyword table is a pointer to the root of an ordered binary tree
typedef BinaryTree * KeywordTable;

typedef enum keyword_type_enum {
  REGISTER,
  OPERATOR,
  DIRECTIVE,
} KeywordType;

typedef enum num_of_operands_enum {
  NONE,
  IMEDIATE,
  DEST_AND_SOURCE,
}NumOfOperands;

typedef struct keyword_struct {
  string value;
  NumOfOperands num_of_operands;
  KeywordType type;
}Keyword_t;

/*
 * load keyword table into a binary ordered tree
 */
KeywordTable keyword_load ( char * filename );

/*
 * search keyword in table, returns 1 or 0 if keyword is in the table or not
 */
Keyword_t * keyword_find ( KeywordTable table, char * keyword );

/*
 * free allocated memory for the keyword-table
 */
void keyword_table_free ( KeywordTable table );

/*
 * free allocated memory for the keyword
 */
void keyword_free ( Keyword_t * table );

/*
 * print an element of keyword-table
 */
void keyword_print_row( Keyword_t * keyword );

/*
 * print the entire keyword-table
 */
void keyword_print( KeywordTable table );
/*
 *  compare a string and a keyword struct
 */
int keyword_cmp( char * s1, Keyword_t * k1 );

/*
 *  compare between keyword structs
 */
int key_2_key_cmp( Keyword_t * k1, Keyword_t * k2 );

#include "keyword_cmp/keyword_cmp.c"
#include "keyword_print/keyword_print.c"
#include "keyword_find/keyword_find.c"
#include "keyword_free/keyword_free.c"
#include "keyword_load/keyword_load.c"

#endif
