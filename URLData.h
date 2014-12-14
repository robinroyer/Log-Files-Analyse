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

		 int read(bool affImage, int hour);




	private:
		int hashStringToInt(std::string str);

		std::string clearURL(std::string str);

		std::unordered_map<std::string, URLStats*> dataMap;
		std::list<std::string> topTen;
		bool optionG;

		typedef struct struct_log {
		    std::string ipEmettor;// client's identity
		    std::string day;// date from the request
		    std::string hour;//hour from the request
		    std::string gmt;// gmt from request
		    std::string action;// type of action
		    std::string urlHit;// document and page asked
		    std::string protocol;// protocol used
		    std::string returnCode;//status of reponse : 200 shows no error
		    std::string octetQuantity;//size of data tranfered from servor
		    std::string referer;//url from where is done the request
		    std::string browser;//client's browsers
		}struct_log;

};

#endif // URLData_h
