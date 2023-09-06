#pragma once

#include <vector>
#include <map>

#include "Document.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Rectangle.hpp"

/*
  класс, с помощью которого наблюдаемый
  объект оповещает наблюдателей
*/
class Observer
{
public:
  virtual void update() = 0;
};

/*
  определяет методы для добавления, удаления
  и оповещения «наблюдателей»
*/
class Observable
{
public:
  Observable(){};

  Observable(Observable const &other) = default;
  ~Observable() = default;
  Observable &operator=(Observable const &other) = default;

  // добавление новых наблюдателей
  void addObserver(Observer *observer)
  {
    _observers.push_back(observer);
  }

  /*
    При вызове метода класс Observable пройдется по списку
    «наблюдателей» и вызовет их методы update(), а они,
    в свою очередь, смогут каким-то образом на это отреагировать.
  */
  void notifyUpdate()
  {
    int size = _observers.size();
    for (int i = 0; i < size; i++)
    {
      _observers[i]->update();
    }
  }

private:
  std::vector<Observer *> _observers;
};

class Model : public Observable
{
public:
  Model(){};

  Model(Model const &other) = default;
  ~Model()
  {
    delete doc;
  };

  Model &operator=(Model const &other) = default;

  void createObject(std::string nameObject)
  {
    if (nameObject == "Point")
    {
      points.insert({1, new Point{}});
    }
    else if (nameObject == "Line")
    {
      lines.insert({1, new Line{}});
    }
    else if (nameObject == "Rectangle")
    {
      rectangls.insert({1, new Rectangle{}});
    }
  }

  void deleteObject(std::string &nameObject, int &id)
  {
    // удалить геометрический объект по id

    notifyUpdate();
  }

  void createDocument(std::string &nameDocument)
  {
    doc = new Document(nameDocument);

    notifyUpdate();
  }

  void importDocument(std::string &pathToDocument)
  {
    //...
    // импортируем документ
    //...
  }

  void exportDocument(std::string &pathToDocument)
  {
    //...
    // экспортируем документ
    //...
  }

private:
  /*
    Коллекция точек
      Аргументы:
      1. int - идентификатор точки
      2. Point - объект точки
  */
  std::map<int, Point *> points{};
  std::map<int, Line *> lines{};
  std::map<int, Rectangle *> rectangls{};

  Document *doc = nullptr;
};