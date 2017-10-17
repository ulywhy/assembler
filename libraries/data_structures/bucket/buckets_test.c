#include <stdlib.h>
#include <stdio.h>
#include <struct.h>//bucketlist and linked list structures

#define SIZE 10
#define LIMIT 100
//this function has the same structure as an (INDEX_CRITERIA_FUNC)
//so there is no need to cast when used
unsigned int get_index_high( void * v ){
  //assign the index according to the higher bit
  int * value = v;
  return *value / 10;
}
unsigned int get_index_low( void * v ){
  //assign the index according to the lower bit
  int * value = v;
  return *value % 10;
}
//this finction should be cast to (COMPARE_FUNC)
//because parameters are not void pointers
int cmp_function( int * v1, int * v2){
  
  if( *v1 == *v2)
  {
    return 0;
  }else{
    return 1;
  }
}

int main( void ){

  //local variables
  BucketList my_bucket_list;
  List bucket, tmp;
  int * ptr;
  int var1 = 9;
  //call init finction
  my_bucket_list = bucket_init( SIZE );
    
  for(int y = 1; y < LIMIT; y++){
    ptr = malloc( sizeof( int ) );
    *ptr = y;
    //insert dynamicaly allocated variables
    bucket_insert( my_bucket_list, ptr, get_index_low );
  }

  //manual traverse of buckets
  for(int x = 0; x < SIZE; x++){
    bucket = my_bucket_list[x];
    printf("list number %d\n", x+1);
    while( bucket != NULL ){
      printf("\t|%3d\n", *(int *) ( bucket-> data) );
      bucket = bucket-> next;
    }
  }
  //FIND
  ptr = NULL;
  ptr = bucket_find( my_bucket_list, &var1, get_index_low, (COMPARE_FUNC)cmp_function );
  if( ptr != NULL ){
    printf("encontrado valor: %d\n", *ptr);
  }

  //FREE
  //NULL should not be passed as a free_function
  bucket_free( my_bucket_list, free );
return 0;
}