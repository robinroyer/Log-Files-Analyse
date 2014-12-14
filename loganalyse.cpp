

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
using namespace std;
//------------------------------------------------------ Include personnel
#include "loganalyse.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


void loganalyse::read(bool x, bool t, int hour)
// Algorithme :
{
    // on ouvre le fichier en lecture
    ifstream fichier("anonyme.log", ios::in);
    // on cree la structure de sotckage
    struct_log data;

    if(fichier)  // si l'ouverture a réussi
    {
        // effectuer la lecture ici:
        string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
        while(getline(fichier, contenu))
        {
             cout << contenu<<endl;  // on affiche la ligne

            // -----------------on va devoir couper et ranger dans la structure ici-------------
            data.ipEmettor=contenu.substr(0,contenu.find_first_of('[',0));
            contenu=contenu.substr(contenu.find_first_of('[',0),contenu.length());
            //data.date=
            data.day=contenu.substr(0,contenu.find_first_of(' ',0));
            contenu=contenu.substr(contenu.find_first_of(' ',0),contenu.length());
            data.hour=contenu.substr(1,contenu.find_first_of(' ',0));
            contenu=contenu.substr(contenu.find_first_of(' ',1),contenu.length());
            data.gmt=contenu.substr(0,contenu.find_first_of(']',0));
            contenu=contenu.substr(contenu.find_first_of('"',0),contenu.length());

            data.action=contenu.substr(0,contenu.find_first_of(' ',0));
            contenu=contenu.substr(contenu.find_first_of(' ',0),contenu.find_first_of(' ',0));
            //data.urlHit=contenu;
            data.urlHit=contenu.substr(0,contenu.find_first_of('"',0));
            contenu=contenu.substr(contenu.find_first_of(' ',0),contenu.length());

            data.return=contenu.substr(0,contenu.find_first_of(' ',1));
            contenu=contenu.substr(contenu.find_first_of(' ',0),contenu.length());

            data.octetQuantity=contenu.substr(0,contenu.find_first_of(' ',1));
            contenu=contenu.substr(contenu.find_first_of('"',1),contenu.length());

            data.referer=contenu.substr(0,contenu.find_first_of('"',1));
            contenu=contenu.substr(contenu.find_first_of('"',1),contenu.length());

            data.browser=contenu.substr(0,contenu.find_first_of('"',1));

        //afichage pour debug

        cout<<data.ipEmettor<<endl;    
        cout<<data.day<<endl;
        cout<<data.hour<<endl;
        cout<<data.hour<<endl;
        cout<<data.gmt<<endl;
        cout<<data.action<<endl;
        cout<<data.urlHit<<endl;
        cout<<data.return<<endl;    
        cout<<data.octetQuantity<<endl; 
        cout<<data.referer<<endl;               
        cout<<data.browser<<endl;     
            // appel avec les option pour ranger des nles maps ou pas

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

   loganalyse::read(true,true,12);


    return 0;
}



