#include <map>
#include <string>
#include "symtbl.h"

Symtbl* symtbl::uniqueTable = nullptr;

symtbl::symtbl() {
  map = std::map<std::string, int>();
  idx = 0;
}
static symtbl* symtbl::getSymbolTable() {
  if (!map) {
    mapDefined = make_unique<map<std::string, int>>();
  }
  return mapDefined;
}
int symtbl::getData(std::string key) {
  if (!mapDefined) {
    return 2147483647; // just an error value I picked
    for (auto const &e : *definedMap) {
      if (e.first == key) {
        return x.second;
      }
    }
  }
  bool putEntry(std::string key, int datum);
#endif /* SYMBOLTABLE_H_ */