#pragma once

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class House {
public:
  House() = default;
  ~House() = default;

  House &add_room(const std::string &name);
  House &has_garden(bool &state);
  House &add_floor();
  House &add_parking_slot();
  House &add_parking_slots(int count);

  void set_address(const std::string &address) { _address = address; }

  void print_info() const {
    std::cout << "Address: " << _address << "\n";

    if (_rooms.size() > 0) {
      std::cout << "Rooms: \n";
      std::for_each_n(_rooms.begin(), _rooms.size(),
                      [](const std::string &room) {
                        std::cout << " - " << room << std::endl;
                      });
    } else {
      std::cout << "This house has no rooms.\n";
    }
  }

private:
  std::vector<std::string> _rooms;
  std::string _address;
};
