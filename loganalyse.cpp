

/*************************************************************************
                           loganalyse  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <loganalyse> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <list>
using namespace std;
//------------------------------------------------------ Include personnel
#include "loganalyse.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


void loganalyse::read(bool affImage, int hour)
/*contrat :  Les entrees possible de hour doivent etre -1 ou [0;23]
             Bool image est vrai si on veut l'affichage des images
        */
{
     // déclaration d'une chaîne qui contiendra la ligne lue
    string contenu; 
    //liste d'exception
    std::list<string> myExtensions;
    //boolean vrai si cette structure a une extension a exclure
    bool exclusion;
    //--------creation de la liste chainee des extensions a ne pas prendre en compte---------
    if (!affImage)
    {
        ifstream extension("extension.ini", ios::in);//ouverture du flux de lecture
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
            #ifdef MAP
            cout<<data.ipEmettor<<endl;  
            #endif
            contenu=contenu.substr(contenu.find_first_of('[',0)+1,contenu.length());
            //day
            data.day=contenu.substr(0,contenu.find_first_of(':',0));
            #ifdef MAP
            cout<<data.day<<endl;
            #endif
            contenu=contenu.substr(contenu.find_first_of(':',0)+1,contenu.length());
            //hour
            data.hour=contenu.substr(0,contenu.find_first_of(':',0));
            #ifdef MAP
            cout<<data.hour<<endl;
            #endif
            contenu=contenu.substr(contenu.find_first_of(' ',1)+1,contenu.length());
            //gmt
            data.gmt=contenu.substr(0,contenu.find_first_of(']',0));
            #ifdef MAP
            cout<<data.gmt<<endl;
            #endif
            contenu=contenu.substr(contenu.find_first_of('"',0)+1,contenu.length());
            //action
            data.action=contenu.substr(0,contenu.find_first_of('/',0));
            #ifdef MAP
            cout<<data.action<<endl;
            #endif
            contenu=contenu.substr(contenu.find_first_of('/',2),contenu.length());
            //urlHit
            data.urlHit=contenu.substr(0,contenu.find_first_of(' ',0));
            #ifdef MAP
            cout<<data.urlHit<<endl;
            #endif
            contenu=contenu.substr(contenu.find_first_of(' ',0)+1,contenu.length());

            //protocol used
            data.protocol=contenu.substr(0,contenu.find_first_of('"',0));
            #ifdef MAP
            cout<<data.protocol<<endl;
            #endif
            contenu=contenu.substr(contenu.find_first_of('"',0)+2,contenu.length());

            //returnCode
            data.returnCode=contenu.substr(0,contenu.find_first_of(' ',1));
            #ifdef MAP
            cout<<data.returnCode<<endl;
            #endif

            contenu=contenu.substr(contenu.find_first_of(' ',2)+1,contenu.length());
            //Octet Quantity
            data.octetQuantity=contenu.substr(0,contenu.find_first_of(' ',1));
            #ifdef MAP
            cout<<data.octetQuantity<<endl;
            #endif

            contenu=contenu.substr(contenu.find_first_of('"',1)+1,contenu.length());
            //referer
            data.referer=contenu.substr(0,contenu.find_first_of('"',0));
            #ifdef MAP
            cout<<data.referer<<endl;
            #endif

            contenu=contenu.substr(contenu.find_first_of('"',1)+3,contenu.length());
            //browser
            data.browser=contenu.substr(0,contenu.length()-1);
            #ifdef MAP
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

          
            // ----------appel avec les options pour ranger les logs dans notre structure--------
            if((affImage==true) ||(exclusion==false))  //on  test si  l'extension est autorise 
            {

                    if (hour==-1){

                        // --------------on les ajoutes tous----------
                        #ifdef MAP
                        cout<<"----------------ajout toutes les heures-------------"<<endl;
                        #endif
                    }
                    else {
                        if(std::stoi(data.hour)==hour){
                            //------------on ajoute les logs correspondant a la bonne heure
                            // --------------on les ajoutes tous----------
                            #ifdef MAP
                            cout<<"----------------ajout de la bonne heure-------------"<<endl;
                            #endif

                        }
                    }
            }      
            //on ferme le fichierx
        }
        fichier.close();
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;


} //----- Fin de Méthode





//------------------------------------------------- Surcharge d'opérateurs
loganalyse & loganalyse::operator = ( const loganalyse & unloganalyse )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
loganalyse::loganalyse ( const loganalyse & unloganalyse )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <loganalyse>" << endl;
#endif
} //----- Fin de loganalyse (constructeur de copie)


loganalyse::loganalyse ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <loganalyse>" << endl;
#endif
} //----- Fin de loganalyse


loganalyse::~loganalyse ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <loganalyse>" << endl;
#endif
} //----- Fin de ~loganalyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées








int main()
{
    cout << "Hello World!" << endl;

   loganalyse::read(false,-1);

    return 0;
}



