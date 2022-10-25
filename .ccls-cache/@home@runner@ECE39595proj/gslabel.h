#include <iostream>

class gslabel : public Stmt {
private:
  std::string label;
  double loc;
public:
  virtual TYPE sym_add(std::string label, double loc);
  virtual TYPE instr_add();

}
