/*
 *  compare a string and a keyword struct
 */
int keyword_cmp( char * s1, Keyword * k1 )
{
  return strcasecmp( s1, k1-> value );
}

/*
 *  compare between keyword structs
 */
int key_2_key_cmp( Keyword * k1, Keyword * k2 )
{
  return strcasecmp( k1-> value, k2-> value );
}
