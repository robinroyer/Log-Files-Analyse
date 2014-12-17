#ifndef URLData_h
#define URLData_h

#include <unordered_map>
#include <string>
#include <list>

#include "URLStats.h"
#include "URLHits.h"

class URLData


{
	public:
		URLData();
		/**
		 * Creates the URLData structure
		 */

		 ~URLData();
		/**
		 * Destroys the URLData structure
		 */

		 int AddLine(std::string url, std::string referer);
		/**
		 * Add a line from the logfile in the database
		 * @params url addres of the URL hit
		 * @params referer addres of the referer
		 * @return an error code
		 */

		 int TopTen();
		/**
		 * Generate by using addTopTen and displays the structure that contains the website, ordered by hits.
		 * @return an error code
		 */

		 std::string getLinks();
		/**
		 * Generate the code in the dot file in order to create the graph
		 * @return an error code
		 */

		 int read(bool affImage, std::string hour, std::string logname, bool clean = false);
		/**
		 * Read is a parserlog, it read the log line by line and analyzes it then it send the data to store to AddLine
		 * @params affImage false if the user uses -x option
		 * @params hour -1 if the user does not use t option, 0:23 else, it is the only hour to display
		 * @params logname name of the log to analyze
		 * @params clean true if the user uses -c option, false by default
		 * @return an error code
		 */

	private:
		//functions
		std::string clearURL(std::string str);
		/**
		 * Modifie the URL by deleting part of the URL to make the graph and the stats more correctly
		 * @return the modified string
		 */

		int addTopTen(std::string str, int hits);
		/**
		 * add to the TopTen structure a website and his number of hits
		 * @params str URL of the website
		 * @params hits nulber of hits
		 * @return an error code
		 */

		//attributes
		//main structure
		std::unordered_map<std::string, URLStats*> dataMap;

		std::list<URLHits> listTopTen;

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
