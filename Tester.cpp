#include "Tester.h"
#include <iostream>

Tester::Tester(){
}

void Tester::run(){
  //execute test calls
  std::cout << "Starting object creation test...\n";
  if(createObj())
    std::cout << "Passed object creation test.\n\n";
  else
    std::cout << "Failed object creation test.\n\n";

  std::cout << "Starting size test...\n";
  if(checkEmpty())
    std::cout << "Passed size test.\n\n";
  else
    std::cout << "Failed size test.\n\n";

  std::cout << "Starting addition test...\n";
  if(checkAdds())
    std::cout << "Passed addition test.\n\n";
  else
    std::cout << "Failed addition test.\n\n";

  std::cout << "Starting removal test...\n";
  if(checkRemoves())
    std::cout << "Passed removal test.\n\n";
  else
    std::cout << "Failed removal test.\n\n";

  std::cout << "Starting size test...\n";
  if(checkSize())
    std::cout << "Passed size test.\n\n";
  else
    std::cout << "Failed size test.\n\n";

  std::cout << "Starting search test...\n";
  if(checkSize())
    std::cout << "Passed search test.\n\n";
  else
    std::cout << "Failed search test.\n\n";
}


bool Tester::createObj(){
  std::vector<int> comparisonVector(0);
  LinkedListOfInts list;

  if(list.toVector() != comparisonVector){
    std::cout << "Error: list was not empty at initialization\n";
    std::cout << "The vector we were expecting:\n";
    printVector(comparisonVector);
    std::cout << "The vectorized list:\n";
    printVector(list.toVector());
    return false;
  }

  return true;
}

bool Tester::checkEmpty(){
  LinkedListOfInts list;
  //check if empty

  bool flag = true;
  if(!list.isEmpty()){
    std::cout << "Error: isEmpty() should return true for a newly created list\n";
    flag = false;
    std::cout << "Error: size() should return zero for a newly created list\n";
    flag = false;
  }

  return flag;
}

bool Tester::checkAdds(){
  bool flag = true;

  std::vector<int> comparisonVector(3);
  comparisonVector[0] = -10;
  comparisonVector[1] = 0;
  comparisonVector[2] = 5;

  LinkedListOfInts list1;
  list1.addFront(5);
  list1.addFront(0);
  list1.addFront(-10);
  if(list1.toVector() != comparisonVector){
    std::cout << "Error: addFront not adding integers to the front of the list.\n";
    std::cout << "The vector we were expecting:\n";
    printVector(comparisonVector);
    std::cout << "The vectorized list:\n";
    printVector(list1.toVector());
    flag = false;
  }

  comparisonVector[0] = 456;
  comparisonVector[1] = 0;
  comparisonVector[2] = -1045;

  LinkedListOfInts list2;
  list2.addBack(456);
  list2.addBack(0);
  list2.addBack(-1045);
  if(list2.toVector() != comparisonVector){
    std::cout << "Error: addBack not adding integers to the back of the list.\n";
    std::cout << "The vector we were expecting:\n";
    printVector(comparisonVector);
    std::cout << "The vectorized list:\n";
    printVector(list2.toVector());
    flag = false;
  }

  return flag;
}

bool Tester::checkRemoves(){
  bool flag = true;

  std::vector<int> comparisonVector(1);
  comparisonVector[0] = 1;

  LinkedListOfInts list1;
  list1.addFront(1);
  list1.addFront(5);
  bool rf = list1.removeFront();
  if(list1.toVector() != comparisonVector){
    if(rf)
      std::cout << "Error: removeFront returns true but does not remove an integer from the front of the list.\n";
    else
      std::cout << "Error: removeFront does not remove an integer from the front of the list.\n";
    std::cout << "The vector we were expecting:\n";
    printVector(comparisonVector);
    std::cout << "The vectorized list:\n";
    printVector(list1.toVector());
    flag = false;
  }
  else if (!rf){
    std::cout << "Error: removeFront returns false on a non-empty list\n";
    flag = false;
  }

  comparisonVector[0] = 5;

  LinkedListOfInts list2;
  list2.addFront(1);
  list2.addFront(5);
  bool rb = list2.removeBack();
  if(list2.toVector() != comparisonVector){
    if(rb)
      std::cout << "Error: removeBack returns true but does not remove an integer from the back of the list.\n";
    else
      std::cout << "Error: removeBack does not remove an integer from the back of the list.\n";
    std::cout << "The vector we were expecting:\n";
    printVector(comparisonVector);
    std::cout << "The vectorized list:\n";
    printVector(list2.toVector());
    flag = false;
  }
  else if (!rb){
    std::cout << "Error: removeBack returns false on a non-empty list\n";
    flag = false;
  }

  return flag;
}

bool Tester::checkSize(){
  LinkedListOfInts list;

  for(int i=0; i < 10; i++){
    list.addFront(i*i);
    if(list.size() != (i+1)){
      std::cout << "Error: size did not return the expected value after ";
      std::cout << (i+1);
      std::cout << " addFronts\n";
      return false;
    }
  }

  return true;
}

bool Tester::checkSearch(){
  LinkedListOfInts list;

  for(int i=0; i < 10; i++)
    list.addFront(i*i);

  for(int i=0; i < 10; i++)
    if(!list.search(i*i)){
      std::cout << "Error: search did not find a value expected to be in the list\n";
      std::cout << "The number searched: ";
      std::cout << i*i;
      std::cout << "The vectorized list being searched:\n";
      printVector(list.toVector());
      return false;
    }


  return true;
}

void Tester::printVector(std::vector<int> v){
  std::cout << "{ ";
  for(int i=0; i < v.size(); i++){
    std::cout << v[i];
    if(i != (v.size() - 1))
      std::cout << " , ";
  }
  std::cout << " }\n";
}
