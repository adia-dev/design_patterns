//
// Created by abdoulayedia on 14.01.2023
//
#pragma once

#include "Visitor.h"

// Entity
class Entity {
public:
  Entity() = default;
  virtual ~Entity() = default;

  virtual std::string GetName() const { return "Entity"; }
  virtual void Accept(Visitor v) const { v.Visit(this); }

protected:
};

class Monster : public Entity {
public:
  Monster() = default;
  virtual ~Monster() = default;

  std::string GetName() const override { return "Monster"; }
  void Accept(Visitor v) const override { v.Visit(this); }
};

class Hero : public Entity {
public:
  Hero() = default;
  virtual ~Hero() = default;

  std::string GetName() const override { return "Hero"; }
  void Accept(Visitor v) const override { v.Visit(this); }
};