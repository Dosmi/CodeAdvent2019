#include "day1.h"
#include "controller.h"
#include "helpers.h"

#include <vector>

float d1::sum_fuelReqs()
{
  std::cout << "sum_fuelReqs" << std::endl;
  helper::openFile(1, 1);
}

float d1::func12()
{
  std::cout << "func12" << std::endl;
}

void d1::day1()
{
  std::vector<void *(*)(void *)> functionPointers;
  functionPointers.push_back((void *(*)(void *))d1::sum_fuelReqs);
  functionPointers.push_back((void *(*)(void *))d1::func12);

  ctrlr::enumerateDayFunctions(functionPointers);
}
