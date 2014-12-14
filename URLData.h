#ifndef URLData_h
#define URLData_h

#include <unordered_map>
#include <string>
#include <list>

#include "URLStats.h"

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

		 int AddLine(std::string url, std::string referer);

		 void Displays();

		 int TopTen();

		 std::string getLinks();


	private:

		std::unordered_map<std::string, URLStats*> dataMap;
		std::list<std::string> topTen;
		bool optionG;

};

#endif // URLData_h
