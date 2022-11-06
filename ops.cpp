#include "ops.h"

Jump::Jump(std::string jm_): jm(jm_){};
void Jump::printData(){
  std::cout << "Jump, " << loc << "\n";
};
void Jump::serialize(std::fstream &out){
  out << "Jump, " <<loc <<"\n";
};
void Jump::initialize(Symtbl * sym){
  if (!is_init) {
    //uninitialized -> patch up
    if (sym->getData(jm) == nullptr){
      std::cout << "\nJump::initialize ERROR. Label " << jm << " is not in the Symbol Table. getData returned nullptr!";
      return;
    }
    else {
      loc = (sym->getData(jm))->location;
    }
    is_init = true;
    return;
  }
  else 
  {
    std::cout << "\ninitalize called on Jump but it has been initialized already: " << jm;
  }
}

Mul::Mul(){};
void Mul::printData(){
  std::cout << "Mul ";
};
void Mul::serialize(std::fstream &out){
  out << "Mul\n";
};

Jumpzero::Jumpzero(std::string jmp_z_): jmp_z(jmp_z_){};
void Jumpzero::printData(){
  std::cout<< "Jumpzero, " <<  jmp_z << ", (" << loc << ")\n";
};
void Jumpzero::serialize(std::fstream &out){
  out << "Jumpzero " << jmp_z << "\n";
};
void Jumpzero::initialize(Symtbl * sym){
  if (!is_init) {
    //uninitialized -> patch up
    if (sym->getData(jmp_z) == nullptr){
      std::cout << "\nJumpzero::initialize ERROR. Label " << jmp_z << " is not in the Symbol Table. getData returned nullptr!";
      return;
    }
    else {
      loc = (sym->getData(jmp_z))->location;
    }
    is_init = true;
    return;
  }
  else 
  {
    std::cout << "\ninitalize called on Jumpzero but it has been initialized already: " << jmp_z;
  }
}

Jump_n::Jump_n(std::string jmp_n_): jmp_n(jmp_n_){};
void Jump_n::printData(){
  std::cout << "JumpNZero " << jmp_n << ", (" << loc << ")\n";
};
void Jump_n::serialize(std::fstream &out){
  out << "JumpNZero " << jmp_n << "\n";
};
void Jump_n::initialize(Symtbl * sym){
  if (!is_init) {
    //uninitialized -> patch up
    if (sym->getData(jmp_n) == nullptr){
      std::cout << "\nJump_n::initialize ERROR. Label " << jmp_n << " is not in the Symbol Table. getData returned nullptr!";
      return;
    }
    else {
      loc = (sym->getData(jmp_n))->location;
    }
    is_init = true;
    return;
  }
  else 
  {
    std::cout << "\ninitalize called on Jump_n but it has been initialized already: " << jmp_n;
  }
}

gslabel::gslabel(std::string name_): name(name_){};
void gslabel::printData(){
  std::cout << "GoSubLabel " << name << "\n";
};
void gslabel::serialize(std::fstream &out){
  out << "GoSubLabel " << name << "\n";
};

//check this
Ret::Ret(){};
void Ret::printData(){
  std::cout << "Return\n" ;
};
void Ret::serialize(std::fstream &out){
  out << "Return\n";
};

//ENT SUB 
// Ent_sub::Ent_sub(std::string label_) : label(label_) {};
// void Ent_sub::printData(){
//   std::cout << "THIS SHOULDN'T BE PRINTED: FROM ENT_SUB " << label << "(" << mem << ")\n";
// };


GoSub::GoSub(std::string label_) : label(label_){};
void GoSub::printData(){
  std::cout << "GoSub " << label << "(" << loc << ")\n";
};
void GoSub::serialize(std::fstream &out){
  out << "GoSub " << label << "(" << loc << ")\n";
};
void GoSub::initialize(Symtbl * sym){
  if (!is_init) {
    //uninitialized -> patch up
    if (sym->getData(label) == nullptr){
      std::cout << "\nJump::initialize ERROR. Label " << label << " is not in the Symbol Table. getData returned nullptr!";
      return;
    }
    else {
      loc = (sym->getData(label))->location;
    }
    is_init = true;
    return;
  }
  else 
  {
    std::cout << "\ninitalize called on Jump but it has been initialized already: " << label;
  }
}


