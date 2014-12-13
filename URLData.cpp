//includes
#include "URLData.h"
#include "URLStats.h"
#include <string>
#include <iostream>

URLData::URLData(bool isOptionG)
{
	#ifdef DEBUG
    std::cout << "URLData +1" << std::endl;
	#endif

	optionG=isOptionG;
}

URLData::~URLData()
{
	#ifdef DEBUG
    std::cout << "URLData -1" << std::endl;
	#endif

    //delete all the URLStats
    for ( auto it = dataMap.begin(); it != dataMap.end(); ++it )
    	delete it->second;
}


int URLData::AddAll(std::string logFile)
{
	return 0;
}

int URLData::AddLine(std::string line)
{
	if(dataMap.find(line) == dataMap.end())
	{
		dataMap[line] = new URLStats();
	}
	dataMap[line]->AddHit();

	return 0;
}

void URLData::Displays()
{
	std::cout << "mymap contains:" << std::endl;
	for ( auto it = dataMap.begin(); it != dataMap.end(); ++it )
		std::cout << " " << it->first << ":" << (it->second)->GetHits() << std::endl;
	std::cout << std::endl;	
}