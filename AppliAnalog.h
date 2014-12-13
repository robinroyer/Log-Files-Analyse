#ifndef AppliAnalog_h
#define AppliAnalog_h

/* includes */

#include <list>


class AppliAnalog

/**
 * The global Application
 */

{
	public:
		//functions
		AppliAnalog(int argc, char* argv[]);
		/**
		 * Creates the AppliAnalog that is the global application
		 * @params argc the size of argv that is the number of options entered by the user
		 * @params argv the options entered by the user
		 */

		~AppliAnalog();
		/**
		 * Destroys the AppliAnalog
		 */

		int Execute();
		/**
		 * Starts the Application
		 * @return the code of the application, details in the readme file
		 */

		 bool hasOption(char opt);

		 bool hasCorrectValueOption(char opt);


	private:
		//attributes
		std::list <std::string> options;
};

#endif //AppliAnalog_h
