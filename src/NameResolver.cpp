#include <cstdlib>
#include <iostream>

#include "NameResolver.hpp"


void getFullNameOfFile(const std::string &nameFromRoot, std::string &out)
{
	// Here, i'm using NULL and free() because realpath called malloc()
	// In order to avoid problems with valgrind, i prefer forget a bit about delete and nullptr for a while.
	char *absolutePath = realpath(Arguments::argv[0], NULL);
	if  (absolutePath == NULL)
	{
		std::cerr << "[ERROR] : The program cannot get the xml file" << std::endl;
		exit(EXIT_FAILURE);
	}
	out = std::string(absolutePath);
	free(absolutePath);
	out = out.substr(0, out.find_last_of("\\/")) + "/" + nameFromRoot;
}
