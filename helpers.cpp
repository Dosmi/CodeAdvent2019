#include "helpers.h"

#include <filesystem>
#include <iostream>
#include <fstream>

std::string helper::addPath(int dayNum, int taskNum)
{
  // namespace fs = std::filesystem;
  std::string foundFilename = "null";
  // get current working directory:
  std::string cwd = std::filesystem::current_path().string();

  std::string path = cwd + "/inputs/day" + std::to_string(dayNum);
  for (const auto& entry : std::filesystem::directory_iterator(path))
    std::cout << entry.path() << std::endl;

  return foundFilename;
}

bool helper::fileExists(std::string fullPath)
{
  return 0;
}

void helper::openFile(int dayNum, int taskNum)
{
  std::ifstream file;
  // get the full file path for the chosen day and task:
  std::string fullFilePath = helper::addPath(dayNum, taskNum);




}

void helper::closeFile(int dayNum, int taskNum)
{

}
