#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

//std::string addPath(std::string filename);

namespace helper
{
  std::vector<std::string> split(std::string, char delimiter);

  std::string addPath(int dayNum, int taskNum);
  bool fileExists(std::string fullPath);
  std::ifstream openFile(int dayNum, int taskNum);
  void closeFile(int dayNum, int taskNum);
}

#endif
