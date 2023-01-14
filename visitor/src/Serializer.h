//
// Created by abdoulayedia on 14.01.2023
//
#pragma once

#include "Visitor.h"

// Serializer
class Serializer : public Visitor {
public:
  Serializer() = default;
  ~Serializer() = default;

  void Visit(const Entity *e) override;
  void Visit(const Monster *m) override;
  void Visit(const Hero *h) override;

private:
};
