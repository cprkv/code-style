#pragma once
#include <inttypes.h>
#include <stdbool.h>
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

void     SomeStructure_destroy( tSomeStructure** v );
uint32_t SomeStructure_max_value( tSomeStructure* v );
size_t   SomeStructure_size( tSomeStructure* v );
