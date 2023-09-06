#pragma once

#include "Entity.hpp"
#include "Point.hpp"

class Line : public Entity
{
public:
  Line(){};
  ~Line(){};
  Line(Line const &other) = default;
  Line &operator=(Line const &other) = default;

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
  // первая точка
  Point p1{};
  // вторая точка
  Point p2{};
};