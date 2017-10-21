//programa que va separando token en algun archivo
#ifndef GET_TOKEN_HEADER
#define GET_TOKEN_HEADER

#include <stdio.h>/* fopen, fclose */
#include <stdlib.h>/* malloc, getline */
#include <ctype.h>/* ispunct, isdigit, isalpha, isxdigit, isblank */
#include <string.h>/* strncmp, index */

#include "../data_type.h" /* Token */
#include "lexical_analysis/lexical_analysis.h" /* preparando para hacer biblioteca */
#include "util/skip_spaces.c"

#define COMENTARIO ';'

typedef struct parser_struct{
  /* source file */
  FILE * source_file;
  /* line conter */
  long long int line_number;
}Parser;

/* FUNCTION HEAD */
string set_line( string line );

Token * parser_next ( KeywordTable );

void parser_free();

bool parser_init( string source_file_name );

/* create parser structure variable */
static Parser parser; /* static makes it visible only
                       * to functions in this file (meaning program)*/

#include "parser_next/parser_next.c"
#include "parser_free/parser_free.c"
#include "parser_init/parser_init.c"
#include "set_line/set_line.c"

#endif
