#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <string>

class Options
{
public:
	Options(int argc, char** argv);

	std::string getFileName() const { return fileName_; }
private:
	std::string fileName_;
};


#endif // _OPTIONS_H_
