//includes
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

#include "AppliAnalog.h"
#include "URLData.h"
#include "Graph.h"


AppliAnalog::AppliAnalog(int argc, char* argv[])
{
	#ifdef DEBUG
    std::cout << "AppliAnalog +1" << std::endl;
	#endif

	//store options in a list of string
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

bool AppliAnalog::is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

bool AppliAnalog::hasOption(char params)
{
	std::list<std::string>::const_iterator it, end;
    for(it = this->options.begin(), end = this->options.end(); it != end; it++)
    {
        if(it->at(0)=='-' and it->at(1)==params and it->size()<3)
        {
        		return true;
        }
    } 
    return false;
}

bool AppliAnalog::hasCorrectValueOption(char params)
{
	std::list<std::string>::const_iterator it, end;
	switch (params)
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
                //test if the params is a number
    			if(it->at(1)==params and is_number(*std::next(it)))
        		{
                    //if it is a number, we can test if is is between 0 and 23 (we accept 2.5 as 2 for exemple)
        			if(std::stoi(*std::next(it)) >= 0 and std::stoi(*std::next(it)) < 24)
                    {
                        return true;
                    }
                }
        	}
		break;

		case 'g': //check if the name of the dotfile is correct
			for(it = this->options.begin(), end = this->options.end(); it != end; it++)
    		{
        		if(it->at(1)==params and ((++it))->find(".dot")!=-1)
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

std::string AppliAnalog::ValueOption(char params)
{
    std::list<std::string>::const_iterator it, end;
    switch (params)
    {
        case '0': 
            //return the last options: the name of the logfil
            #ifdef DEBUG
            std::cout << options.back() << std::endl;
            #endif
            return options.back();
        break;

        case 't':
            //find the t params
            for(it = this->options.begin(), end = this->options.end(); it != end; it++)
            {
                if(it->at(1)==params)
                {
                    #ifdef DEBUG
                    std::cout << options.back() << std::endl;
                    #endif
                    return *(std::next(it));
                }
            }
        break;

        case 'g':
            //find the g params
            for(it = this->options.begin(), end = this->options.end(); it != end; it++)
            {
                if(it->at(1)==params) 
                {
                    //return the name of the dot file
                    #ifdef DEBUG
                    std::cout << options.back() << std::endl;
                    #endif
                    return *(std::next(it));
                }
            }           
        break;

        default:
            return "ERROR";
        break;
    }
    return "ERROR";
}



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

    if(hasOption('t'))
    {
        if(!hasCorrectValueOption('t'))
        {
            std::cerr<< "ERROR2: The time is incorrect."<<std::endl;
            return 2;
        }
    }

    if(hasOption('g'))
    {
        if(!hasCorrectValueOption('g'))
        {
            std::cerr<< "ERROR3: The dotfile is incorrect."<<std::endl;
            return 3;
        }
    }
    
    //All the options are correct, starts the application!
    URLData* data = new URLData();

    //Read the logfile and put information from it in data
    if(hasOption('t'))
    {
        data->read(!hasOption('x'), ValueOption('t'), ValueOption('0'), hasOption('c'));
    }
    else
    {
        data->read(!hasOption('x'), "-1", ValueOption('0'), hasOption('c'));
    }
    
    //displays the top ten websites
    data->TopTen();

    //generate the dot file if option -g
    if(hasOption('g'))
    {
        Graph* graph = new Graph(ValueOption('g'));
        graph->GenerateDot(data);
        delete graph;

    }

    delete data;
    
    return 0;

}



int main (int argc, char* argv[])
{
	AppliAnalog* app = new AppliAnalog(argc, argv);
	int code = app->Execute();
	delete app;
	return code;

}
