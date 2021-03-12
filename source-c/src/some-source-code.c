#include "some-source-code.h"
#include <stdint.h>
#include <stdio.h>

void SomeStructure_destroy( tSomeStructure** v ) {
  tSomeStructure* tmp = *v;
  while( tmp ) {
    tSomeStructure* del = tmp;
    tmp = tmp->next;
    printf("destroy %" PRIu32 "\n", del->value);
    free( del );
  }
  *v = NULL;
}

uint32_t SomeStructure_max_value( tSomeStructure* v ) {
  uint32_t m = 0;
  for( ; v; v = v->next ) {
    m = mMax( m, v->value );
  }
  return m;
}

size_t SomeStructure_size( tSomeStructure* v ) {
  size_t size = 0;
  for( ; v; v = v->next ) {
    size++;
  }
  return size;
}
