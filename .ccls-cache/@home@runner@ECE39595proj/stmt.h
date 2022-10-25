#include <iostream>
#include <forward_list>
#include <fstream>
#include <string>

class Stmt {
     
  public:
      //variables
      std::forward_list<std::string> scope;
      std::forward_list<std::string>::iterator it;
  
      //functions
      virtual std::string getScope() { return scope.front(); };
  
      //pure virtual functions:
      /* SERIALIZE will write the object to a file in
      sequential order. This file will have a .out file type */
      virtual void serialize(std::ofstream aout_file) = 0; 
};