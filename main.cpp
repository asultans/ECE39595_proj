#include "Symtbl.h"
#include "buffers.h"
#include "ops.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
// need to add exit_subroutine op

// CHECK TO SEE IF WE HAVE ALL OP CODES TAKEN CARE OF

int main(int argc, char *argv[]) {

  // DECLARTIONS
  string line;
  fstream fl;
  Symtbl *sym = Symtbl::getSymbolTable();
  Inst_buff *inst_buff = Inst_buff::getInst_buff();
  Str_buff *str_buff = Str_buff::getStr_buff();
  
  // Instantiate Scope
  std::forward_list<std::string> scope;
  std::forward_list<std::string>::iterator it;
  scope.push_front("Global");

  // test if regex can handle edge cases
  regex scl("(declscal )(.*)+");
  regex arr("(declarr )(.*)+"); 
  regex lbl("(label )(.*)+");
  regex gsl("(gosublabel )(.*)+");
  regex jmp("(jump )(.*)+");
  regex jmp_z("(jumpzero )(.*)+");
  regex jmp_n("(jumpnzero )(.*)+");
  regex gs("(gosub )(.*)+");
  regex psh_scl("(pushscal )(.*)+");
  regex psh_arr("(pusharr )(.*)+");
  regex psh_i("(pushi )(.*)+");
  regex pop_scl("(popscal )(.*)+");
  regex pop_arr("(poparr )(.*)+");
  regex prints("(prints )(.*)+");
  // open file
  fl.open(argv[1]);
  
  // read line by line
  while (getline(fl, line)) {
    //printf("in loop\n");

    //START OPS.H ADDED
    if (line.compare("start") == 0) {
      Stmt * start = new Start();
      inst_buff->buff.push_back(start);

    } 
    //END OPS.H ADDED
    else if (line.compare("end") == 0) {

      // returns length of vector as unsigned int
      unsigned int buffSize = inst_buff->buff.size();
      for(unsigned int i = 0; i < buffSize; i++)
      {
        inst_buff->buff[i]->printData();
      }
      cout << endl;
      
      //DONT CREATE STMT
      //Reached END. PRINT SERIALIZE
      
      // for(Stmt * i : inst_buff->buff){
      //   if (!i->is_initialized){
      //     i->serialize(argv[2]);
      //   }
      // }
    } 

    else if (line.compare("exit") == 0) {
      Stmt * exit = new Exit();
      inst_buff->buff.push_back(exit);
      cout << inst_buff->buff.size();
      //EXIT Encountered. Calculate Memory and store it in the first element of the vector (OP_START)
      //Also fill in all jumps and gosubs
      // int startmem = sym->getMemory("Global");
      //inst_buff->buff.front()->mem = startmem;
      //inst_buff->buff.front()->is_initialized = true;


      //patch up uninitialized statements
      // for(std::unique_ptr<Stmt> i : inst_buff->buff){
      //   if (!i->is_initialized){
      //     i->initialize(sym);
      //   }
      // }
    } 
    
    else if (line.compare("return") == 0) {

      Stmt * ret = new Ret();
      inst_buff->buff.push_back(ret);
      // update the mem for sub_routine in the inst_buff and put return into
      inst_buff->buff.push_back(ret);
      
      // for (std::vector<std::unique_ptr<Stmt>>::reverse_iterator i = inst_buff->buff.rbegin(); i != inst_buff->buff.rend(); i++){
      //   if (i->op_add == 19){
      //     i->is_initialized = true;
      //     i->mem = sym->getMemory(scope.front());
      //     break;
      //   }
      // }
      
      //pop all the variables in the sub scope
      // std::map<std::string, Data *>::iterator it;
    
      // for (it = table.begin(); it != table.end(); it++) {
      //   if ((it->second)->scope == scope.front())
      //     table.erase(it);
      // }
      
      // //pop scope
      // scope.pop_front();
    } 
      
    
    else if (line.compare("pop") == 0) {
      Stmt * pop = new Pop();
      inst_buff->buff.push_back(pop);

    } 
    
    else if (line.compare("dup") == 0) {
      Stmt * dup = new Dup();
      inst_buff->buff.push_back(dup);

    } 
    
    else if (line.compare("swap") == 0) {
      Stmt * swap = new Swap();
      inst_buff->buff.push_back(swap);

    } 
    
    else if (line.compare("add") == 0) {
      Stmt * add = new Add();
      inst_buff->buff.push_back(add);

    } 
    
    else if (line.compare("negate") == 0) {
      
      Stmt * neg = new Negate();
      inst_buff->buff.push_back(neg);
    } 
    
    else if (line.compare("mul") == 0) {
      Stmt * mul = new Mul();
      inst_buff->buff.push_back(mul);
    } 
    
    else if (line.compare("div") == 0) {
      Stmt * div = new Div();
      inst_buff->buff.push_back(div);
      
    } 
    
    else if (line.compare("printtos") == 0) {
      Stmt * printtos = new Printtos();
      inst_buff->buff.push_back(printtos);
      
    } // from here on are the regex needed for matching
    
    else if (regex_match(line,prints)){
      
      string printval = line.substr(6,line.length());
      Stmt * print = new Prints(printval);
      inst_buff->buff.push_back(print);
        
    }
    
    else if (regex_match(line, scl)) {
      //DECLSCAL
      // Save variable into Data with the current scope and is_label false
      
      //data->print();

      string var = line.substr(7, line.length());
      sym->putEntry(var, new Data(-1, 1, false, scope.front()));
      

    } 
    
    // Need to figure out how to do this!!!!!
    else if (regex_match(line, arr)) {  
      // string name = line.substr(7, 8);
      // int size = stoi(line.substr(8, line.length()));
      
      // Data *data = new Data(-1, size, false, scope.front());
      // sym->putEntry(name, data);
    } 
      
    else if (regex_match(line, lbl)) {
      //whenever we save label to the table the position in the
      //statement buffer is saved as opposed to memory
      
      string lbl = line.substr(5, line.length());
      Data *data = new Data(inst_buff->buff.size() + 1, 0, true, scope.front());
      sym->putEntry(lbl, data);

      std::cout << "\nTEST. PRINTING TABLE:______";
      sym->printTable();
      std::cout << "END TEST. PRINT TABLE\n\n";

    } 
    else if (regex_match(line, gsl)) {
      // string gosub = line.substr(10, line.length());
      // Data * data = new Data(getStatementLine, 0, true, scope.front());
      // data->print();
      // sym->putEntry(gosub, data);
      
    } 
    
    else if (regex_match(line, jmp)) {
      string jm = line.substr(4,line.length());
      Stmt * jump = new Jump(jm);
      inst_buff->buff.push_back(jump);
      
    } 
    
    else if (regex_match(line, jmp_z)) {
      string jmpz = line.substr(8,line.length());
      Stmt * jump_z = new Jumpzero(jmpz);
      inst_buff->buff.push_back(jump_z);
      

    } 
    
    else if (regex_match(line, jmp_n)) {
      string jmpn = line.substr(9,line.length());
      Stmt * jmp = new Jump_n(jmpn); 
      inst_buff->buff.push_back(jmp);
      
      

    } 
    
    else if (regex_match(line, gs)) {
      // encountered Gosub. CHANGE SCOPE.
      std::string label = line.substr(10, line.length());
      Stmt * go = new Ent_sub(label);
      inst_buff->buff.push_back(go);

    } 
    
    else if (regex_match(line, psh_scl)) {
      string scl = line.substr(8,line.length());
      Stmt * psh_sl = new Push_scl(scl); 
      inst_buff->buff.push_back(psh_sl);
    

    } 
    
    else if (regex_match(line, psh_arr)) {
      // need to also get the mem amount 
      string name = line.substr(8,9);
      int mem = stoi(line.substr(9,line.length()));
      Stmt * psh_a = new Push_arr(name, mem);
      
      // need to do regex to find size 
      
      inst_buff->buff.push_back(psh_a);
      
      } 
    
    else if (regex_match(line, psh_i)) {
      //printf("pushi\n");
      string i = line.substr(5,line.length());
      Stmt * push_i = new Push_i(i);
      inst_buff->buff.push_back(push_i);

    } 
    
    else if (regex_match(line, pop_scl)) {
      printf("pop_scl\n");
      string var = line.substr(8,line.length());
      Stmt * pop_scal = new Pop_scl(var);
      inst_buff->buff.push_back(pop_scal);
      // inst_buff->buff.push_back(pop_scl);
    } 
    
    else if (regex_match(line, pop_arr)) {
      
      string var = line.substr(7,line.length());
      Stmt * pop_arr = new Pop_arr(var);
      inst_buff->buff.push_back(pop_arr);

    }

    // did not match a command return an error command
    else {
      printf("line does not match any commands\n");
    }
  }
  // end of while

  return 0;
};