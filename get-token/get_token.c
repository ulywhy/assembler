//programa que va separando token en algun archivo

#include <stdio.h>/* fopen, fclose */
#include <stdlib.h>/* malloc, getline */
#include <ctype.h>/* ispunct, isdigit, isalpha, isxdigit, isblank */
#include <string.h>/* strncmp, index */

#include "lexico.c" /* preparando para hacer biblioteca */

#define COMENTARIO ';'
#define LITERAL    '"'
#define DIRECTIVA  '.'
#define TOTAL_PALABRAS_RESERVADAS 19

const string LISTA_PALABRAS_RESERVADAS[TOTAL_PALABRAS_RESERVADAS]={"INCLUDE", "BYTE", "DUP", "DWORD", "MOV", "EDX", "MAIN", "PROC", "ECX", "ESI", "EDI", "EAX", "EBX", "CALL", "NOP", "IF", "ELSE", "DATA", "END"};
  
int buscar_palabra_reservada( string palabra)
{
  int indice_local;
  for (indice_local=0; indice_local<TOTAL_PALABRAS_RESERVADAS; indice_local++)
  {
    if (strcasecmp(palabra, LISTA_PALABRAS_RESERVADAS[indice_local])==0)
    {
      return indice_local;
    }
  }
  return -1;
}



string preparar_linea( string linea ){
  char * apuntador_nueva_linea;
 /* eliminar '\n' si es que lo hay */
  /* buscar salto de linea */
  apuntador_nueva_linea = index( linea, '\n' );
  /* si contiene '\n' */
  if(apuntador_nueva_linea != NULL ){
    /* sobreescribir con caracter nulo */
    VALOR( apuntador_nueva_linea ) = '\0';
  }
  /* devolver lina */
  return linea;
}

string saltar_espacios( string linea ){
  /* mientras sea espacio o tab */
  while( isblank( VALOR( linea ) ) ){
    /* apunta al siguiente caracter */
    linea++;
  }
  /* devolver linea */    
  return linea;
}

void clear( void ){
  printf( "\033[2J\033[;H" );
  return;
}


/* 
 * PROGRAMA PRINCIPAL
 */
