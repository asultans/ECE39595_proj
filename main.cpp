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
#include <forward_list>


using namespace std;
// need to add exit_subroutine op

// CHECK TO SEE IF WE HAVE ALL OP CODES TAKEN CARE OF

int main(int argc, char *argv[]) {

  // DECLARTIONS
  string line;
  fstream fl;
  fstream out;
  Symtbl *sym = Symtbl::getSymbolTable();
  Inst_buff *inst_buff = Inst_buff::getInst_buff();
  Str_buff *str_buff = Str_buff::getStr_buff();
  
  // Instantiate Scope
  std::forward_list<std::string> scope;
  scope.push_front("Global");

  // Instantiate GoSubTracker
  std::forward_list<Stmt *> gstrack;
  
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
  out.open(argv[2]);
  // read line by line
  while (getline(fl, line)) {
    //printf("in loop\n");

    if (line.compare("start") == 0) {
      Stmt * start = new Start();
      start->is_init = false;
      inst_buff->buff.push_back(start);

    } 
    
    else if (line.compare("end") == 0) {
      //patch up all statements with undefined operands
      unsigned int buffSize = inst_buff->buff.size();
      for(unsigned int i = 0; i < buffSize; i++)
      {
        inst_buff->buff[i]->initialize(sym);
      }
      cout << endl;
      
      for(unsigned int i = 0; i < buffSize; i++)
      {
        inst_buff->buff[i]->printData();
        //inst_buff->buff[i]->serialize(out);
      }
      cout << endl;

      
      /* TESTING Symbol Table Contents */
      std::cout << "\n_____TEST. PRINTING SYMBOL TABLE:______";
      sym->printTable();
      std::cout << "_____END TEST. PRINT TABLE______\n\n";
    } 

    else if (line.compare("exit") == 0) {
      //cout << "JWHDBCUHW";
      Stmt * exit = new Exit();
      inst_buff->buff.push_back(exit);
      
      // cout << "\nINSTR_BUFF SIZE: " << inst_buff->buff.size() << endl;
      // //EXIT Encountered. Calculate Memory and store it in the first element of the vector (OP_START)
      // //Also fill in all jumps and gosubs
      // int startmem = sym->getMemory("Global");
      // (dynamic_cast<Start*> (inst_buff->buff.front()))->mem = startmem;
      // cout << "JWHskvjbnadsfjkbvnlkjadbmDBCUHW";
      // for (auto & element : inst_buff->buff) 
      // {
      //   if (element->getOp() == 19){
      //     //GOSUB
      //     cout << "PRINT\n\n\n";
      //     Data * data = sym->getData((dynamic_cast<GoSub*>(element))->label);
      //     (dynamic_cast<GoSub*>(element))->loc = data->location;
      //   }
      //   if (element->getOp() == 16){
      //     //JUMP
      //     Data * data = sym->getData((dynamic_cast<Jump*>(element))->jm);
      //     (dynamic_cast<Jump*>(element))->loc = data->location;
      //   }
        
      // }

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

      //return to the old scope
      scope.pop_front();
      }  
      

      
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
      
      string printval = line.substr(7,30);
      Stmt * print = new Prints(printval);
      inst_buff->buff.push_back(print);
        
    }
    
    else if (regex_match(line, scl)) {
      //DECLSCAL
      // Save variable into Data with the current scope and is_label false
      
      //data->print();

      string var = line.substr(9, 2);
      if (!sym->putEntry(var, new Data(-1, 1, false, scope.front()))){
        //insert failed because the same entry key already exsits.
        // check if the scope is the same
        if (sym->getData(var)->scope == scope.front()){
          cout << "\nError: trying to insert a variable with the same name in the same scope. Var Name: " << var << "\nScope: " << scope.front();
        }
        else {
          //scope is different. insert by appending scope name
          sym->putEntry(var + "_" + scope.front(), new Data(-1, 1, false, scope.front()));
        }
      }
      

    } 
    
    // Need to figure out how to do this!!!!!
    else if (regex_match(line, arr)) {  

      
      string name = line.substr(8, 1);
      
      int mem = stoi(line.substr(9, 2));
      
      Data *data = new Data(-1, mem, false, scope.front());
      if (!sym->putEntry(name, data)){
        cout<<"Shit didn't work. Put Entry ARR";
      }
    } 
      
    else if (regex_match(line, lbl)) {
      //whenever we save label to the table the position in the
      //statement buffer is saved as opposed to memory
      
      string lbl = line.substr(6, 10);
      Data *data = new Data(inst_buff->buff.size(), 0, true, scope.front());
      sym->putEntry(lbl, data);

      

    } 
    else if (regex_match(line, gsl)) {
      string label = line.substr(11, 10);
      //save to symbol table
      Data * data = new Data(inst_buff->buff.size(), 0, true, scope.front());
      Stmt * goSubLabel = new gslabel(label);
      inst_buff->buff.push_back(goSubLabel);
      sym->putEntry(label, data);
      //change the scope to the new label
      scope.push_front(label);
    } 
    
    else if (regex_match(line, jmp)) {
      string jm = line.substr(5,10);
      Stmt * jump = new Jump(jm);
      jump->is_init = false;
      inst_buff->buff.push_back(jump);
      
    } 
    
    else if (regex_match(line, jmp_z)) {
      string jmpz = line.substr(9,10);
      Stmt * jump_z = new Jumpzero(jmpz);
      jump_z->is_init = false;
      inst_buff->buff.push_back(jump_z);
      

    } 
    
    else if (regex_match(line, jmp_n)) {
      string jmpn = line.substr(10,10);
      Stmt * jmp = new Jump_n(jmpn); 
      jmp->is_init = false;
      inst_buff->buff.push_back(jmp);
      
      

    } 
    
    else if (regex_match(line, gs)) {
      // encountered Gosub. DONT change the scope.
      std::string label = line.substr(6, 2);
      Stmt * goSub = new GoSub(label);
      goSub->is_init = false;
      inst_buff->buff.push_back(goSub);

      //gstracker.push_front(goSub);
    } 
    
    else if (regex_match(line, psh_scl)) {
      string scl = line.substr(9,10);
      //check if we are in a subroutine
      if (scope.front() == "Global") {
        //Not in a subroutine. Nothing new
        Stmt * psh_sl = new Push_scl(scl, sym); 
        inst_buff->buff.push_back(psh_sl);
      }
      else {
        //we are in a subroutine. Append scope to variable search
        Stmt * psh_sl = new Push_scl(scl + "_" + scope.front(), sym);
        inst_buff->buff.push_back(psh_sl);
      }
    } 
    
    else if (regex_match(line, psh_arr)) {
      // need to also get the mem amount 
      string name = line.substr(8,9);
      int mem = stoi(line.substr(9,2));
      Stmt * psh_a = new Push_arr(name, mem);
      
      // need to do regex to find size 
      
      inst_buff->buff.push_back(psh_a);
      
      } 
    
    else if (regex_match(line, psh_i)) {
      string i = line.substr(6,1);
      Stmt * push_i = new Push_i(i);
      inst_buff->buff.push_back(push_i);

    } 
    
    else if (regex_match(line, pop_scl)) {
      string var = line.substr(8,2);
      //check if we are in a subroutine
      if (scope.front() == "Global") {
        //Not in a subroutine. Nothing new
        Stmt * pop_scal = new Pop_scl(var, sym);
        inst_buff->buff.push_back(pop_scal);
      }
      else {
        //we are in a subroutine. Append scope to variable search
        Stmt * pop_scal = new Pop_scl(var + "_" + scope.front(), sym);
        inst_buff->buff.push_back(pop_scal);
      }
      
      
      
    } 
    
    else if (regex_match(line, pop_arr)) {
      
      string var = line.substr(7,2);
      Stmt * pop_arr = new Pop_arr(var);
      inst_buff->buff.push_back(pop_arr);

    }

    // did not match a command return an error command
    else {
      printf("line does not match any commands\n");
      
    }
  }
  // end of while
  out.close();
  fl.close();
  return 0;
};