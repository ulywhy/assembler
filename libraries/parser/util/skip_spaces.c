#ifndef SKIP_SPACES
#define SKIP_SPACES

/* using: ctype.h and data_type.h */
string skip_spaces( string line ){
  /* mientras sea espacio o tab */
  while( isblank( VALUE( line ) ) ){
    /* apunta al siguiente caracter */
    line++;
  }
  /* devolver line */
  return line;
}
#endif
