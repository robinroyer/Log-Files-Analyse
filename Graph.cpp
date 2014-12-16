#include <iostream>
#include <fstream>

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
	//generate the text of the dot file
	dotText=data->getLinks();

	//creates the file
	std::filebuf fb;
	fb.open (fileName,std::ios::out);
	std::ostream os(&fb);
	os << dotText;
	fb.close();

	return 0;
}