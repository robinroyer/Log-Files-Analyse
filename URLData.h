#ifndef URLData_h
#define URLData_h

#include <unordered_map>
#include <string>

//#include <URLStats.h>

class URLData


{
	public:
		URLData(bool isOptionG);
		/**
		 * Creates the structure of the URL data
		 * @params isOptionG true if the user uses -g option
		 * Creates a dataMapG if isOptionG is true, else creates a dataMapR
		 */

		 ~URLData();
		/**
		 * Destroys the URLData
		 */

		 int AddAll(std::string logFile);

		 int AddLine(std::string line);

		 void Displays();


	private:

		//std::unordered_map <std:string, URLStats>  dataMapG; //dataMap optimized for -g option
		//std::unordered_map<std:string, int>  dataMapR; //regular dataMap
		std::unordered_map<std::string,int> dataMapR;

		bool optionG;

};

#endif // URLData_h
