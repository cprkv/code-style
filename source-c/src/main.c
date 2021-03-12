#include "some-source-code.h"
#include <stdio.h>
#include <stdlib.h>

static tSomeStructure* create_some_structure() {
  return mNewStruct( tSomeStructure,
    {
      .value_of_something = eSomeEnumMember,
      .array = { 1, 2, 3 },
      .ok = false,
      .value = rand(),
    } );
}

int main( int argc, char** argv ) {
  tSomeStructure* structure = create_some_structure();
  structure->next = create_some_structure();
  structure->next->next = create_some_structure();

  printf( "get_size: %zu\n", SomeStructure_size( structure ) );
  printf( "get_max_value: %" PRIu32 " \n", SomeStructure_max_value( structure ) );

  SomeStructure_destroy( &structure );
  printf( "get_size: %zu\n", SomeStructure_size( structure ) );

  return 0;
}
