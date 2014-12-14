#ifndef URLMultiMap_h
#define URLMultiMap_h

#include <multimap>
#include <string>

#include "URLStats.h"

class URLMultiMap


{
	public:
		URLMultiMap();
		/**
		 * Creates the structure of the URL data
		 * @params isOptionG true if the user uses -g option
		 * Creates a dataMapG if isOptionG is true, else creates a dataMapR
		 */

		~URLMultiMap();
		/**
		 * Destroys the URLMultiMap
		 */

		int AddLine(std::string url, int hits);

		void Displays();

	private:

		std::multimap<std::string, int> topTenMap;
};

#endif // URLMultiMap_h
