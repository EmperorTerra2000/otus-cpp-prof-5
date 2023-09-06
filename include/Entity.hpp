#pragma once

#include <string>
#include <array>

class Entity
{
public:
  Entity() {}
  virtual ~Entity() {}

  Entity(Entity const &other) = default;
  Entity &operator=(Entity const &other) = default;

protected:
  float x{}, y{};
  std::string nameObject{};
  std::array<float, 2> location{};

  // отрисовать геом-ий объект
  virtual void draw() = 0;
  // получить имя объекта (точка, линия итд)
  virtual std::string getNameObject() = 0;

  virtual void setX(double x) = 0;
  virtual void setY(double y) = 0;
  virtual float getX() = 0;
  virtual float getY() = 0;
  // получить расположение объекта относительно левого верхнего угла
  virtual std::array<float, 2> getLocation() = 0;
  // удаление объекта
  virtual void deleteObject() = 0;
};