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
    static void read(bool image, int hour);
    // Mode d'emploi :
    //
    // Contrat :
    //
    static bool isAuthorised(string url,const std::vector<string> & tab );


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
typedef struct struct_log {
    std::string ipEmettor;// client's identity
    std::string day;// date from the request
    std::string hour;//hour from the request
    std::string gmt;// gmt from request
    std::string action;// type of action
    std::string urlHit;// document and page asked
    std::string protocol;// protocol used
    std::string returnCode;//status of reponse : 200 shows no error
    std::string octetQuantity;//size of data tranfered from servor
    std::string referer;//url from where is done the request
    std::string browser;//client's browsers
}struct_log;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <loganalyse>

#endif // loganalyse_H

