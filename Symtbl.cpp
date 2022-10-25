//#include "Data.h"
#include "Symtbl.h"
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

Symtbl *Symtbl::uniqueTable = nullptr;

// PRIVATE constructor:
Symtbl::Symtbl() { table = std::map<std::string, Data *>(); }

// get unique instance of the singleton
Symtbl *Symtbl::getSymbolTable() {
  if (!uniqueTable) {
    uniqueTable = new Symtbl();
  }
  return uniqueTable;
}

Data *Symtbl::getData(std::string key) {
  if (!uniqueTable) {
    throw std::invalid_argument(
        "getData::error table was never initialized"); // error: Table was never
                                                       // initialized
  } else {
    for (auto const &e : uniqueTable->table) {
      if (e.first == key) {
        return e.second; // found key return value pair
      }
    }
    throw std::invalid_argument(
        "getData::error key wasn't found"); // key wasn't found
  }
}

bool Symtbl::putEntry(std::string key, Data *data) {
  std::pair<std::map<std::string, Data *>::iterator, bool> ret;

  ret = table.insert({key, data});
  if (ret.second == false) {
    std::cout << "element " << key << " already existed";
    std::cout << " with a value of: (location:" << ret.first->second->location
              << ", length:" << ret.first->second->length << ")" << '\n';
    return false;
  }
  return true;
}

int Symtbl::getMemory(std::string scope) {
  std::map<std::string, Data *>::iterator it;
  int sum = 0;

  for (it = table.begin(); it != table.end(); it++) {
    if ((it->second)->scope == scope)
      sum += (it->second)->length;
  }
  return sum;
};

Symtbl::~Symtbl(){};

void Symtbl::printTable(){
  for(std::map<std::string, Data*>::const_iterator it = table.begin();
  it != table.end(); ++it)
  {  
    std::cout << it->first << "\n";
    it->second->print();
  }
}
