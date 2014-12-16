#ifndef TopTenPair_h
#define TopTenPair_h

#include <string>

class TopTenPair

{
	public:
		TopTenPair(std::string nm, int ht);
		/**
		 * Creates the structure of the URL data
		 * @params isOptionG true if the user uses -g option
		 * Creates a dataMapG if isOptionG is true, else creates a dataMapR
		 */

		~TopTenPair();
		/**
		 * Destroys the TopTenPair
		 */

		std::string name;
		int hits;
		
	private:
		
};

#endif // TopTenPair_h
