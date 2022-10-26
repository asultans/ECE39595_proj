#ifndef OPS_H
#define OPS_H

#include "Stmt.h"
#include <iostream>


// This file contains classes for all op_codes needed

// for Friday!
// need to look at what classes each op needs to inherit. i.e does it need
// buffers or symtable or both then we need to implement method functionality

// jmp
class Jump : public Stmt {
private:
public:
  Jump(std::string jm);
  std::string jm;
  int op_add = 16;
  virtual void printData();
};

// jmpzero
class Jumpzero : public Stmt {
private:
public:
std::string jmp_z;
Jumpzero(std::string jmp_z);
virtual void printData();
int op_add = 17;
};

// jmpnzro
class Jump_n : public Stmt {
private:
public:
  std::string jmp_n;
  Jump_n(std::string jmp_n);
  int op_add = 18;
  virtual void printData();
};

// gosub label
class gslabel : public Stmt {
private:
public:
  std::string name;
  gslabel(std::string name);
  int op_add = 19;
  virtual void printData();
  // virtual TYPE sym_add(std::string label, double loc);
  // virtual TYPE instr_add();
};

//  return
class Ret : public Stmt {
private:
public:
  Ret();
  int op_add = 20;
  virtual void printData();
};

//  ent_sub is GO_SUB
class Ent_sub : public Stmt {
private:
public:
  Ent_sub(std::string label);
  std::string label;
  int op_add = 21;
  virtual void printData();
};

//  start
class Start : public Stmt {
private:
  // in theory this is the op_start address converted to int for now
public:
  int mem = 0;
  Start();
  virtual void printData();
  int op_add = 23;
};

//  exit
class Exit : public Stmt {
private:
public:
  Exit();
  virtual void printData();
  int op_add = 22;
};

//  push_scl
class Push_scl : public Stmt {
private:
public:
  std::string name;
  Push_scl(std::string name);
  virtual void printData();
  int op_add = 32;
};

//  push_arr
class Push_arr : public Stmt {
private:
public:
  Push_arr(std::string name_, int mem);
  virtual void printData();
  std::string name;
  int op_add = 33;
  int mem;
};

//  push_i
class Push_i : public Stmt {
private:
public:
  // maybe change to digit? current serialize works with string so maybe dont change
  std::string i;
  virtual void printData();
  Push_i(std::string i);
  int op_add = 34;
};

//  pop_scl
class Pop_scl : public Stmt {
private:
public:
  std::string name;
  virtual void printData();
  Pop_scl(std::string name);
  int op_add = 48;
};

//  pop_arr
class Pop_arr : public Stmt {
private:
public:
  std::string name;
  virtual void printData();
  Pop_arr(std::string name);
  int op_add = 49;
};

//  pop
class Pop : public Stmt {
private:
public:
  virtual void printData();
  Pop();
  int op_add = 50;
};

//  dup
class Dup : public Stmt {
private:
public:
  Dup();
  virtual void printData();
  int op_add = 64;
};

//  swap
class Swap : public Stmt {
private:
public:
  Swap();
  virtual void printData();
  int op_add = 65;
};

//  add
class Add : public Stmt {
private:
public:
  Add();
  virtual void printData();
  int op_add = 80;
};

//  negate
class Negate : public Stmt {
private:
public:
  Negate();
  virtual void printData();
  int op_add = 81;
};

//  mul
class Mul : public Stmt {
private:
public:
  Mul();
  virtual void printData();
  int op_add = 82;
};

//  div
class Div : public Stmt {
private:
public:
  Div();
  virtual void printData();
  int op_add = 83;
};

//  prints
class Prints : public Stmt {
private:
public:
  std::string printed;
  Prints(std::string printed);
  virtual void printData();
  int op_add = 96;
};

//  printtos
class Printtos : public Stmt {
private:
public:
  Printtos();
  int op_add = 97;
  virtual void printData();
};

#endif