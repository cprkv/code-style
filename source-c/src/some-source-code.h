#pragma once
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef mMax
  #define mMax( a, b ) ( a ) > ( b ) ? ( a ) : ( b )
#endif

#define mNewStruct( t, ... ) ( t* ) ( memcpy( malloc( sizeof( t ) ), &( t ) __VA_ARGS__, sizeof( t ) ) )

typedef enum SomeEnum        tSomeEnum;
typedef struct SomeStructure tSomeStructure;

enum SomeEnum {
  eSomeEnumDefault = 0,
  eSomeEnumMember = 1,
  eSomeEnumAnotherMember,
};

struct SomeStructure {
  tSomeEnum       value_of_something;
  bool            ok;
  tSomeStructure* next;
  int             array[ 28 ];
  uint32_t        value;
};

static void SomeStructure_destroy( tSomeStructure** v ) {
  tSomeStructure* tmp = *v;
  while( tmp ) {
    tSomeStructure* del = tmp;
    tmp = tmp->next;
    printf("deleting %" PRIu32 "\n", del->value);
    free( del );
  }
  *v = NULL;
}

static uint32_t SomeStructure_max_value( tSomeStructure* v ) {
  uint32_t m = 0;
  for( ; v; v = v->next ) {
    m = mMax( m, v->value );
  }
  return m;
}

static size_t SomeStructure_size( tSomeStructure* v ) {
  size_t size = 0;
  for( ; v; v = v->next ) {
    size++;
  }
  return size;
}
