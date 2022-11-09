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
    //std::cout << "\nThe following key not found " << key << std::endl;
    // throw std::invalid_argument(
    //     "getData::error key wasn't found"); // key wasn't found
    return nullptr;
  }
}

bool Symtbl::putEntry(std::string key, Data *data) {

  if(!data->is_label && data->location != -1){
    std::cout << "\nERROR variable location is improperly initialized. Main->Symtbl::putEntry";
    std::cout << "\nis_label: " << data->is_label <<" | loc:" << data->location << "\n\n";
    return false;
  }
  
  //if it's a variable then get next location
  if (!data->is_label){
    data->location = getNextLoc();
  }

  std::pair<std::map<std::string, Data *>::iterator, bool> ret;
  ret = table.insert({key, data});
  if (ret.second == false) {
    // std::cout << "\nElement " << key << " already existed";
    // std::cout << " with a value of: (location:" << ret.first->second->location
    //           << ", length:" << ret.first->second->length << ")" << '\n';
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
    std::cout << "\nKey: [" << it->first << "]\nData: ";
    it->second->print();
  }
}

int Symtbl::getNextLoc(){
  int loc = 0;
  for(std::map<std::string, Data*>::const_iterator it = table.begin();
  it != table.end(); ++it)
  {  
    //add len of all variables
    if (!it->second->is_label){ 
      loc += it->second->length;
    }
  }
  return loc;
}

void Symtbl::popScope(std::string scope){
  std::map<std::string, Data *>::iterator it;

  for (it = table.begin(); it != table.end(); it++) {
    if ((it->second)->scope == scope)
      table.erase(it);
  }
  return;
}


