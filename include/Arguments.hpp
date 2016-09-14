/**
 * @brief A basic storage for argc and argv
 * @author MTLCRBN
 * @version 1.0
 */
#ifndef ARGUMENTS_HPP_INCLUDED
#define ARGUMENTS_HPP_INCLUDED


/**
 * @brief A container for the command line.
 */
class Arguments final
{
	public:
		static int    argc;
		static char **argv;
		
		/**
		 * @brief To store the command line in this class.
		 * You just have to call this function with appropriate arguments :D.
		 */
		static void linkingArgcArgv(int argc, char **argv);
		
		Arguments(void) = delete;
		Arguments(const Arguments &other) = delete;
		Arguments(Arguments &&other) = delete;
	
};

#endif
