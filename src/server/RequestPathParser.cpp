#include "RequestPathParser.h"

#include <string>
#include <iostream>

namespace
{
  void addArg(std::map<std::string,std::string> & args, std::string const & kv)
  {
    std::cout << "pair = " << kv << std::endl;
    std::size_t eq_loc = kv.find_first_of("=");
    std::string key = kv.substr(0,eq_loc);
    std::string value = kv.substr(eq_loc+1);
    args[key] = value;
  }
}

void
RequestPathParser::
parse(std::string & method, std::map<std::string,std::string> & args) const
{
  std::size_t qmark = path.find_first_of("?");

  method = path.substr(1,qmark-1);

  std::string argstr = path.substr(qmark+1);

  std::string const del {"&"};

  args.clear();
  std::size_t cur_loc = 0;
  std::size_t del_loc = argstr.find_first_of(del, cur_loc);
  if (del_loc > argstr.size())
  {
    addArg(args, argstr);
    return;
  }
  
  while (del_loc <= argstr.size())
  {
    std::string kv = argstr.substr(cur_loc,del_loc - cur_loc);
    addArg(args, kv);
    cur_loc = del_loc + 1;
    del_loc = argstr.find_first_of(del, cur_loc);
  }

  std::string kv = argstr.substr(cur_loc,del_loc - cur_loc);
  addArg(args, kv);
}