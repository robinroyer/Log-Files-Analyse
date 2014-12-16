//includes
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#include "URLData.h"
#include "URLStats.h"

using namespace std;

	
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
        addTopTen(it->first,(it->second)->GetHits());
	}
	
	listTopTen.sort();
	
    auto itend = listTopTen.end();
	for (int i = 0; i < 10; i++)
    {
        itend--;
        std::cout << itend->name << " : " << itend->hits << std::endl;
    }

   	return 0;
}

int URLData::addTopTen(std::string str, int hits)
{
    URLHits newURL(str, hits);
    listTopTen.push_back(newURL);
    return 0;
}

std::string URLData::getLinks()
{
	std::stringstream tempText;

	//writes the dot file
	std::unordered_map<std::string,int> tempMap;

	//str.erase(std::remove(str.begin(), str.end(), 'a'), str.end());
	///-------- nodes -----
	/*
	for (auto it = dataMap.begin(); it != dataMap.end(); ++it )
	{
		tempText /*<< "ID"
				<< hashStringToInt(it->first)
				<< " [label=\""
				<<	it->first
				/*<<  "\"];\n"
                << "\n";
	}
    */

    for (auto it = dataMap.begin(); it != dataMap.end(); ++it )
    {
        tempMap=(it->second)->GetMap();
        for (auto its = tempMap.begin(); its != tempMap.end(); ++its)
        {
                tempText <<it->first
                            <<"\n"
                            << its->first
                            << "\n";
        }
    }
	
	///------- links -----
	for (auto it = dataMap.begin(); it != dataMap.end(); ++it )
	{
		tempMap=(it->second)->GetMap();
		for (auto its = tempMap.begin(); its != tempMap.end(); ++its)
		{
				tempText << "\""
							<< its->first
                            << "\""
							<< " -> "
							/*<< "ID"*/
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

std::string URLData::clearURL(std::string str)
{

    test.push_back(str);

	if (str.find("?")!=std::string::npos /*or str.rfind("php?")!=std::string::npos or str.rfind("url?")!=std::string::npos */)
	{
		std::size_t found = str.find("?");
    	if (found!=std::string::npos)
        	str = str.substr(0, found);
	}
	if (str.rfind(";")!=std::string::npos)
	{
		std::size_t found = str.rfind(";");
    	if (found!=std::string::npos)
        	str = str.substr(0, found);
	}
	if (str.back() == '/')
	{
		str.erase (str.end()-1, str.end());
	}
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
    if (str.find("intranet-if")!=std::string::npos)
    {
        if (str.find("90")!=std::string::npos)
        {
            std::size_t found = str.find("90");
            if (found!=std::string::npos)
                str = str.substr(found+2, str.size());
        }
        
    }
    //google
    if (str.find("google")!=std::string::npos)
    {
        str = "Google";
        
    }
    //bing
    if (str.find("bing")!=std::string::npos)
    {
        str = "Bing";
        
    }
    //facebook
    if (str.find("facebook")!=std::string::npos)
    {
        str = "Facebook";
        
    }
    if (str.find("stages/descriptif")!=std::string::npos)
    {
        str = "/stages";
    }
    //intranet

	return str;

}


int URLData::hashStringToInt(std::string str)
{
	return std::hash<std::string>()(str);
}
int URLData::read(bool affImage, int hour)
/*contrat :  Les entrees possible de hour doivent etre -1 ou [0;23]
             Bool image est vrai si on veut l'affichage des images
        */
{
     // déclaration d'une chaîne qui contiendra la ligne lue
    std::string contenu; 
    //liste d'exception
    std::list<string> myExtensions;
    //boolean vrai si cette structure a une extension a exclure
    bool exclusion;
    //--------creation de la liste chainee des extensions a ne pas prendre en compte---------
    if (!affImage)
    {
        ifstream extension("extension.ini", std::ios::in);//ouverture du flux de lecture
        if(extension)
        {
            
            while(getline(extension, contenu))
            {
                //--------------ajout de chaque extension a mon vector d'extensions

                if(contenu.substr(0,1)!="#")
                {
                    myExtensions.push_back(contenu);
                    
                } 
            }
            
            extension.close();
        }
        else
            cerr << "Impossible d'ouvrir le fichier des extensions !" << endl;
    }//-------------vector des extensions cree------------



    // on ouvre le fichier de log en lecture
    ifstream fichier("anonyme.log", ios::in);
    // on cree la structure de stockage
    struct_log data;

    if(fichier)  // si l'ouverture a réussi
    {        
        while(getline(fichier, contenu))
        {
            #ifdef MAP
             cout <<"la ligne de log est : "<<endl<< contenu<<endl<<endl;// trace pour verifier que les logs sont bien coupes
            #endif


            // -----------------separation des logs et rangement dans la structure-------------
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
            data.urlHit = clearURL(contenu.substr(0,contenu.find_first_of(' ',0)));
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
			data.referer = clearURL(contenu.substr(0,contenu.find_first_of('"',0)));
			contenu=contenu.substr(contenu.find_first_of('"',1)+3,contenu.length());
            
            //browser
            data.browser=contenu.substr(0,contenu.length()-1);


            #ifdef MAP

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

            //on cherche si lextension est conforme
            exclusion=false;
            for (std::list<string>::iterator it = myExtensions.begin(); it != myExtensions.end(); it++)
             {
                 if((data.urlHit.find(*it)>0)&&(data.urlHit.find(*it)<=data.urlHit.length()))
                {
                    #ifdef MAP
                    cout<<"extension trouve a la place"<<data.urlHit.find(*it)<<endl;
                    cout<<*it <<endl;


                    #endif
                    exclusion =true;
                }
             }

            if (data.returnCode=="200")
            
            {// ----------appel avec les options pour ranger les logs dans notre structure--------
                        if((affImage==true) ||(exclusion==false))  //on  test si  l'extension est autorise 
                        {
            
                                if (hour==-1){
            
                                    AddLine(data.urlHit,data.referer);
                                    #ifdef MAP
                                    cout<<"----------------ajout toutes les heures-------------"<<endl;
                                    #endif
                                }
                                else {
                                    if(std::stoi(data.hour)==hour){
                                        //------------on ajoute les logs correspondant a la bonne heure
                                        AddLine(data.urlHit,data.referer);
                                        #ifdef MAP
                                        cout<<"----------------ajout de la bonne heure-------------"<<endl;
                                        #endif
                                    }
                                }
                        }      }
            //on ferme le fichierx
        }
        fichier.close();
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;


} //----- Fin de Méthode


bool operator< (URLHits const h1, URLHits const h2) 
{ 
    return h1.hits <= h2.hits; 
}