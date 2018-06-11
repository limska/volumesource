#ifndef _REQUEST_PATH_PARSER_
#define _REQUEST_PATH_PARSER_

#include <string>
#include <map>

class RequestPathParser
{
public:
  RequestPathParser(std::string const & requestPath)
    : path(requestPath)
  {}

  void parse(std::string & method, std::map<std::string,std::string> & args) const;
private:
  std::string path;
};

#endif
