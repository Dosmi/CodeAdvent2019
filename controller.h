#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <vector>

namespace ctrlr
{
  void chooseDay(void(*day)());

  template<typename T>
  void enumerateDayFunctions(std::vector<T> allFunctions)
  {
    for(unsigned int i = 1; i <= allFunctions.size(); i++)
    {
      std::cout << i << std::endl;
    }

    int funcNum;
    std::cout << "Choose the function number: " << std::endl;
    std::cin  >> funcNum;

    // allFunctions[funcNum]();
    ( (int (*)(int))allFunctions[funcNum-1]) (2);        // The value of b is 2.

    // if (funcNum == 1) func1();
    // else func2();

  }
}
#endif // end of defining CONTROLLER_H
