/*
 *  compare a string and a keyword struct
 */
int keyword_cmp( char * s1, Keyword_t * k1 )
{
  return strcasecmp( s1, k1-> value );
}

/*
 *  compare between keyword structs
 */
int key_2_key_cmp( Keyword_t * k1, Keyword_t * k2 )
{
  if( NULL != k1 && NULL != k2 )
    return strcasecmp( k1-> value, k2-> value );
  else
    return 1;
}
