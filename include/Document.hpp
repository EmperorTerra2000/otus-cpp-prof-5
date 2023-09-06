#pragma once

#include <string>

class Document
{
public:
  Document(std::string name){};

  Document(Document const &other) = default;
  ~Document() = default;
  Document &operator=(Document const &other) = default;
};