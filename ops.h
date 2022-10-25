#include "buffers.h"
#include <iostream>


// This file contains classes for all op_codes needed

// for Friday!
// need to look at what classes each op needs to inherit. i.e does it need
// buffers or symtable or both then we need to implement method functionality

// jmp
class Jump : public Stmt {
private:
public:
  Jump();
  int op_add = 16;
};

// jmpzero
class Jumpzero : public Stmt {
private:
public:
Jumpzero();
  int op_add = 17;
};

// jmpnzro
class Jump_n : public Stmt {
private:
public:
  Jump_n();
  int op_add = 18;
};

// gosub label
class gslabel : public Stmt {
private:
  std::string label;
  double loc;

public:
  gslabel();
  int op_add = 19;
  // virtual TYPE sym_add(std::string label, double loc);
  // virtual TYPE instr_add();
};

//  return
class Return : public Stmt {
private:
public:
  Return();
  int op_add = 20;
};

//  ent_sub is GO_SUB
class Ent_sub : public Stmt {
private:
public:
  Ent_sub();
  int op_add = 21;
};

//  exit_sub
class Exit_sub : public Stmt {
private:
public:
  Exit_sub();
  int op_add = 22;
};

//  start
class Start : public Stmt {
private:
  // in theory this is the op_start address converted to int for now
public:
  Start();
  int op_add = 23;
};

//  exit
class Exit : public Stmt {
private:
public:
  Exit();
  int op_add = 22;
};

//  push_scl
class Push_scl : public Stmt {
private:
public:
  Push_scl();
  int op_add = 32;
};

//  push_arr
class Push_arr : public Stmt {
private:
public:
  Push_arr();
  int op_add = 33;
};

//  push_i
class Push_i : public Stmt {
private:
public:
Push_i();
  int op_add = 34;
};

//  pop_scl
class Pop_scl : public Stmt {
private:
public:
  Pop_scl();
  int op_add = 48;
};

//  pop_arr
class Pop_arr : public Stmt {
private:
public:
  Pop_arr();
  int op_add = 49;
};

//  pop
class Pop : public Stmt {
private:
public:
  Pop();
  int op_add = 50;
};

//  dup
class Dup : public Stmt {
private:
public:
  Dup();
  int op_add = 64;
};

//  swap
class Swap : public Stmt {
private:
public:
  Swap();
  int op_add = 65;
};

//  add
class Add : public Stmt {
private:
public:
  Add();
  int op_add = 80;
};

//  negate
class Negate : public Stmt {
private:
public:
  Negate();
  int op_add = 81;
};

//  mul
class Mul : public Stmt {
private:
public:
  Mul();
  int op_add = 82;
};

//  div
class Div : public Stmt {
private:
public:
  Div();
  int op_add = 83;
};

//  prints
class Prints : public Stmt {
private:
public:
  Prints();
  int op_add = 96;
};

//  printtos
class Printtos : public Stmt {
private:
public:
  Printtos();
  int op_add = 97;
};
