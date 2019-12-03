#include "controller.h"
#include "day1.h"

// template<typename T>
// void enumerateDayFunctions(T func1, T func2)
// {
//   for(unsigned int i = 1; i <= 2; i++)
//   {
//     std::cout << i << std::endl;
//   }
//
//   int funcNum;
//   std::cout << "Choose the function number: " << std::endl;
//   std::cin  >> funcNum;
//
//   if (funcNum == 1) func1();
//   else func2();
//
// }

void ctrlr::chooseDay(void(*day)())
{
  day();
}
