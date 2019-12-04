#include "day1.h"
#include "controller.h"
#include "helpers.h"

#include <vector>
#include <fstream> // using file IO
#include <math.h> // using 'floor'

float d1::sum_fuelReqs()
{ // sum fuel requirements
  std::cout << "sum_fuelReqs" << std::endl;
  std::ifstream file = helper::openFile(1, 1);
  int mass;
  int totalMass = 0;

  while(file >> mass)
  {
    std::cout << mass << std::endl;
    totalMass += floor(mass/3) - 2;
    std::cout << "-> " << totalMass << std::endl;
  }
  file.close();

  std::cout << totalMass << std::endl;

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
