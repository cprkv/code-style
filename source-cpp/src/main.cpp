#include "some-source-code.hpp"

using namespace some;

static auto create_some_structure() {
  SomeStructure< uint32_t > value{
    .value_of_something = SomeEnum::Member,
    .ok = false,
    .next = nullptr,
    .array = { 1, 2, 3 },
    .value = static_cast< uint32_t >( rand() ),
  };
  return std::make_shared< SomeStructure< uint32_t > >( value );
}

int main( int argc, char** argv ) {
  auto structure = create_some_structure();
  structure->next = create_some_structure();
  structure->next->next = create_some_structure();

  std::cout << "size: " << structure->get_size() << "\n";
  std::cout << "max_value: " << structure->get_max_value() << "\n";

  return 0;
}
