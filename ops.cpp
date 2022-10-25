#include "ops.h"

Jump::Jump(std::string jm_): jm(jm_){};

Mul::Mul(){};

Jumpzero::Jumpzero(std::string jmp_z_): jmp_z(jmp_z_){};

Jump_n::Jump_n(std::string jmp_n_): jmp_n(jmp_n_){};

gslabel::gslabel(std::string name_): name(name_){};

//check this
Ret::Ret(){};
//check this??????
Ent_sub::Ent_sub(std::string label_) : label(label_){};
//idk what to do here
Exit_sub::Exit_sub(){};

Start::Start(){};
//check if this is pushed to inst_buff
Exit::Exit(){};

Push_scl::Push_scl(std::string name_) : name(name_){};

Push_arr::Push_arr(std::string name_) : name(name_){};

Push_i::Push_i(std::string i_) : i(i_){};

Pop_scl::Pop_scl(std::string name_): name(name_){};

Pop_arr::Pop_arr(std::string name_): name(name_){};

Pop::Pop(){};

Dup::Dup(){};

Swap::Swap(){};

Add::Add(){};

Negate::Negate(){};

Div::Div(){};

Prints::Prints(std::string printed_): printed(printed_){};

Printtos::Printtos(){};
