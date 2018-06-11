#ifndef _VOLUME_CALCULATOR_H_
#define _VOLUME_CALCULATOR_H_

#include <map>
#include <string>

class VolumeCalculator
{
public:
  VolumeCalculator(std::map<std::string,std::string> const & args_, std::string const & doc_root_)
    : args(args_)
    , doc_root(doc_root_)
  {}

  void calculate(std::string & response);

private:
  std::map<std::string,std::string> args;
  std::string doc_root;
};

#endif