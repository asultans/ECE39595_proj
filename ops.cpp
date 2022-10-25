#include "ops.h"

Jump::Jump(std::string jm_): jm(jm_){};
void Jump::printData(){
  std::cout << "Jump " << jm << "\n";
};
Mul::Mul(){};

Jumpzero::Jumpzero(std::string jmp_z_): jmp_z(jmp_z_){};
void Jumpzero::printData(){
  std::cout<< "Jumpzero " <<  jmp_z << "\n";
};
    
Jump_n::Jump_n(std::string jmp_n_): jmp_n(jmp_n_){};
void Jump_n::printData(){
  std::cout << "JumpNZero " << jmp_n << "\n";
};

gslabel::gslabel(std::string name_): name(name_){};
void gslabel::printData(){
  std::cout << "GoSubLabel " << name << "\n";
};

//check this
Ret::Ret(){};
void Ret::printData(){
  std::cout << "Return\n" ;
};

//check this??????
Ent_sub::Ent_sub(std::string label_) : label(label_){};
void Ent_sub::printData(){
  std::cout << "Enter Go Sub " << label << "\n";
};

Start::Start(){};
void Start::printData(){
  std::cout << "Start " << mem << "\n";
};
//check if this is pushed to inst_buff
Exit::Exit(){};
void Exit::printData(){
  std::cout << "Exit" ;
};
Push_scl::Push_scl(std::string name_) : name(name_){};
void Push_scl::printData(){
  std::cout << "Push_scl " << name << "\n";
};


Push_arr::Push_arr(std::string name_, int loc_) : name(name_), loc(loc_){};
void Push_arr::printData(){
  std::cout << "PushArray " << name << ", (" << loc <<")\n";
};

Push_i::Push_i(std::string i_) : i(i_){};
void Push_i::printData(){
  std::cout << "PushI " << i<< "\n";
};

Pop_scl::Pop_scl(std::string name_): name(name_){};
void Pop_scl::printData(){
  std::cout << "Pop_scl " << name << "\n";
};

Pop_arr::Pop_arr(std::string name_): name(name_){};
void Pop_arr::printData(){
  std::cout<<"Pop_arr " << name << "\n";
};

Pop::Pop(){};
void Pop::printData(){
  std::cout<<"Pop\n";
};

Dup::Dup(){};
void Dup::printData(){
  std::cout << "Dup\n";
};

Swap::Swap(){};
void Swap::printData(){
  std::cout << "Swap\n";
};

Add::Add(){};
void Add::printData(){
  std::cout << "Add\n";
};

Negate::Negate(){};
void Negate::printData(){
  std::cout << "Negate\n";
};

Div::Div(){};
void Div::printData(){
  std::cout << "Div\n";
};

Prints::Prints(std::string printed_): printed(printed_){};
void Prints::printData(){
  std::cout << "Print " << printed << "\n";
};

Printtos::Printtos(){};
void Printtos::printData(){
  std::cout << "PrintTOS\n";
};