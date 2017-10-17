#include"../../data_type.h"

#ifndef LEXICAL_HEADER
#define LEXICAL_HEADER


#define CANTIDAD_SIMBOLOS_DOBLES 16
#define CANTIDAD_SIMBOLOS_SIMPLES 24
#define LONGITUD_MAX_SIMBOLOS 2 //simbolos dobles
#define COINCIDENCIA_COMPARACION 0


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

/* usa el operador '*' para acceder al VALUE que
 * contiene la direccion a la que se apunta */
#define VALUE( ptr )    ( * ptr )

/* compara con el character de
 *fin de linea o de nueva linea */
#define END_LINE( character )    ( character == '\0' || character == '\n' )

/* compara el character con delimitadores que pueden ser
 * fin de linea, espacio, y simbolos */
#define DELIMITER( character )      ( isblank( character ) ||    \
                                          ispunct( character ) ||    \
                                          END_LINE( character ) )


Token * is_binary( string * );

Token * is_octal( string * );

Token * is_decimal( string * );

Token * is_hexadecimal( string * );

Token * is_identifier( string * );

Token * is_symbol( string * );

Token * is_literal( string * );

Token * token_create( TokenType type, string inicio_token, string fin_token );

#include "token_create/token_create.c"
#include "is_binary/is_binary.c"
#include "is_octal/is_octal.c"
#include "is_decimal/is_decimal.c"
#include "is_hexadecimal/is_hexadecimal.c"
#include "is_identifier/is_identifier.c"
#include "is_literal/is_literal.c"
#include "is_symbol/is_symbol.c"

#endif
