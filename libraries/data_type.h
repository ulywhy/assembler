#ifndef DATOS_HEADER
#define DATOS_HEADER

typedef char* string;

void clear( void ){
  printf( "\033[2J\033[;H" );
  return;
}

/*
 * ENUM
 */

 //BOOLEAN
 typedef enum boolean_enum {
   FALSE = 0,
   TRUE = 1
 }bool;

typedef enum token_type_enum {
  OPERADOR = 0, //palabras reservadas del lenguaje ensamblador
  DIRECTIVA,  //indicadores de control para el ensamblador
  REGISTRO,
  IDENTIFICADOR, //valores declarados por el usuario
  CONSTANTE, //numeros (decimal, binario, octal, hexadecimal)
  LITERAL, //cadenas delimitadas entre comillas dobles
  SIMBOLO,
}TokenType;

typedef enum identifier_type_enum {
  INDEFINIDO = 0,
  MULTIDEFINIDO,
  DEFINIDO,
} IdentifierType;

/*
 * ESTRUCTURAS
 */

typedef struct token_struct {
  string value;
  TokenType type;
  int lenght;
}Token;

typedef struct error_struct {
  string message;
  char * tokenptr;
}Error;

/*
 *MENSAJES DE ERROR
 */
#define IDENTIFICADOR_INVALIDO  "error de sintaxis, identificador invalido"
#define IDENTIFICADOR_VACIO     "advertencia, identificador vacio"
#define DIRECTIVA_INVALIDA      "error de sintaxis, directiva invalida"
#define ERROR_FORMATO_NUMERO    "error de sintaxis, formato de numero desconocido"
#define ERROR_USO_DE_SEPARADOR  "error de sintaxis, esperando separador: ','"
#define ERROR_OPERADOR_INVALIDO "error de sintaxis, operador invalido"
#define ERROR_OPERANDO_INVALIDO "error de sintaxis, no es operando (simbolo/numero)"
#define ERROR_FALTA_OPERANDO    "advertencia, esperando operador"

/*
 * COLORES DE FUENTE
 */

#define ERROR_COLOR         "\x1b[91m"
#define HIGHLIGHT_LINE_CODE "\x1b[97m"
#define NORMAL_COLOR        "\x1b[0m"
#endif
