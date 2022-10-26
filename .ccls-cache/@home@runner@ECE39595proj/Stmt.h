#ifndef STMT_H
#define STMT_H
#include <fstream>
#include <iostream>

class Stmt {
  public:
    Stmt();
    virtual ~Stmt();
    virtual void printData();
    // bool is_initialized = false;
    // virtual void initialize(Symtbl* sym) = 0;
    // virtual void serialize(char * aout_file);
};

#endif