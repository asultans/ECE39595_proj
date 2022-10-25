#ifndef BUFF_h
#define BUFF_h

#include "Data.h"
#include "Stmt.h"
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

class Inst_buff {
public:
  static Inst_buff *getInst_buff();
  std::vector<std::unique_ptr<Stmt>> buff;
  ~Inst_buff();

  Inst_buff();

private:
  static Inst_buff *uniqueBuff;
  // Inst_buff();
};

class Str_buff {
public:
  static Str_buff *getStr_buff();
  std::vector<std::string> buff;
  ~Str_buff();
  Str_buff();

private:
  static Str_buff *uniqueBuff;
  // Str_buff();
};

#endif
