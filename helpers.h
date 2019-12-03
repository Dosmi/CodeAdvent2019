#ifndef HELPERS_H
#define HELPERS_H

#include <string>

//std::string addPath(std::string filename);

namespace helper
{
  std::string addPath(int dayNum, int taskNum);
  bool fileExists(std::string fullPath);
  void openFile(int dayNum, int taskNum);
  void closeFile(int dayNum, int taskNum);
}

#endif
