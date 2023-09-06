#pragma once

#include "Entity.hpp"
#include "Line.hpp"

class Rectangle : public Entity
{
public:
  Rectangle(){};
  ~Rectangle(){};
  Rectangle(Rectangle const &other) = default;
  Rectangle &operator=(Rectangle const &other) = default;

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

private:
  // первая сторона треугольника
  Line l1{};
  // вторая сторона треугольника
  Line l2{};
  // третья сторона треугольника
  Line l3{};
};