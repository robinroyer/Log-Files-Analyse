#ifndef URLHits_h
#define URLHits_h

#include <string>

class URLHits
{

public:
	URLHits(std::string name, int hits);

	~URLHits();

	std::string GetName() const;

	int GetHits() const;


private:
	//attributes
	std::string name;
	int hits;
};

#endif // URLHits_h