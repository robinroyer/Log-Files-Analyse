#include "TopTenPair.h"

#include <multimap>
#include <string>

TopTenPair::TopTenPair(std::string nm, int ht);
{
	#ifdef DEBUG
    std::cout << "TopTenPair +1" << std::endl;
	#endif
	name=nm;
	hits=ht;
	
}

TopTenPair::~TopTenPair();
{
	#ifdef DEBUG
    std::cout << "TopTenPair -1" << std::endl;
	#endif

}