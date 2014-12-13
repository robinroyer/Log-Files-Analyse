//includes

#include "URLData.h"
#include <string>
#include <iostream>

URLData::URLData(bool isOptionG)
{
	#ifdef DEBUG
    std::cout << "URLData +1" << std::endl;
	#endif

	optionG=isOptionG;

	if(optionG)
	{
		#define MAPDATA dataMapG
	}
	else
	{
		#define MAPDATA dataMapR
	}
}

URLData::~URLData()
{
	#ifdef DEBUG
    std::cout << "URLData -1" << std::endl;
	#endif
}


int URLData::AddAll(std::string logFile)
{
	return 0;
}

int URLData::AddLine(std::string line)
{
	if(MAPDATA.find(line) == dataMapR.end())
	{
		dataMapR[line] = 0;
	}
	dataMapR[line]++;

	return 0;
}

void URLData::Displays()
{
	std::cout << "mymap contains:" << std::endl;
 	for (auto& x: dataMapR)
    	std::cout << x.first << ": " << x.second << std::endl;
 	std::cout << std::endl;
}