#include <iostream>
#include <string>
#include <map>
#include "Inst_buff.h"
#include "Data.h"

Inst_buff* Inst_buff::uniqueBuff = nullptr;

//PRIVATE constructor:
Inst_buff::Inst_buff() {
  buff = std::vector<std::unique_ptr<Stmt>>();
}

//get unique instance of the singleton
Inst_buff* Inst_buff::getInst_buff() {
  if (!uniqueBuff) {
    uniqueBuff = new Inst_buff();
  }
  return uniqueBuff;
}