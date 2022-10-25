#include <map>
#include <string>
#include <memory>
#include "Data.h"

class instbuff {
  public:
    static instbuff* getSymbolTable();
    std::map<std::string, Data&> map;
    Data& getData(std::string key);
    bool putEntry(std::string key, Data& data);
    ~instbuff();

  private:
    static instbuff* uniqueTable;
    instbuff();
};
