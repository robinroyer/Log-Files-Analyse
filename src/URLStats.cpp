#include "URLStats.h"
#include <string>
#include <iostream>

URLStats::URLStats()
{
	#ifdef DEBUG
    std::cout << "URLStats +1" << std::endl;
	#endif

	hits=0;
	howManyReferer=0;
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

int URLStats::GetHits() const
{
	return hits;
}

int URLStats::GetNumberOfReferer() const
{
	return howManyReferer;
}


std::unordered_map<std::string,int> URLStats::GetMap() const
{
	return statsMap;
}


int URLStats::AddReferer(std::string referer)
{
	if(statsMap.find(referer) == statsMap.end())
	{
		statsMap[referer] = 0;
		howManyReferer++;
	}
	statsMap[referer]++;
	return 0;
}