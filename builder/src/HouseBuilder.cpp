#include "HouseBuilder.hpp"

HouseBuilder &HouseBuilder::add_room(const std::string &name) {
  _house.add_room(name);
  return *this;
}

House HouseBuilder::build() { return _house; }

HouseBuilder &HouseBuilder::set_address(const std::string &address) {
  _house.set_address(address);
  return *this;
}
