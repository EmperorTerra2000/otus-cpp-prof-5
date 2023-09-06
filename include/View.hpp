#pragma once

#include "Model.hpp"

class View : public Observer
{
public:
  View(Model *model)
  {
    _model = model;
    _model->addObserver(this);
  }
  virtual void update()
  {
    // отрисовать в GUI обновленные географичесие объекты
  }

private:
  Model *_model;
};