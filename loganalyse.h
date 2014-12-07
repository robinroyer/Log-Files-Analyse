/*************************************************************************
                           loganalyse  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <loganalyse> (fichier ${file_name}) ------
#if ! defined ( loganalyse_H )
#define loganalyse_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <loganalyse>
//
//
//------------------------------------------------------------------------

class loganalyse
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void read(bool x, bool t, int hour);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    loganalyse & operator = ( const loganalyse & unloganalyse );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    loganalyse ( const loganalyse & unloganalyse );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    loganalyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~loganalyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
struct struct_log {
    string ipEmettor;// client's identity
    tm date;// date and hour from the request
    string action;// type of action
    string urlHit;// document and page asked
    int returnCode;//status of reponse : 200 shows no error
    int octetQuantity;//size of data tranfered from servor
    string referer;//url from where is done the request
    string browser;//client's browsers
};

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <loganalyse>

#endif // loganalyse_H

