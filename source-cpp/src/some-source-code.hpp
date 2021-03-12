#pragma once
#include <algorithm>
#include <iostream>

namespace some {
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

    ~SomeStructure();

    [[nodiscard]] TValue get_max_value() const;
    [[nodiscard]] size_t get_size() const;
  };
} // namespace some

#include "some-source-code.inl"
