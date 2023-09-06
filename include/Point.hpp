#pragma once

#include "Entity.hpp"

class Point : public Entity
{
public:
  Point(){};
  ~Point(){};
  Point(Point const &other) = default;
  Point &operator=(Point const &other) = default;

public:
  // отрисовать геом-ий объект
  void draw() override{};
  // получить имя объекта
  std::string getNameObject() override{};
  void setX(double x) override{};
  void setY(double y) override{};
  float getX() override{};
  float getY() override{};
  // получить расположение объекта относительно левого верхнего угла
  std::array<float, 2> getLocation() override{};
  // удаление объекта
  void deleteObject() override{};
};