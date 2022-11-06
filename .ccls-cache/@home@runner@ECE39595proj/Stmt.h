#ifndef STMT_H
#define STMT_H
#include <fstream>
#include <iostream>
#include "Symtbl.h"

class Stmt {
  public:
    Stmt();
    virtual ~Stmt();
    virtual void printData();
    int op_add = -1;
    // virtual int getOp(){};
    bool is_init = true;
    virtual void initialize(Symtbl* sym);
    virtual void serialize(std::fstream &out);
};

#endif