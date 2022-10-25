
#include "Stmt.h"
#include "Symtbl.h"
#include <fstream>

void Stmt::serialize(char *aout_fil) {

  ofstream fl;
  fl.open(aout_file);
  if (!fl) {
    printf("error with output file\n");
  } else {
    // determine op_code and print accordingly

    // this if is for mem prints
    if ((op_add == 21) || op_add == 23) {
      if (op_add == 21) {
        fl << "GoSub " + name + "(" + mem + ")" + "\n";
      } else {
        fl << "Start " + mem + "\n";
      }
    }

    // this if is for location based prints
    // this has jumps, pops and pushs
    else if (op_add == (16 || 17 || 18 || 19 || 32 || 33 || 34 || 48 || 49)) {
      if (op_add == 16) {
        fl << "Jump, " + location + "\n";
      } else if (op_add == 17) {
        fl << "JumpZero, " + name + ", (" + location + ")\n";
      } else if (op_add == 18) {
        fl << "JumpNZero, " + name + ", (" + location + ")\n";

      } else if (op_add == 19) {
        fl << "GoSubLabel , " + name + "\n";
      } else if (op_add == 32) {
        fl << "PushScalar " + name + ", (" + location + ")\n";
      } else if (op_add == 33) {
        fl << "PushArray " + name + ", (" + location + ")\n";
      } else if (op_add == 34) {
        fl << "PushI  " + "(" + pushi + ")\n";
      } else if (op_add == 48) {
        fl << "PopScalar " + name + ", (" + location + ")\n";
      } else {
        fl << "PopArray " + name + ", (" + location + ")\n";
      }

    }

    // this is going to just do basic print op_code name
    else if (op_add == 96) {
      fl << "Prints " + print + "\n"
    } else if (op_add == 97) {
      fl << "PrintTOS\n";
    } else if (op_add == 22) {
      fl << "Return\n";
    } else if (op_add == 24) {
      fl << "Exit\n";
    } else if (op_add == 64) {
      fl << "Dup\n";
    } else if (op_add == 65) {
      fl << "Swap\n";
    } else if (op_add == 80) {
      fl << "Add\n";
    } else if (op_add == 81) {
      fl << "Negate\n";
    } else if (op_add == 82) {
      fl << "Mul\n";
    } else if (op_add == 83) {
      fl << "Div\n";
    } else {
      fl << "Op code not accounted for " + op_add + "\n";
    }
  }
};

// Stmt::Stmt(int op_add_) 
//   : op_add(op_add_){
//     mem = -1;
//     push_i = -1;
//     initialize = false;
//     print = "wrong";
//     location = -1;
//     name = "wrong";
//   };

Stmt::~Stmt(){};

void Stmt::op_func(int op_add_, Inst_buff *buff, Symtbl *table) {
  // requires memory
  if ((op_add_ == 21) || (op_add_ == 23)) {
    mem = Symtbl::getMemory(std::string scope);
    // update memory variable and attach to data in inst_buff
  } else if (op_add_ == 34) {
    // update the pushi val and attach to data in inst_buff i.e. <prints,
    // std::string >
  } else if (op_add_ == 96) {
    // update the std::string print and add to data in inst_buff i.e. <prints,
    // std::string print>
  }
};

void Stmt::initialize(Symtbl *sym) {
  location = sym->getData(name)->location;
  is_initialized = true;
  return;
}

Stmt::Stmt(int op_add_, bool is_init, int location_, std::string name_, std::string print_, int mem_, int push_i_)
  : op_add(op_add_), is_initialized(is_init), location(location_), name(name_),
    print(print_), mem(mem_), push_i(push_i_) {};

// Stmt::Stmt(int op_add_, bool is_init_)
//   : op_add(op_add_), is_initialized(is_init_){};





     
