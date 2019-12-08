#include "day1.h"
#include "controller.h"
#include "helpers.h"

#include <vector>
#include <fstream> // using file IO
#include <math.h> // using 'floor'

int d1::sum_fuelReqs()
{ // sum fuel requirements
  std::cout << "sum_fuelReqs" << std::endl;
  std::ifstream file = helper::openFile(1, 1);
  int mass;
  int totalMass = 0;

  while(file >> mass)
  {
    // std::cout << mass << std::endl;
    totalMass += floor(mass/3) - 2;
    // std::cout << "-> " << totalMass << std::endl;
  }
  file.close();

  std::cout << "mass of fuel needed: " << totalMass << std::endl;

  return totalMass;

}

int d1::additionalFuel()
{
  std::cout << "func12" << std::endl;
  // int totalMass = d1::sum_fuelReqs();
  std::ifstream file = helper::openFile(1, 1);
  int mass;
  int totalMass = 0;

  while(file >> mass)
  {
    int additionalFuelMass = floor(mass/3) - 2;

    while(additionalFuelMass > 0)
    {
      std::cout << additionalFuelMass << std::endl;
      totalMass += additionalFuelMass;
      additionalFuelMass = floor(additionalFuelMass/3) - 2;
    }
  }

  std::cout << "additional fuel to carry the additional fuel: " \
            << totalMass << std::endl;
  return totalMass;

}

void d1::day1()
{
  std::vector<void *(*)(void *)> functionPointers;
  functionPointers.push_back((void *(*)(void *))d1::sum_fuelReqs);
  functionPointers.push_back((void *(*)(void *))d1::additionalFuel);

  ctrlr::enumerateDayFunctions(functionPointers);
}
