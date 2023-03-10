//
// Created by abdoulayedia on 14.01.2023
//
#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

class Entity;
class Monster;
class Hero;

// Visitor
class Visitor {
public:
  Visitor() = default;
  virtual ~Visitor() = default;

  virtual void Visit(const Entity *e) {
    throw std::runtime_error("Not implemented");
  }
  virtual void Visit(const Monster *m) {
    throw std::runtime_error("Not implemented");
  }
  virtual void Visit(const Hero *h) {
    throw std::runtime_error("Not implemented");
  }

private:
};
