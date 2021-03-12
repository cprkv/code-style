#pragma once
#include "some-source-code.hpp"

namespace some {
  template< typename TValue >
  SomeStructure< TValue >::~SomeStructure() {
    std::cout << "destroy " << value << "\n";
  }

  template< typename TValue >
  TValue SomeStructure< TValue >::get_max_value() const {
    TValue m = std::numeric_limits< TValue >::min();
    for( auto v = this; v; v = v->next.get() ) {
      m = std::max( m, v->value );
    }
    return m;
  }

  template< typename TValue >
  size_t SomeStructure< TValue >::get_size() const {
    size_t size = 0;
    for( auto v = this; v; v = v->next.get() ) {
      size++;
    }
    return size;
  }
} // namespace some