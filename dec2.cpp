#include "day2.h"
#include "controller.h"
#include "helpers.h"

#include <vector>
#include <sstream>

#include <math.h> // using 'floor'

int d2::runINTCodeProgram(std::ifstream file, int noun, int verb)
{
  std::string line; // line of the file

  std::vector<std::string> parsedProgram;
  std::vector<int> intcodeProgram;

  while(std::getline(file, line))
  {
    // std::cout << "line: '" << line << "'" << std::endl;
    std::stringstream lineStream(line);

    parsedProgram = helper::split(line, ',');

    for(std::string opcode : parsedProgram)
    {
      std::cout << opcode << ", ";
      intcodeProgram.push_back(std::stoi(opcode));
    }
    std::cout << std::endl;
    // totalMass += floor(mass/3) - 2;
    // std::cout << "-> " << totalMass << std::endl;
  }
  file.close();

  std::cout << "IntCode Program Parsed:\n";
  int position = 0;
  for(int opcode : intcodeProgram)
  {
    std::cout << position << ") "<< opcode << "\n";
    position++;
  }

  std::cout << "noun: " << noun << "\n";
  std::cout << "verb: " << verb << "\n";
  intcodeProgram[1] = noun;
  intcodeProgram[2] = verb;

  std::cout << "\n\nExecuting the program ... " << std::endl;
  int value = -1; // value where we will hold the output result
  int index = 0;
  int currentOPcode = intcodeProgram[index];
  while(currentOPcode != 99)
  {
    switch (currentOPcode)
    {
      case 1:
        value = intcodeProgram[intcodeProgram[index+1]] + intcodeProgram[intcodeProgram[index+2]];
        intcodeProgram[intcodeProgram[index+3]] = value;
        break;

      case 2:
        value = intcodeProgram[intcodeProgram[index+1]] * intcodeProgram[intcodeProgram[index+2]];
        intcodeProgram[intcodeProgram[index+3]] = value;
        break;

      default:
        std::cout << "Unexpected OPcode: " << currentOPcode << std::endl;
        return 0;

    }
    index += 4;
    std::cout << index << "->" << intcodeProgram[index] << std::endl;
    currentOPcode = intcodeProgram[index];

  }

  std::cout << "\n\nOutput ... " << std::endl;
  position = 0;
  for(int opcode : intcodeProgram)
  {
    std::cout << position << ") "<< opcode << "\n";
    position++;
  }

  return intcodeProgram[0];

}

int d2::restoreGAP()
{ // sum fuel requirements
  std::cout << "restoreGAP" << std::endl;
  // std::ifstream file = helper::openFile(2, 1);

  int output = d2::runINTCodeProgram(helper::openFile(2, 1), 12, 2);
  std::cout << "[0] = " << output << std::endl;

  return 1;
}

int d2::produceOutput()
{
  int getOutput = 19690720;
  int output = 0;

  while (output != getOutput)
  {
    for (int noun = 0; noun <= 99; noun++)
    {
      for (int verb = 0; verb <= 99; verb++)
      {
        output = d2::runINTCodeProgram(helper::openFile(2, 1), noun, verb);
        if (output == getOutput)
        {
          std::cout << noun*100+verb;
          return noun*100+verb;
        }
      }
    }
  }
  return -1;
}

void d2::day2()
{
  std::vector<void* (*) (void*)> functionPointers;
  functionPointers.push_back( (void* (*)(void*) )d2::restoreGAP);
  functionPointers.push_back( (void* (*)(void*) )d2::produceOutput);

  ctrlr::enumerateDayFunctions(functionPointers);
}
