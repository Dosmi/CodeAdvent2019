#include <iostream>

#include "controller.h"
#include "day1.h"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << "dec#\n";
    std::cout << "... where # is a number 1-25" << std::endl;
    return -1;
  }

  // ctrlr::chooseDay(argv[1]);
  void(*functionPtr)() = d1::day1;
  ctrlr::chooseDay(functionPtr);


  return 0;
}
