#include <string>

#include "URLHits.h"

URLHits::URLHits(std::string nm, int ht)
{
	#ifdef DEBUG
    std::cout << "URLHits +1" << std::endl;
	#endif
	this->name = nm;
	this->hits = ht;
}

URLHits::~URLHits()
{
	#ifdef DEBUG
    std::cout << "URLHits -1" << std::endl;
	#endif
}

std::string URLHits::GetName() const
{
	return name;
}

int URLHits::GetHits() const
{
	return hits;
}