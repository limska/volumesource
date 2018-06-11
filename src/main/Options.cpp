#include "Options.h"

#include <boost/program_options.hpp>


#include <vector>
#include <string>
#include <iostream>

namespace po = boost::program_options;

Options::
Options(int argc, char** argv)
{
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("filename", po::value<std::string>(), "set STL filename")
  ;



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
