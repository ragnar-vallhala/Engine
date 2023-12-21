#include "EngineUtils.h"



void readFile(const char* path, std::string& str)
{
	std::ifstream in;
	in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		in.open(path);
		std::stringstream stream;
		stream << in.rdbuf();
		str = stream.str();
		in.close();
	}
	catch(std::ifstream::failure e){
		LOGL("ERROR:: COULD NOT OPEN ");
		LOG((std::string)path+" "+e.what());
	}


}
