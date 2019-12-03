#include "day1.h"
#include "controller.h"

float d1::sum_fuelReqs()
{
  std::cout << "sum_fuelReqs" << std::endl;
}

float d1::func12()
{
  std::cout << "func12" << std::endl;
}

void d1::day1()
{
  ctrlr::enumerateDayFunctions(d1::sum_fuelReqs, d1::func12);
}
