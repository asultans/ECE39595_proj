#include "Stmt.h"

Stmt::Stmt() {};
Stmt::~Stmt() {};
void Stmt::printData() {
  std::cout <<" THIS SHOULDN'T PRINT";
};
void Stmt::serialize(std::fstream &out) {
  std::cout <<" THIS SHOULDN'T PRINT";
};
void Stmt::initialize(Symtbl *sym) {
  if (is_init){
    return;
  }
  else {
    std::cout << "error. is_init false. func not overridden THIS SHOULDN'T PRINT\nError in function: ";
    printData();
  }
  
}