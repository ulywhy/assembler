#include <stdio.h>
/*
 * file_open
 * handles the openning of a file
 * calls fopen and checks if the operation was succesfull
 * else prints an error to 'stderr'
 * RETURN VALUE TRUE if no error happened while openning file
 * else FALSE is returned
 */
#ifndef FILE_OPEN_BODY
#define FILE_OPEN_BODY

int file_open( const char * file_name, const char * mode, FILE ** file_ptr )
{
  *file_ptr = fopen( file_name, mode );
  if( NULL == *file_ptr )
  {
    perror( file_name );
    return 0;
  }else
  {
    return 1;
  }
}

#endif