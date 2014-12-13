#ifndef URLStats_h
#define URLStats_h

#include <unordered_map>
#include <string>

class URLStats


{
	public:
		URLStats();
		/**
		 * Creates a URLStats
		 */

		 ~URLStats();
		/**
		 * Destroys the URLStats
		 */

		int AddHit();

		int GetHits();

	private:

		std::unordered_map<std::string,int> statsMap;
		int hits;

};

#endif // URLData_h
