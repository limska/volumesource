#include "Options.h"

#include <vector>
#include <string>
#include <iostream>

Options::
Options(int argc, char** argv)
{
  std::vector<std::string> args(argv,argv+argc);

  std::cout << "Args: ";
  for (auto arg : args)
  {
    std::cout << arg;   
  }
  std::cout << std::endl;

  if (args.size() != 2)
  {
    std::cout << "Usage: " << args[0] << " <filename>" << std::endl;
    throw;
  }

  fileName_ = args[1];

}
