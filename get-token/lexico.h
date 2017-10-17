#ifndef BIBLIOTECA_LEXICO
#define BIBLIOTECA_LEXICO

#define CANTIDAD_DE_AGRUPADORES 3 /* corchete:[], llaves:{} y parentesis:() */
#define INICIO_CONTADOR_AGRUPADORES 0

#define CANTIDAD_SIMBOLOS_DOBLES 16
#define CANTIDAD_SIMBOLOS_SIMPLES 24
#define LONGITUD_MAX_SIMBOLOS 2 //simbolos dobles
#define COINCIDENCIA_COMPARACION 0

/* define tipo de dato string */
typedef char * string;

/* lista de simbolos dobles permitidos */
static string SIMBOLOS_DOBLES  [ CANTIDAD_SIMBOLOS_DOBLES ]  = { "==", "<=", 
                                                                 "&&", "++",
                                                                 ">=", "||",
                                                                 "--", "+=",
                                                                 "-=", "*=",
                                                                 "/=", "%=",
                                                                 "!=", "->",
                                                                 "<<", ">>"
                                                               };
static string SIMBOLOS_SIMPLES [ CANTIDAD_SIMBOLOS_SIMPLES ] = { "?", "=", "!",
                                                                 "+", "*", "%",
                                                                 "&", "<", ">",
                                                                 "-", "^", ".",
                                                                 "|", "{", "}", 
                                                                 ",", "[", "]",
                                                                  "/","(", ")",
                                                                 "\"", ":", ";"
                                                               };

/* usa el operador '*' para acceder al valor que 
 * contiene la direccion a la que se apunta */
#define VALOR( apuntador )    ( * apuntador )

/* compara con el caracter de 
 *fin de linea o de nueva linea */
#define FIN_DE_LINEA( caracter )    ( caracter == '\0' || caracter == '\n' )

/* compara el caracter con delimitadores que pueden ser
 * fin de linea, espacio, y simbolos */
#define ES_DELIMITADOR( caracter )      ( isblank( caracter ) ||    \
                                          ispunct( caracter ) ||    \
                                          FIN_DE_LINEA( caracter ) )

/* cabecera de funcion que analiza si el simbolo es doble,
 * de agrupacion simple o inválido */
string analizar_simbolo( string * );

string analizar_decimal( string * );

string analizar_hexadecimal( string * );

string analizar_binario( string * );

string analizar_octal( string *);

string analizar_identificador( string * );

string analizar_literal( string * );

string clonar_token( int longitud, string inicio_token );


#endif