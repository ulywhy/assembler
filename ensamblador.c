/*
 * ensamblador.1.2.1.c
 * implementa el analisis sintáctico de cualquier
 * archivo escrito en lenguaje ensamblador
 * tabla de simbolos: areglo de listas
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to open source file */
#include "libraries/file_open.c"
/* binary tree to use as simbol table */
#include "libraries/data_structures/bin_tree/bin_tree.h"
/* function to load keyword table */
#include "libraries/keyword_loader/keyword_loader.h"
/* function to get tokens */
#include "libraries/parser/token/token.h"

#define BUCKET_SIZE 27

typedef struct identificador_struct
{
  char * nombre;
  //type
  //value
  //uso
  //direccion
}Identificador;

int identificador_cmp ( char * s1, Identificador * s2 )
{
  return strcasecmp( s1, s2-> nombre );
}

int identificador_struct_cmp ( Identificador * i1, Identificador * i2 )
{
  return strcasecmp( i1-> nombre, i2-> nombre );
}

void identificador_print ( Identificador * idt_ptr )
{
  printf("  |%20s|%20s|%20s|%20s|%20s|\n", idt_ptr-> nombre, "nill", "nill", "nill", "nill");
  return;
}

void identificador_free ( Identificador * idt_ptr )
{
  free( idt_ptr-> nombre );
  free( idt_ptr );
  return;
}

int main ( void ){
  //Token
  Token * token = NULL;
  //source-file
  FILE * archivo_entrada = NULL;
  char * nombre_entrada = NULL;
  //keyword table
  KeywordTable tabla_de_palabras_res = NULL;
  Keyword_t * keyword = NULL;
  //symbol table
  BinaryTree * tabla_de_simbolos = NULL;

  Identificador * identificador_ptr = NULL;

  char * tipo_token = NULL;
  long long int location_counter = 0;

  /* iniciar parser */
  printf("escribe el nombre del archivo ");
  scanf( " %ms", &nombre_entrada );

  if( !parser_init( nombre_entrada ) ){
    free( nombre_entrada );
    exit( EXIT_FAILURE );
  }

  tabla_de_palabras_res = keyword_load( "palabras_reservadas.txt" );
  /* mostrar tabla de palabras reservadas */
  keyword_print( tabla_de_palabras_res );

  do
  {
    token = NULL;
    token = parser_next( tabla_de_palabras_res );

    if( token != NULL )
    {
      switch( token-> type)
      {
        case IDENTIFICADOR:
          //es palabra reservada?
          keyword = keyword_find( tabla_de_palabras_res, token-> value );
          if( NULL != keyword )
          {
            tipo_token = "palabra reservada";
          }else{
            //es indentificador
            tipo_token = "identificador";
            //buscar si ya esta en la tabla
            if( NULL == tree_find( tabla_de_simbolos,
                                   token->value,
                                   (COMPARE_FUNC) identificador_cmp ) )
            {
              //crear nuevo identificador
              identificador_ptr = malloc( sizeof( Identificador ) );
              identificador_ptr-> nombre = strdup( token-> value );
              tabla_de_simbolos = tree_insert( tabla_de_simbolos,
                           identificador_ptr,
                           (COMPARE_FUNC) identificador_struct_cmp );
            }
          }
        break;
        case CONSTANTE:
          tipo_token = "numero";
        break;
        case LITERAL:
          tipo_token = "literal";
        break;
        case SIMBOLO:
          tipo_token = "simbolo";
        break;
        case DIRECTIVA:
          tipo_token = "directiva";
        break;
        case COMENTARIO:
          tipo_token = "comentario";
        break;
        default:
          tipo_token = "desconocido";
        break;
      }
      printf(" %-25s  %s\n", tipo_token, token-> value);
      free(token-> value);
      free(token);
    }
  }while( token != NULL);

  puts("_______tabla de simbolos________\n");
  printf("  |%-20s|%-20s|%-20s|%-20s|%-20s|\n", "nombre", "type", "value", "uso", "direccion");
  tree_map( tabla_de_simbolos, (FUNCTION) identificador_print );
  puts("________________________________\n");
  /* liberar tabla de simbolos */
  tree_free( tabla_de_simbolos , (FREE_FUNC) identificador_free );

  free( nombre_entrada );
  /* liberar archivo fuente */
  parser_free();
  /* liberar tabla de palabras reservadas */
  keyword_table_free( tabla_de_palabras_res );
  return 0;
}
