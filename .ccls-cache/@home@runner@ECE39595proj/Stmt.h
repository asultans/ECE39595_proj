#include <iostream>
#include <forward_list>
#include <fstream>
#include <string>
#include "buffers.h"
#include "Symtbl.h"

class Stmt {
  public:
    /* SERIALIZE will write the object to a file in
    sequential order. This file will have a .out file type */
    void serialize(std::ofstream aout_file); 
    Stmt(int op_add_, bool is_init, int location_, std::string name, std::string print, int mem, std::string push_i); 
   // Stmt(int op_add_, bool is_init_);
    virtual ~Stmt();
    int op_add;
    int location;
    std::string name;
    std::string print;
    int mem;
    std::string push_i;
    void op_func(int op_add_, Inst_buff * inst, Symtbl *table);
    bool is_initialized;
   

    void initialize(Symtbl* sym);

    
};