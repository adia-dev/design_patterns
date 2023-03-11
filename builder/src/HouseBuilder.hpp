#pragma once

#include "House.hpp"

class HouseBuilder {
public:
  HouseBuilder() = default;
  ~HouseBuilder() = default;

  static HouseBuilder blueprint() { return HouseBuilder(); }
  HouseBuilder &add_room(const std::string &name);
  HouseBuilder &set_address(const std::string &address);
  House build();

private:
  House _house;
};
