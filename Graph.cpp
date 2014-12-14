#include "Graph.h"
#include "URLData.h"

Graph::Graph(std::string name)
{
	#ifdef DEBUG
    std::cout << "Graph +1" << std::endl;
	#endif
    dotText = "";
    fileName = name;
}

Graph::~Graph()
{
	#ifdef DEBUG
    std::cout << "Graph -1" << std::endl;
	#endif
}

int Graph::GenerateDot(URLData* data)
{
	dotText=data->getLinks();
	return 0;
}