#ifndef OPS_H
#define OPS_H

#include "Stmt.h"
#include "Symtbl.h"
#include <iostream>
#include <fstream>


// This file contains classes for all op_codes needed

// for Friday!
// need to look at what classes each op needs to inherit. i.e does it need
// buffers or symtable or both then we need to implement method functionality

// jmp
class Jump : public Stmt {
private:
public:
  Jump(std::string jm);
  int loc = -1;
  std::string jm;
  int op_add = 16;
  virtual void printData();
  virtual void serialize(std::fstream &out);
  virtual void initialize(Symtbl* sym);
};

// jmpzero
class Jumpzero : public Stmt {
private:
public:
std::string jmp_z;
int loc = -1;
Jumpzero(std::string jmp_z);
virtual void serialize(std::fstream &out);
virtual void initialize(Symtbl* sym);
virtual void printData();
int op_add = 17;
};

// jmpnzro
class Jump_n : public Stmt {
private:
public:
  std::string jmp_n;
  int loc = -1;
  virtual void serialize(std::fstream &out);
  virtual void initialize(Symtbl* sym);
  Jump_n(std::string jmp_n);
  int op_add = 18;
  virtual void printData();
};

// gosub label
class gslabel : public Stmt {
private:
public:
  std::string name;
  virtual void serialize(std::fstream &out);
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
  virtual void serialize(std::fstream &out);
};

//  ent_sub 
// class Ent_sub : public Stmt {
// private:
// public:
//   Ent_sub(std::string label);
//   std::string label;
//   int mem;
//   int op_add = 21;
//   virtual void printData();
//   virtual void serialize(std::fstream &out);
// };

// go sub
class GoSub : public Stmt {
public:
  GoSub(std::string label);
  std::string label;
  int loc;
  int op_add = 19;
  virtual void printData();
  virtual void serialize(std::fstream &out);
  virtual void initialize(Symtbl * sym);
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
  virtual void serialize(std::fstream &out);
  virtual void initialize(Symtbl * sym);
};

//  exit
class Exit : public Stmt {
private:
public:
  Exit();
  virtual void printData();
  int op_add = 22;
  virtual void serialize(std::fstream &out);
};

//  push_scl
class Push_scl : public Stmt {
private:
public:
  std::string name;
  int loc = -1;
  Push_scl(std::string name, Symtbl * sym);
  virtual void printData();
  int op_add = 32;
  virtual void serialize(std::fstream &out);
};

//  push_arr
class Push_arr : public Stmt {
private:
public:
  Push_arr(std::string name_, Symtbl * sym);
  virtual void printData();
  std::string name;
  int op_add = 33;
  int loc = -1;
  virtual void serialize(std::fstream &out);
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
  virtual void serialize(std::fstream &out);
};

//  pop_scl
class Pop_scl : public Stmt {
private:
public:
  std::string name;
  int loc = -1;
  virtual void printData();
  Pop_scl(std::string name, Symtbl * sym);
  int op_add = 48;
  virtual void serialize(std::fstream &out);
};

//  pop_arr
class Pop_arr : public Stmt {
private:
public:
  std::string name;
  int loc = -1;
  virtual void printData();
  Pop_arr(std::string name, Symtbl * sym);
  int op_add = 49;
  virtual void serialize(std::fstream &out);
};

//  pop
class Pop : public Stmt {
private:
public:
  virtual void printData();
  Pop();
  int op_add = 50;
  virtual void serialize(std::fstream &out);
};

//  dup
class Dup : public Stmt {
private:
public:
  Dup();
  virtual void printData();
  int op_add = 64;
  virtual void serialize(std::fstream &out);
};

//  swap
class Swap : public Stmt {
private:
public:
  Swap();
  virtual void printData();
  int op_add = 65;
  virtual void serialize(std::fstream &out);
};

//  add
class Add : public Stmt {
private:
public:
  Add();
  virtual void printData();
  int op_add = 80;
  virtual void serialize(std::fstream &out);
};

//  negate
class Negate : public Stmt {
private:
public:
  Negate();
  virtual void printData();
  int op_add = 81;
  virtual void serialize(std::fstream &out);
};

//  mul
class Mul : public Stmt {
private:
public:
  Mul();
  virtual void printData();
  int op_add = 82;
  virtual void serialize(std::fstream &out);
};

//  div
class Div : public Stmt {
private:
public:
  Div();
  virtual void printData();
  int op_add = 83;
  virtual void serialize(std::fstream &out);
};

//  prints
class Prints : public Stmt {
private:
public:
  std::string printed;
  Prints(std::string printed);
  virtual void printData();
  int op_add = 96;
  virtual void serialize(std::fstream &out);
};

//  printtos
class Printtos : public Stmt {
private:
public:
  Printtos();
  int op_add = 97;
  virtual void printData();
  virtual void serialize(std::fstream &out);
};

#endif