#include <map>
#include <string>
#include <memory>

class Symtbl {
  public:
    static Symtbl* getSymbolTable();
    std::map<std::string, int> map;

  private:
    static symtbl* uniqueTable;
    
}
