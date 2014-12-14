//includes
#include <iostream>
#include <string>
#include <list>

#include "AppliAnalog.h"
#include "URLData.h"
#include "Graph.h"

AppliAnalog::AppliAnalog(int argc, char* argv[])
{
	#ifdef DEBUG
    std::cout << "AppliAnalog +1" << std::endl;
	#endif

	options = std::list <std::string> ();

	//stock options in a list of string
	for (int i = 0; i < argc; i++)
	{
		options.push_back(std::string(argv[i]));
	}
}

AppliAnalog::~AppliAnalog()
{
	#ifdef DEBUG
    std::cout << "AppliAnalog -1" << std::endl;
	#endif
}

bool AppliAnalog::hasOption(char opt)
{
	std::list<std::string>::const_iterator it, end;
    for(it = this->options.begin(), end = this->options.end(); it != end; it++)
    {
        if(it->at(0)=='-' and it->at(1)==opt and it->size()<3)
        {
        		return true;
        }
    } 
    return false;
}

bool AppliAnalog::hasCorrectValueOption(char opt)
{
	std::list<std::string>::const_iterator it, end;
	switch (opt)
	{
		case '0': //check if the name of the logfile is correct
			if(options.back().at(0)!='-' and options.back().find(".log")!=-1)
			{
				return true;
			}
		break;

		case 't': //check if the time format is correct
			for(it = this->options.begin(), end = this->options.end(); it != end; it++)
    		{
    			/*
    			 * Incorrect pour l'instant
    			 *
    			 *
        		if(it->at(1)==opt and std::stoi(*(it++))>0 and std::stoi(*it)>24) //pas beau, a modifier en it.next 
        		{
        			return true;
        		}

        		std::cout<< std::stoi(*it) << std::endl;
        		*/
        	}
		break;

		case 'g': //check if the name of the dotfile is correct
			for(it = this->options.begin(), end = this->options.end(); it != end; it++)
    		{
        		if(it->at(1)==opt and ((++it))->find(".dot")!=-1) //pas beau, a modifier en it.next 
        		{
        			return true;
        		}
        	}			
		break;

		default:
			return false;
		break;
	}
	return false;
}

/*
bool AppliAnalog::hasCorrectValueOption(std::string filename, std::string extention)
{
	if()
}
 */

int AppliAnalog::Execute()
{
	#ifdef DEBUG
    std::cout << "Start Execution" << std::endl;
	#endif	

    if(!hasCorrectValueOption('0'))
    {
    	std::cerr<< "ERROR1: The logfile is incorrect."<<std::endl;
    	return 1; //filename of the logfile invalid
    }

    if(hasOption('x'))
    {
    	std::cout<< "Option x" << std::endl;
    }

    if(hasOption('t'))
    {
    	if(!hasCorrectValueOption('t'))
    	{
    		std::cerr<< "ERROR2: The time is incorrect."<<std::endl;
    		return 2;
    	}
    	std::cout<< "Option t" << std::endl;
    }

    if(hasOption('g'))
    {
    	if(!hasCorrectValueOption('g'))
    	{
    		std::cerr<< "ERROR2: The dotfile is incorrect."<<std::endl;
    		return 2;
    	}
    	std::cout<< "Option g" << std::endl;
    }

    URLData* data = new URLData(hasOption('g'));

    data->AddLine("facebook.fr","google.fr");
    data->AddLine("facebook.fr","google.fr");
    data->AddLine("facebook.fr","yahou.fr");
    data->AddLine("yahoo.fr","google.fr");



    data->Displays();
    data->TopTen();

    Graph* graph = new Graph("coucou.dot");

    graph->GenerateDot(data);

    delete data;
    delete graph;

    return 0;

}

int main (int argc, char* argv[])
{
	AppliAnalog* app = new AppliAnalog(argc, argv);
	int code = app->Execute();
	delete app;
	return code;

}