Start::Start(){};
void Start::printData(){
  std::cout << "Start " << mem << "\n";
};
void Start::serialize(std::fstream &out){
  out << "Start " << mem << "\n";
};
void Start::initialize(Symtbl * sym){
  mem = sym->getMemory("Global");
  is_init = true;
}
//check if this is pushed to inst_buff
Exit::Exit(){};
void Exit::printData(){
  std::cout << "Exit\n" ;
};
void Exit::serialize(std::fstream &out){
  out << "Exit\n";
};

Push_scl::Push_scl(std::string name_, Symtbl * sym) : name(name_)
{
  if (sym->getData(name) == nullptr){
      std::cout << "\nPush_scl::constructor ERROR. Label " << name << " is not in the Symbol Table. getData returned nullptr!";
      return;
    }
    else {
      loc = (sym->getData(name))->location;
    }
    is_init = true;
    return;
};
void Push_scl::printData(){
  std::cout << "PushScalar " << name << ", (" << loc << ")\n";
};
void Push_scl::serialize(std::fstream &out){
  out << "PushScalar " << name << ", (" << loc << ")\n";
};

Push_arr::Push_arr(std::string name_, int mem_) : name(name_), mem(mem_){};
void Push_arr::printData(){
  std::cout << "PushArray " << name << ", (" << mem <<")\n";
};
void Push_arr::serialize(std::fstream &out){
  out << "PushArray " << name << ", (" << mem <<")\n";
};

Push_i::Push_i(std::string i_) : i(i_){};
void Push_i::printData(){
  std::cout << "PushI  (" << i << ")\n";
};
void Push_i::serialize(std::fstream &out){
  out << "PushI  (" << i << ")\n";
};

Pop_scl::Pop_scl(std::string name_, Symtbl * sym): name(name_)
{
  if (sym->getData(name) == nullptr){
      std::cout << "\nPop_scl::constructor ERROR. Label " << name << " is not in the Symbol Table. getData returned nullptr!";
      return;
    }
    else {
      loc = (sym->getData(name))->location;
    }
    is_init = true;
    return;
};
void Pop_scl::printData(){
  std::cout << "PopScalar " << name << ", (" << loc << ")\n";
};
void Pop_scl::serialize(std::fstream &out){
  out << "PopScalar " << name << ", (" << loc << ")\n";
};

Pop_arr::Pop_arr(std::string name_): name(name_){};
void Pop_arr::printData(){
  std::cout<<"Pop_arr " << name << "\n";
};
void Pop_arr::serialize(std::fstream &out){
  out << "Pop_arr " << name <<"\n";
};

Pop::Pop(){};
void Pop::printData(){
  std::cout<<"Pop\n";
};
void Pop::serialize(std::fstream &out){
  out << "Pop\n";
};

Dup::Dup(){};
void Dup::printData(){
  std::cout << "Dup\n";
};

void Dup::serialize(std::fstream &out){
  out << "Dup\n";
};

Swap::Swap(){};
void Swap::printData(){
  std::cout << "Swap\n";
};
void Swap::serialize(std::fstream &out){
  out << "Swap\n";
};

Add::Add(){};
void Add::printData(){
  std::cout << "Add\n";
};
void Add::serialize(std::fstream &out){
  out << "Add\n";
};

Negate::Negate(){};
void Negate::printData(){
  std::cout << "Negate\n";
};
void Negate::serialize(std::fstream &out){
  out << "Negate\n";
};
Div::Div(){};
void Div::printData(){
  std::cout << "Div\n";
};
void Div::serialize(std::fstream &out){
  out << "Div\n";
};

Prints::Prints(std::string printed_): printed(printed_){};
void Prints::printData(){
  std::cout << "Prints " << printed << "\n";
};
void Prints::serialize(std::fstream &out){
  out << "Prints " << printed << "\n";
};
Printtos::Printtos(){};
void Printtos::printData(){
  std::cout << "PrintTOS\n";
};

void Printtos::serialize(std::fstream &out){
  out << "PrintTOS\n";
};