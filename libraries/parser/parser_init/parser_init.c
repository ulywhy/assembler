bool parser_init( string source_file_name )
{
  /* intentar abrir archivo en modo lectura */
  parser.source_file = fopen( source_file_name, "r" );

  if( parser.source_file == NULL ){
    fprintf( stderr, "el archivo %s no existe\n", source_file_name );
    return FALSE;
  }else{
    return TRUE;
  }
}
