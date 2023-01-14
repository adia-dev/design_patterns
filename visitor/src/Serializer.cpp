//
// Created by abdoulayedia on 14.01.2023
//
#include "Serializer.h"

void Serializer::Visit(const Entity *e) {
  std::cout << "Saving an Entity" << std::endl;
}

void Serializer::Visit(const Monster *m) {
  std::cout << "Saving a Monster" << std::endl;
}

void Serializer::Visit(const Hero *h) {
  std::cout << "Saving a Hero" << std::endl;
}
