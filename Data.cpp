#include "Data.h"
#include "iostream"
#include <string>

Data::Data(int location_, int length_, bool is_label_, std::string scope_) 
  : location(location_), length(length_), is_label(is_label_), scope(scope_) {};

Data::~Data(){}

void Data::print(){
  std::string printres = "\n<" + std::to_string(location) + ", " + std::to_string(length) + ">\nIs it label? " + std::to_string(is_label) + "\nScope: " + (scope) + "\n";
  std::cout << printres;
}