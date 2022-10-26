#include "buffers.h"

Inst_buff *Inst_buff::uniqueBuff = nullptr;

// PRIVATE constructor:
Inst_buff::Inst_buff() { buff = std::vector<Stmt *>(); }

// get unique instance of the singleton
Inst_buff *Inst_buff::getInst_buff() {
  if (!uniqueBuff) {
    uniqueBuff = new Inst_buff();
  }
  return uniqueBuff;
}

void Inst_buff::printBuff(){
  for(Stmt * i : buff){
    i->printData();
  }
};





Str_buff *Str_buff::uniqueBuff = nullptr;

// PRIVATE constructor:
Str_buff::Str_buff() { buff = std::vector<std::string>(); }

// get unique instance of the singleton
Str_buff *Str_buff::getStr_buff() {
  if (!uniqueBuff) {
    uniqueBuff = new Str_buff();
  }
  return uniqueBuff;
}




Inst_buff::~Inst_buff(){};
Str_buff::~Str_buff(){};