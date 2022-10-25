#ifndef DATA_H
#define DATA_H

#include <forward_list>
#include <string>

class Data {
public:
  // variables
  int location;
  int length;
  bool is_label;
  std::string scope;

  Data(int location_, int length_, bool is_label_, std::string scope);
  ~Data();
  void print();
};
#endif