#include <map>
#include <string>
#include <memory>
#include <vector>
#include "Stmt.h"

class Inst_buff {
  public:
    static Inst_buff* getInst_buff();
    std::vector<std::unique_ptr<Stmt>> buff;
    ~Inst_buff();

  private:
    static Inst_buff* uniqueBuff;
    Inst_buff();
};
