#ifndef TESTER_H
#define TESTER_H

#include "LinkedListOfInts.h"
#include <iostream>

class Tester
{
  //create object
  //test object created

  //check size
  //etc

  //destroy object
  //check deleted
public:
  Tester();
  void run();

  bool createObj();
  bool checkEmpty();
  bool checkAdds();
  bool checkRemoves();
  bool checkSize();
  bool checkSearch();

private:
  void printVector(std::vector<int> v);
};

#endif /* TESTER_H */
