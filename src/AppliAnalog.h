#ifndef AppliAnalog_h
#define AppliAnalog_h

/* includes */

#include <list>

class AppliAnalog

/**
 * Global Application
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

		 bool is_number(const std::string& s);
		/**
		 * Return true is the string is a number
		 * @params s the string the function test
		 * @return true if the string is a number, false else
		 */

		 bool hasOption(char params);
		/**
		 * Check if the option in params exists in the options entered by the user
		 * @params params the letter that corresponds to the option (ex g for -g)
		 * @return true if the option exists, false else
		 */

		 bool hasCorrectValueOption(char params);
		/**
		 * Check if the syntax for the option is correct
		 * @params params the letter that corresponds to the option (ex g for -g)
		 * @return true if the syntax is correct, false else
		 */

		 std::string ValueOption(char params);
		/**
		 * return the value of the option in params (ex, for -t 14, it returns 14)
		 * @params params the letter that corresponds to the option (ex g for -g)
		 * @return value of the otpion in params
		 */


	private:
		//attributes
		std::list <std::string> options; //a list of the options entered by the user
};


#endif //AppliAnalog_h
