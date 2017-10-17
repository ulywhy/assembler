//programa que va separando token en algun archivo
#ifndef GET_TOKEN_HEADER
#define GET_TOKEN_HEADER

#include <stdio.h>/* fopen, fclose */
#include <stdlib.h>/* malloc, getline */
#include <ctype.h>/* ispunct, isdigit, isalpha, isxdigit, isblank */
#include <string.h>/* strncmp, index */

#include"../../data_type.h" /* Token */
#include "../lexical_analysis/lexical_analysis.h" /* preparando para hacer biblioteca */

#define COMENTARIO ';'
#define LITERAL    '"'
#define DIRECTIVA  '.'

/*
 * VARIABLES GLOBALES
 */
FILE * source_file;

string line_ptr = NULL;
string line_ptr_backup = NULL;

long long int line_number = 0;

void clear( void ){
  printf( "\033[2J\033[;H" );
  return;
}

string saltar_espacios( string line ){
  /* mientras sea espacio o tab */
  while( isblank( VALUE( line ) ) ){
    /* apunta al siguiente caracter */
    line++;
  }
  /* devolver line */
  return line;
}

string set_line( string line );

Token * get_token ();

void parser_free();

bool parser_init( string source_file_name );

#include "get_token/get_token.c"
#include "parser_free/parser_free.c"
#include "parser_init/parser_init.c"
#include "set_line/set_line.c"

#endif
