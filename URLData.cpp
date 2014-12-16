//includes
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#include "URLData.h"
#include "URLStats.h"

	
URLData::URLData()
{
	#ifdef DEBUG
    std::cout << "URLData +1" << std::endl;
	#endif
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

int URLData::TopTen()
{
    //add to a list, all the website visited and their hits
	for( auto it = dataMap.begin(); it != dataMap.end(); ++it )
	{
        addTopTen(it->first,(it->second)->GetHits());
	}
	//sort this list according to their hits number (less first)
	listTopTen.sort();
	
    //displays the last 10 elements of this list
    auto itend = listTopTen.end();
	for (int i = 0; i < 10; i++)
    {
        itend--;
        //displays each ten first website with this syntax : "Website : X" (X, number of hits)
        std::cout << itend->GetName() << " : " << itend->GetHits() << std::endl;
    }

   	return 0;
}

int URLData::addTopTen(std::string str, int hits)
{
    //add the website to the list (key: website, value: number of hits)
    URLHits newURL(str, hits);
    listTopTen.push_back(newURL);
    return 0;
}

std::string URLData::getLinks()
{
	std::stringstream tempText;

	//writes the dot file
	std::unordered_map<std::string,int> tempMap;
	
	//White in tempText the synthaxe to create links in the dot file
    //with this syntax : " "website1" -> "website2" [label="X"]" (X, number of hits)
	for (auto it = dataMap.begin(); it != dataMap.end(); ++it )
	{
		tempMap=(it->second)->GetMap();
		for (auto its = tempMap.begin(); its != tempMap.end(); ++its)
		{
				tempText << "\""
							<< its->first
                            << "\""
							<< " -> "
                            << "\""
							<< it->first
                            << "\""
							<< " [label=\""
							<< its->second
							<< "\"];\n";
		}
	}

	return "digraph {\n" + tempText.str() + "}\n";

}

std::string URLData::clearURL(bool clean, std::string str)
{
    
    if(clean)
    {
        //clean php URLs
    	if (str.find("?")!=std::string::npos)
    	{
    		std::size_t found = str.find("?");
        	if (found!=std::string::npos)
            	str = str.substr(0, found);
    	}
        //clean js URLs
    	if (str.rfind(";")!=std::string::npos)
    	{
    		std::size_t found = str.rfind(";");
        	if (found!=std::string::npos)
            	str = str.substr(0, found);
    	}
        //delete the last /
    	if (str.back() == '/')
    	{
    		str.erase (str.end()-1, str.end());
    	}
        //delete the root URL for insa-lyon.fr URLs
        if (str.find("insa-lyon.fr")!=std::string::npos)
        {
            if (str.find(".fr:90")!=std::string::npos)
            {
                std::size_t found = str.find("90");
                if (found!=std::string::npos)
                    str = str.substr(found+2, str.size());
            }
            else if (str.find(".fr")!=std::string::npos)
            {
                std::size_t found = str.find(".fr");
                if (found!=std::string::npos)
                    str = str.substr(found+3, str.size());
            }
            
        }
        //delete the root URL for intranet-if URLs
        if (str.find("intranet-if")!=std::string::npos)
        {
            if (str.find("90")!=std::string::npos)
            {
                std::size_t found = str.find("90");
                if (found!=std::string::npos)
                    str = str.substr(found+2, str.size());
            }
            
        }

        //Clean and order URLs from google        
        if (str.find("google")!=std::string::npos)
        {
            str = "Google";            
        }
        
        //Clean and order URLs from facebook        
        if (str.find("facebook")!=std::string::npos)
        {
            str = "Facebook";            
        }
    }

	return str;

}

int URLData::read(bool affImage, std::string hour, std::string logname, bool clean)
/*contrat :  Les entrees possible de hour doivent etre -1 ou [0;23]
 *           Bool image est vrai si on veut l'affichage des images
 */
{
    //contenu is the line read by the log parser
    std::string contenu;
    //myExtention is the list of extention to exclude
    std::list<std::string> myExtensions;
    //exclusion is false if do not have to add the line to the database
    bool exclusion;

    //creating the list of extention the exclude
    {
        //opening the extention file
        std::ifstream extension("extension.ini", std::ios::in);
        if(extension)
        {
            while(getline(extension, contenu))
            {
                //add each extention to the list
                if(contenu.substr(0,1)!="#")
                {
                    myExtensions.push_back(contenu);
                }
            }
            extension.close();
        }
        else
        {
            std::cerr << "ERROR 5 : Extention file can not be open, please check extention.ini." << std::endl;
            return 5;
        }
            
    } //extention list created

    //opening the logfile
    std::ifstream fichier(logname, std::ios::in);
    //creating data structure
    struct_log data;

    //if the file is open
    if(fichier)  
    {
        //for each line of the logfile
        while(getline(fichier, contenu))
        {
            #ifdef DEBUG
            std::cout <<"la ligne de log est : "<< std::endl << contenu << std::endl;
            #endif


            //Log parser and store it in a structure
            //emettor's IP
            data.ipEmettor=contenu.substr(0,contenu.find_first_of('[',0));
            contenu=contenu.substr(contenu.find_first_of('[',0)+1,contenu.length());

            //day
            data.day=contenu.substr(0,contenu.find_first_of(':',0));
            contenu=contenu.substr(contenu.find_first_of(':',0)+1,contenu.length());

            //hour
            data.hour=contenu.substr(0,contenu.find_first_of(':',0));
            contenu=contenu.substr(contenu.find_first_of(' ',1)+1,contenu.length());

            //gmt
            data.gmt=contenu.substr(0,contenu.find_first_of(']',0));
            contenu=contenu.substr(contenu.find_first_of('"',0)+1,contenu.length());

            //action
            data.action=contenu.substr(0,contenu.find_first_of('/',0));
            contenu=contenu.substr(contenu.find_first_of('/',2),contenu.length());

            //urlHit
            data.urlHit = clearURL(clean,contenu.substr(0,contenu.find_first_of(' ',0)));
            contenu=contenu.substr(contenu.find_first_of(' ',0)+1,contenu.length());

            //protocol used
            data.protocol=contenu.substr(0,contenu.find_first_of('"',0));
            contenu=contenu.substr(contenu.find_first_of('"',0)+2,contenu.length());

            //returnCode
            data.returnCode=contenu.substr(0,contenu.find_first_of(' ',1));
            contenu=contenu.substr(contenu.find_first_of(' ',2)+1,contenu.length());

            //Octet Quantity
            data.octetQuantity=contenu.substr(0,contenu.find_first_of(' ',1));
            contenu=contenu.substr(contenu.find_first_of('"',1)+1,contenu.length());

            //referer
            data.referer = clearURL(clean, contenu.substr(0,contenu.find_first_of('"',0)));
            contenu=contenu.substr(contenu.find_first_of('"',1)+3,contenu.length());

            //browser
            data.browser=contenu.substr(0,contenu.length()-1);


            #ifdef DEBUG

            cout<<data.ipEmettor<<endl;
            cout<<data.day<<endl;
            cout<<data.hour<<endl;
            cout<<data.gmt<<endl;
            cout<<data.action<<endl;
            cout<<data.urlHit<<endl;
            cout<<data.protocol<<endl;
            cout<<data.returnCode<<endl;
            cout<<data.octetQuantity<<endl;
            cout<<data.referer<<endl;
            cout<<data.browser<<endl<<endl;

            #endif

            //check if the extention is correct
            exclusion=false;
            //for each extention
            for (std::list<std::string>::iterator it = myExtensions.begin(); it != myExtensions.end(); it++)
            {
                if((data.urlHit.find(*it)>0) and (data.urlHit.find(*it)<=data.urlHit.length()))
                {
                    exclusion=true;
                }
            }

            //Add the website hited and his referer according to the option in the database
            //check the extention
            if(affImage==true or exclusion==false)
            {
                //then, check the time
                if (std::stoi(hour)==-1 or std::stoi(data.hour)==std::stoi(hour))
                {
                    AddLine(data.urlHit,data.referer);
                }
            }
        }
        fichier.close();
    }
    else
    {
        std::cerr << "ERROR 6 : The logfile can not be open." << std::endl;
        return 6;  
    }
    return 7;
}//--end of read--

//redefine of the operator < for two URLHits (uses by the TopTenList)
bool operator< (URLHits const h1, URLHits const h2) 
{ 
    return h1.GetHits() <= h2.GetHits(); 
}