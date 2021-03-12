#pragma once
#include <algorithm>
#include <iostream>

enum class SomeEnum {
  Default = 0,
  Member = 1,
  AnotherMember,
};

template< typename TValue >
struct SomeStructure {
  SomeEnum                         value_of_something{ SomeEnum::Default };
  bool                             ok{ false };
  std::shared_ptr< SomeStructure > next{ nullptr };
  int                              array[ 28 ]{};
  TValue                           value{};

  ~SomeStructure() {
    std::cout << "destroy " << value << "\n";
  }

  [[nodiscard]] TValue get_max_value() const {
    TValue m = std::numeric_limits< TValue >::min();
    for( auto v = this; v; v = v->next.get() ) {
      m = std::max( m, v->value );
    }
    return m;
  }

  [[nodiscard]] size_t get_size() const {
    size_t size = 0;
    for( auto v = this; v; v = v->next.get() ) {
      size++;
    }
    return size;
  }
};
