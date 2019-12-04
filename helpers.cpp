#include "helpers.h"

#include <filesystem> // used for getting files in directory, getting cwd
#include <iostream>
#include <fstream>
#include <sstream> // used for parsing a string, combined with getline()

std::vector<std::string> helper::split(std::string str, char delimiter)
{
  // populate the list and return it
  std::vector<std::string> list;
  // save parts in between delimiters to a token
  std::string token;
  // input stream ( getline(stream, string_to_store_into, delimiter) )
  std::stringstream ss(str);

  while(std::getline(ss, token, delimiter))
  {
    list.push_back(token);
  }

  return list;
}

std::string helper::addPath(int dayNum, int taskNum)
{
  // namespace fs = std::filesystem;
  std::string foundFilename = "null";
  // get current working directory:
  std::string cwd = std::filesystem::current_path().string();
  // list of string split by delimiter
  std::vector<std::string> tokens;

  std::string path = cwd + "/inputs/day" + std::to_string(dayNum);
  for (const auto& entry : std::filesystem::directory_iterator(path))
  {
    std::cout << entry << std::endl;
    tokens = helper::split(entry.path(), '/');
    tokens = helper::split(tokens.back(), '_');

    if (tokens[0].compare(std::to_string(dayNum)) == 0)
    {
      std::cout << "returning the found file: \n";
      std::cout << entry.path() << std::endl;

      return entry.path();
    }
  }
  return "filenotfound";
}

bool helper::fileExists(std::string fullPath)
{
  return 0;
}

std::ifstream helper::openFile(int dayNum, int taskNum)
{
  std::ifstream file;
  // get the full file path for the chosen day and task:
  std::string fullFilePath = helper::addPath(dayNum, taskNum);
  file.open(fullFilePath);

  return file; 
}

void helper::closeFile(int dayNum, int taskNum)
{

}
