#include "Entity.h"
#include "Serializer.h"

int main(int argc, char **argv) {

  Serializer s;

  std::array<std::shared_ptr<Entity>, 3> entities = {
      std::make_shared<Entity>(), std::make_shared<Monster>(),
      std::make_shared<Hero>()};

  for (auto entity : entities)
    entity->Accept(s);

  return 0;
}