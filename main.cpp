#include <iostream>
#include <map> // using c++ dictionary

#include "controller.h"
#include "day1.h"
#include "day2.h"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << "day#\n";
    std::cout << "... where # is a number 1-25" << std::endl;
    return -1;
  }
  typedef void (*functionPtr)(); // define function pointer type
  std::map<std::string, functionPtr> functionMap;
  functionMap["day1"] = d1::day1;
  functionMap["day2"] = d2::day2;
  // ctrlr::chooseDay(argv[1]);
  // void(*functionPtr)() = d1::day1;
  // functionPtr = functionMap[ argv[1] ];
  // ctrlr::chooseDay(functionPtr());
  ctrlr::chooseDay(functionMap[ argv[1] ]);

  return 0;
}
