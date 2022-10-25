#include "Symtbl.h"
//#include "ops.h"
#include "Stmt.h"
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
  regex arr("(declarr )(.*)+'\t'(.*)"); // check the \t for whitespace
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
    printf("in loop\n");

    if (line.compare("start") == 0) {
      // printf("start\n");
      inst_buff->buff.push_back(std::make_unique<Stmt>(23, false, -1, "none", "none", sym->getMemory(scope.front()),"none"));

    } else if (line.compare("end") == 0) {
      

      for(std::unique_ptr<Stmt> i : inst_buff->buff){
        if (!i->is_initialized){
          i->serialize(argv[2]);
        }
      }
    } 
    
    else if (line.compare("exit") == 0) {
      //EXIT Encountered. Calculate Memory and store it in the first element of the vector (OP_START)
      //Also fill in all jumps and gosubs
      int startmem = sym->getMemory("Global");
      inst_buff->buff.front()->mem = startmem;
      inst_buff->buff.front()->is_initialized = true;


      //patch up uninitialized statements
      for(std::unique_ptr<Stmt> i : inst_buff->buff){
        if (!i->is_initialized){
          i->initialize(sym);
        }
      }
      inst_buff->buff.push_back(std::make_unique<Stmt>(24, true, -1, "none", "none", -1, "none"));
      
    } 
    
    else if (line.compare("return") == 0) {
      // update the mem for sub_routine in the inst_buff and put return into
      inst_buff->buff.push_back(std::make_unique<Stmt>(20, true, -1, "none", "none", -1, "none"));
      
      for (std::vector<std::unique_ptr<Stmt>>::reverse_iterator i = inst_buff->buff.rbegin(); i != inst_buff->buff.rend(); i++){
        if (i->op_add == 19){
          i->is_initialized = true;
          i->mem = sym->getMemory(scope.front());
          break;
        }
      }
      
      //pop all the variables in the sub scope
      std::map<std::string, Data *>::iterator it;
    
      for (it = table.begin(); it != table.end(); it++) {
        if ((it->second)->scope == scope.front())
          table.erase(it);
      }
      
      //pop scope
      scope.pop_front();
    } 
      
    
    else if (line.compare("pop") == 0) {
      stmt * pop = new Pop(var)

      inst_buff->buff.push_back(pop));

    } 
    
    else if (line.compare("dup") == 0) {
      inst_buff->buff.push_back(std::make_unique<Stmt>(64,true, -1, "none", "none", -1, "none" ));

    } 
    
    else if (line.compare("swap") == 0) {
      inst_buff->buff.push_back(std::make_unique<Stmt>(65, true, -1, "none", "none", -1, "none"));

    } 
    
    else if (line.compare("add") == 0) {
      inst_buff->buff.push_back(std::make_unique<Stmt>(80,true, -1, "none", "none", -1, "none"));
      // inst_buff->buff.push_back(add);
    } 
    
    else if (line.compare("negate") == 0) {
      inst_buff->buff.push_back(std::make_unique<Stmt>(81,true, -1, "none", "none", -1, "none"));
      // inst_buff->buff.push_back(neg);
    } 
    
    else if (line.compare("mul") == 0) {
      inst_buff->buff.push_back(std::make_unique<Stmt>(82,true, -1, "none", "none", -1, "none"));
      // inst_buff->buff.push_back(mul);
    } 
    
    else if (line.compare("div") == 0) {
      inst_buff->buff.push_back(std::make_unique<Stmt>(83, true, -1, "none", "none", -1, "none"));
      // inst_buff->buff.push_back(div);
    } 
    
    else if (line.compare("printtos") == 0) {

      inst_buff->buff.push_back(std::make_unique<Stmt>(97, true, -1, "none", "none", -1, "none"));
      // inst_buff->buff.push_back(pts);
    } // from here on are the regex needed for matching
    
    else if(regex.match(line,prints)){
        string printer = line.substr(6,line.length());
      inst_buff->buff.push_back(std::make_unique<Stmt>(96,true, -1, "none", printer, -1, "none"));
        
    }
    
    else if (regex_match(line, scl)) {
      std::cout<<"\nDeslscal";
      Data *data = new Data(sym->table.size(), 1, false, scope.front());
      //data->print();

      string lab = line.substr(7, line.length());
      sym->putEntry(lab, data);
      // Save variable into Data with the current scope and is_label false

    } 
    
    else if (regex_match(line, arr)) {
      //need to modify this function 
      Data *arr;
      // need to filter regex to get just length
      
      string name = line.substr(7, 8);
      int size = stoi(line.substr(8, line.length()));
      
      Data *data = new Data(sym->table.size(), size, false, scope.front());
      sym->putEntry(name, data);
    } 
    
    else if (regex_match(line, lbl)) {
      //whenever we save label to the table the position in the
      //statement buffer is saved as opposed to memory
      string lab = line.substr(5, line.length());
      Data *data = new Data(sym->table.size(), 0, true, scope.front());
      data->print();
      sym->putEntry(lab, data);

      std::cout << "\nTEST. PRINTING TABLE:";
      sym->printTable();

    } 
    
    else if (regex_match(line, gsl)) {
      string gosub = line.substr(10, line.length());
      Data * data = new Data(sym->table.size(),0,true,scope.front());
      data->print();
      sym->putEntry(gosub, data);
      
    } 
    
    else if (regex_match(line, jmp)) {
      string jm = line.substr(4,line.length());

      inst_buff->buff.push_back(std::make_unique<Stmt>(16, false, -1, jm, "none", -1, "none" ));
      
    } 
    
    else if (regex_match(line, jmp_z)) {
      string jmpz = line.substr(8,line.length());
      inst_buff->buff.push_back(std::make_unique<Stmt>(17, false, -1, jmpz, "none", -1, "none"));
      // inst_buff->buff.push_back(jmpz);

    } 
    
    else if (regex_match(line, jmp_n)) {
      string jmpn = line.substr(9,line.length());
      inst_buff->buff.push_back(std::make_unique<Stmt>(18, false, -1, jmpz, "none", -1, "none"));
      // inst_buff->buff.push_back(jmpn);

    } 
    
    else if (regex_match(line, gs)) {
      // encountered Gosub. Change scope
      std::string label = line.substr(10, line.length());
      scope.push_front(label);

      inst_buff->buff.push_back(std::make_unique<Stmt>(19, false, -1, label, "none", -1, "none"));

    } 
    
    else if (regex_match(line, psh_scl)) {
      string scl = line.substr(8,line.length());
      inst_buff->buff.push_back(std::make_unique<Stmt>(32, true, sym->table.size(), "none","none", -1, "none"));
    

    } 
    
    else if (regex_match(line, psh_arr)) {
      string arr = line.substr(7,line.length());
      // need to do regex to find size 
      inst_buff->buff.push_back(std::make_unique<Stmt>(33, true, sym->table.size(), "none","none", -1, "none"));
    } 
    
    else if (regex_match(line, psh_i)) {
      printf("pushi\n");
      string psh_i = line.substr(5,line.length());
      inst_buff->buff.push_back(std::make_unique<Stmt>(34, true, -1, "none","none", -1, psh_i));

    } 
    
    else if (regex_match(line, pop_scl)) {
      printf("pop_scl\n");
      string pop_scl = line.substr(8,line.length());
      inst_buff->buff.push_back(std::make_unique<Stmt>(48, true, sym->table.size(), pop_scl,"none," -1, "none"));
      // inst_buff->buff.push_back(pop_scl);
    } 
    
    else if (regex_match(line, pop_arr)) {
      string pop_arr = line.substr(7,line.length());
      inst_buff->buff.push_back(std::make_unique<Stmt>(49, true, -1, pop_arr, "none", -1, "none"));
      // inst_buff->buff.push_back(pop_arr);
    }

    // did not match a command return an error command
    else {
      printf("line does not match any commands\n");
    }
  }
  // end of while

  return 0;
};