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

private:
  bool createObj();
  bool checkSize();
  bool deleteObj();

};

#endif /* TESTER_H */
