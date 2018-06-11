#include "Options.h"
#include "server/server.hpp"

#include <iostream>
#include <string>
#include <boost/asio.hpp>

int
main(int argc, char** argv)
{
  Options opts(argc,argv);

  std::string address = "0.0.0.0";
  std::string port = "80";
  std::string doc_root = "tests";

  try
  {
    // Initialise the server.
    http::server::server s(address,port,doc_root);

    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }


	return 0;
}
