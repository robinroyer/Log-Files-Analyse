#include "URLStats.h"
#include <string>
#include <iostream>

URLStats::URLStats()
{
	#ifdef DEBUG
    std::cout << "URLStats +1" << std::endl;
	#endif

	hits=0;
}

URLStats::~URLStats()
{
	#ifdef DEBUG
    std::cout << "URLStats -1" << std::endl;
	#endif
}

int URLStats::AddHit()
{
	hits++;
	return 0;
}

int URLStats::GetHits()
{
	return hits;
}