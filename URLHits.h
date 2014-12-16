#include <string>

class URLHits
{

public:
	URLHits(std::string name, int hits);

	~URLHits();

	std::string name;
	int hits;
};