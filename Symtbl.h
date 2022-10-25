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

private:
  static Symtbl *uniqueTable;
};
