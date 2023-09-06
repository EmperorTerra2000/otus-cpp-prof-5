#pragma once

#include <Model.hpp>

class Controller
{
public:
  Controller(Model *model)
  {
    _model = model;
  }

  void createDocument(std::string &nameDocument)
  {
    //...
    _model->createDocument(nameDocument);
    //...
  }

  void importDocument(std::string &pathToDocument)
  {
    //...
    _model->importDocument(pathToDocument);
    //...
  }

  void exportDocument(std::string &pathToDocument)
  {
    //...
    _model->exportDocument(pathToDocument);
    //...
  }

  void createObject(std::string &nameObject)
  {
    //...
    _model->createObject(nameObject);
    //...
  }

  void deleteObject(std::string &nameObject, int &id)
  {
    //...
    _model->deleteObject(nameObject, id);
    //...
  }

private:
  Model *_model;
};