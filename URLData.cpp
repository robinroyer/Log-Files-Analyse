//includes
#include "URLData.h"
#include "URLStats.h"
#include <string>
#include <iostream>
#include <sstream>
#include <list>
	
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

int URLData::AddLine(std::string url, std::string referer)
{
	//check if the website is in the database and add it if it isn't in
	if(dataMap.find(url) == dataMap.end())
	{
		dataMap[url] = new URLStats();
	}
	dataMap[url]->AddHit();
	dataMap[url]->AddReferer(referer);
	return 0;
}

void URLData::Displays()
{
	std::cout << "mymap contains:" << std::endl;
	for ( auto it = dataMap.begin(); it != dataMap.end(); ++it )
		std::cout << " " << it->first << ":" << (it->second)->GetHits() << std::endl;
	std::cout << std::endl;	
}

int URLData::TopTen()
{
	for ( auto it = dataMap.begin(); it != dataMap.end(); ++it )
	{
		//std::cout << " " << it->first << ":" << (it->second)->GetHits() << std::endl;
		//créer structure 
		//ajouter à la liste
	}
		
	//trier la list
}

std::string URLData::getLinks()
{
	std::stringstream tempText;

	//writes the dot file
	std::unordered_map<std::string,int> tempMap;
	for (auto it = dataMap.begin(); it != dataMap.end(); ++it )
	{
		tempMap=(it->second)->GetMap();
		for (auto its = tempMap.begin(); its != tempMap.end(); ++its)
		{
			tempText << it->first
					<< " -> "
					<< its->first
					<< " [label=\""
					<< its->second
					<< "\"];\n";
		}
		
	}

	return "diagraph {\n" + tempText.str() + "}\n";

}