int main ( void ){
  const string formato_reporte_token = "    | %-20s | %s\n";

  FILE * archivo_fuente;

  string nombre_archivo_fuente;
  string apuntador_linea = NULL;
  string apuntador_linea_respaldo = NULL;
  size_t size_linea_entrada = 0;

  long long int numero_linea = 0;
  string token = NULL;
  /* falta pedir el nombre del archivo y comprobar que exista */
  clear();
  printf("\n   BIENVENIDO AL ANALIZADOR LEXICO\n\n   porfavor escribe el nombre del archivo ");
  scanf( " %ms", &nombre_archivo_fuente );
  archivo_fuente = fopen( nombre_archivo_fuente, "r" );
  if( archivo_fuente == NULL ){
    printf( "el archivo %s no existe", nombre_archivo_fuente );
    free( nombre_archivo_fuente );
    exit( EXIT_FAILURE );
  }

  /* mientras el archivo fuente tenga lineas aun por leer */
  while( !feof( archivo_fuente ) ){
    
    /* extraer una linea del archivo fuente */
    getline( &apuntador_linea, &size_linea_entrada, archivo_fuente );
    /* preparar linea */
    apuntador_linea_respaldo = preparar_linea ( apuntador_linea );
    /* contar linea */
    numero_linea++;
    /* mostrar la linea */

    getchar();
    clear();
    printf( "\n%4lld| %s\n\n", numero_linea, apuntador_linea );


    /* mientras haya caracteres an la linea de entrada */
    while( !FIN_DE_LINEA( VALOR( apuntador_linea ) ) ){
      /* avanzar todos los espacios */
      apuntador_linea = saltar_espacios( apuntador_linea );
      /*
       * BUSCAR SIGUIENTE TOKEN
       */
      /* si es simbolo: [][!"#$%&'()*+,./:;<=>?@\^_`{|}~-] */
      if( ispunct( VALOR( apuntador_linea ) ) ){
        /* analizar simbolo */
        token = analizar_simbolo( &apuntador_linea );
        if( token != NULL ){
          switch( token[0] ){
            
            case LITERAL:
              token = analizar_literal( &apuntador_linea );
              if( token != NULL ){
                printf( formato_reporte_token, "literal", token );
                free( token );
              }
              break;

            case COMENTARIO:
              printf( formato_reporte_token, "comentario", apuntador_linea );
              /* apuntar al final de la linea */
              apuntador_linea = index( apuntador_linea, '\0' );
              break;

            case DIRECTIVA:
              token = analizar_identificador( &apuntador_linea );
              if( token != NULL ){
                if(0<= buscar_palabra_reservada(token))
                {
                  printf( formato_reporte_token, "directiva", token );
                  free( token );
                }
              }
              break;
            case '+': 
              printf( formato_reporte_token, "suma", token);
              break;
            case '*': 
              printf( formato_reporte_token, "producto", token);
              break;
            case '/': 
              printf( formato_reporte_token, "division", token);
              break;
            case '(': 
              printf( formato_reporte_token, "parentesis izquierdo", token);
              break;
            case ')': 
              printf( formato_reporte_token, "parentesis derecho", token);
              break;
            case '[': 
              printf( formato_reporte_token, "corchete izquierdo", token);
              break;
            case ']': 
              printf( formato_reporte_token, "corchete derecho", token);
              break;
            case ',': 
              printf( formato_reporte_token, "separador", token);
              break;

            default:
              printf( formato_reporte_token, "simbolo", token );
              break;
          }
        }
      }else
      /* si es letra */
      if( isalpha( VALOR( apuntador_linea ) ) ){
        /* si es hexadeimal */
        token = analizar_hexadecimal( &apuntador_linea );
        if( token != NULL ){ /* es hexadecimal */
          printf( formato_reporte_token, "hexadecimal", token );
          free( token );
        }else{
          /* si es palabra reservada */
          token = analizar_identificador( &apuntador_linea );
          /* buscar en tabla de palabras reservadas */
          if( token != NULL ){
            if(buscar_palabra_reservada(token )>=0)
            {
              printf( formato_reporte_token, "palabra reservada:", token );
            }else{
              printf( formato_reporte_token, "identificador", token );
            }
            free( token );
          }else{
            /* error de identificador */
            /* mover al siguiente token */
            apuntador_linea++;
          }
        }
        /* si es identificador */
      }else
      /* si es número */
      if( isdigit( VALOR( apuntador_linea ) ) ){
        /* si es decimal */
        token = analizar_decimal( &apuntador_linea);
        if( token != NULL){
          printf( formato_reporte_token, "decimal", token);
          free( token );
        }
        /* si es binario */
        token = analizar_binario( &apuntador_linea);
        if( token != NULL ){
          printf( formato_reporte_token, "binario", token);
          free ( token );
        }
        /* si es octal */
        token = analizar_octal( &apuntador_linea);
        if( token != NULL){
          printf( formato_reporte_token, "octal", token);
          free ( token );
        }
        /* si es hexadecimal */
        token = analizar_hexadecimal( &apuntador_linea );
        if( token != NULL ){ /* es hexadecimal */
          printf( formato_reporte_token, "hexadecimal", token );
          free( token );
        }
      }else{

      }
    }
    /* liberar memoria de la linea usando el respaldo */
    free( apuntador_linea_respaldo );
    /* hacer NULL para evitar acceder a memoria no reservada */
    apuntador_linea_respaldo = NULL;
    size_linea_entrada = 0;
  }
  free( nombre_archivo_fuente );
  fclose( archivo_fuente );
 return 0;
}
