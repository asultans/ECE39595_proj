#ifndef STMT_H
#define STMT_H

class Stmt {
  public:
    Stmt() {};
    virtual ~Stmt() {};
    // bool is_initialized;
    // virtual void initialize(Symtbl* sym) = 0;
    // virtual void serialize(std::ofstream aout_file) = 0;   
};

#endif