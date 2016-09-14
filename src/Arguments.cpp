#include "Arguments.hpp"

int    Arguments::argc;
char** Arguments::argv; 

void Arguments::linkingArgcArgv(int argc, char **argv)
{
	Arguments::argc = argc;
	Arguments::argv = argv;
}
