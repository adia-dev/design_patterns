#include "HouseBuilder.hpp"

int main(int argc, char *argv[]) {

  // House new_house = House()
  //                       .add_floor()
  //                       .add_room("Parent's room")
  //                       .add_room("Parent's bathroom");
  //

  House new_house = HouseBuilder::blueprint()
                        .set_address("3 Allée Jacques Tati")
                        .add_room("Parent's room")
                        .add_room("Parent's bathroom")
                        .add_room("First kid room")
                        .add_room("First kid bathroom")
                        .add_room("Second kid bathroom")
                        .build();

  new_house.print_info();

  return 0;
}
