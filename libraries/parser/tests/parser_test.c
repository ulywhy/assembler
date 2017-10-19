/*
 * parser_test.c
 */
#include<stdio.h>
#include"get_token.c"

 int main(){
  Token * token;

  parser_init("archivo_muestra.txt");

  do{
    token = NULL;
    token = get_token();
    if( token != NULL ){
      switch( token-> tipo){
        case IDENTIFICADOR:
          printf("identificador");
        break;
        case CONSTANTE:
          printf("numero");
        break;
        case LITERAL:
          printf("literal");
        break;
        case SIMBOLO:
          printf("simbolo");
        break;
        case DIRECTIVA:
          printf("directiva");
        break;
        case COMENTARIO:
          printf("comentario");
        break;
        default:
          printf("desconocido");
        break;
      }
      printf("  %20s\n", token-> valor);
      free(token-> valor);
      free(token);
    }
  }while( token != NULL);
  return 0;
 }