#include "Tester.h"
#include <iostream>

Tester::Tester(){
  //nothing?
}

void Tester::run(){
  //execute test calls
  if(createObj())
    std::cout << "Passed object creation test\n\n";
  else
    std::cout << "Failed object creation test\n\n";

  if(checkSize())
    std::cout << "Passed size test\n\n";
  else
    std::cout << "Failed size test\n\n";
}

bool Tester::createObj(){
  LinkedListOfInts list;

  // if(list == NULL){
  //   std::cout << "Error: new list object returns NULL";
  //   return false;
  // }

  return true;
}

bool Tester::checkSize(){
  LinkedListOfInts list;
  //check if empty

  bool flag = true;
  if(!list.isEmpty()){
    std::cout << "Error: isEmpty() should return true for a newly created list\n";
    flag = false;
  }
  if(list.size() != 0){
    std::cout << "Error: size() should return zero for a newly created list\n";
    flag = false;
  }

  //check after adding to list
  list.addFront(5);
  if(list.size() != 1){
    std::cout << "Error: failure on addFront(5)\n\tsize() should return 1, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  list.addFront(0);
  if(list.size() != 2){
    std::cout << "Error: failure on addFront(0)\n\tize() should return 2, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  list.addFront(-10);
  if(list.size() != 3){
    std::cout << "Error: failure on addFront(-10)\n\tsize() should return 3, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  list.addBack(456);
  if(list.size() != 4){
    std::cout << "Error: failure on addBack(456)\n\tsize() should return 4, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  list.addBack(0);
  if(list.size() != 5){
    std::cout << "Error: failure on addBack(0)\n\tsize() should return 5, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  list.addBack(-1045);
  if(list.size() != 6){
    std::cout << "Error: failure on addBack(-1045)\n\tsize() should return 6, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }

  //check after removing from list
  if(!list.removeBack()){
    std::cout << "Error: failure on removeBack()\n\treturned false when the size is ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  else if(list.size() != 5){
    std::cout << "Error: failure on removeBack()\n\tsize() should return 5, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  if(!list.removeFront()){
    std::cout << "Error: failure on removeBack()\n\treturned false when the size is ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }
  else if(list.size() != 4){
    std::cout << "Error: failure on removeFront()\n\tsize() should return 4, it returned ";
    std::cout << list.size();
    std::cout << "\n";
    flag = false;
  }

  return flag;
}

bool Tester::deleteObj(){
  return true;
}
