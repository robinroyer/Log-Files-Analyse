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

		int GetHits() const;

		int GetNumberOfReferer() const;

		std::unordered_map<std::string,int> GetMap();

		int AddReferer(std::string referer);

	private:

		std::unordered_map<std::string,int> statsMap;
		unsigned int hits;
		unsigned int howManyReferer;

};

#endif // URLData_h
