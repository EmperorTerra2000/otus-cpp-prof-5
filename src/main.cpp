#include <iostream>

#include "Controller.hpp"
#include "Model.hpp"
#include "View.hpp"

// событие создания нового объекта
void handlerCreateObject(Controller &cnt, std::string nameObject)
{
  // делегируем создание нового объекта контроллеру
  cnt.createObject(nameObject);
}

// событие удаления объекта
void handlerDeleteObject(Controller &cnt, std::string nameObject, int id)
{
  // делегируем создание нового объекта контроллеру
  cnt.deleteObject(nameObject, id);
}

void handlerCreateDocument(Controller &cnt, std::string nameDocument)
{
  cnt.createDocument(nameDocument);
};

void handlerImportDocument(Controller &cnt, std::string pathToDocument)
{
  cnt.importDocument(pathToDocument);
};

void handlerExportDocument(Controller &cnt, std::string pathToDocument)
{
  cnt.exportDocument(pathToDocument);
};

int main()
{
  Model model;
  View view(&model);
  Controller controller(&model);

  handlerCreateObject(controller, "Line");
  handlerDeleteObject(controller, "Line", 3);

  handlerCreateDocument(controller, "project_2.cdw");

  handlerImportDocument(controller, "/media/documents/project_1.cdw");
  handlerExportDocument(controller, "/media/documents");

  return 0;
}