

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
    ifstream fichier("test.txt", ios::in);
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
            contenu=contenu.substr(contenu.find_first_of(']',0),contenu.length());
            data.action=contenu.substr(0,contenu.find_first_of(' ',0));
            contenu=contenu.substr(contenu.find_first_of('[',0),contenu.find_first_of(' ',0));
            //data.urlHit=contenu;


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

