string set_line( string line )
{
  char * new_line_ptr;
 /* overwrite NEW-LINE char if any */
  /* find NEW-LINE char */
  new_line_ptr = index( line, '\n' );
  /* ends with '\n'? */
  if( new_line_ptr != NULL ){
    /* finish line with NULL-BYTE */
    VALUE( new_line_ptr ) = '\0';
  }
  return line;
}
