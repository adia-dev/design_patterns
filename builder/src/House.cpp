#include "House.hpp"

House &House::add_room(const std::string &name) {
  this->_rooms.push_back(name);
  return *this;
}
House &House::has_garden(bool &state) { return *this; }
House &House::add_floor() { return *this; }
House &House::add_parking_slot() { return *this; }
House &House::add_parking_slots(int count) { return *this; }
