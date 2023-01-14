#include "Entity.h"
#include "Serializer.h"

int main(int argc, char **argv) {

  Serializer s;
  Visitor v;

  std::array<std::shared_ptr<Entity>, 3> entities = {
      std::make_shared<Entity>(), std::make_shared<Monster>(),
      std::make_shared<Hero>()};

  for (auto entity : entities)
    try {
      entity->Accept(s);
      // entity->Accept(v);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

  return 0;
}