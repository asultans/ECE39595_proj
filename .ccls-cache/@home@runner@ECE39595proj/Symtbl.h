#ifndef SYMTBL_h
#define SYMTBL_h

#include "Data.h"
#include <map>
#include <memory>
#include <string>

class Symtbl {
public:
  static Symtbl *getSymbolTable();
  std::map<std::string, Data *> table;
  Data* getData(std::string key);
  bool putEntry(std::string key, Data *data);
  int getMemory(std::string scope); // calculates memory in the given scope and returns it
  ~Symtbl();
  Symtbl();
  void printTable();
  int getNextLoc();
  void popScope(std::string scope);

private:
  static Symtbl *uniqueTable;
};

#endif