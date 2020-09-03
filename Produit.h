//
// Created by eric on 03/09/2020.
//

#ifndef TPCOMMERCE_PRODUIT_H
#define TPCOMMERCE_PRODUIT_H

#include <string>

using namespace std;
class Produit {
    string nom;
    float prixachat;
    float prixvente;
    int nombreExemplaire;
    string description;
public:
    /**********************constructor***************************/
    Produit(const string &nom, float prixachat, float prixvente);
    /*********************methods*******************************/
    void afficherDescription();
    void editerDescription(const string &description);
    void augmenterExemplaire(const int nbex);
    void diminuerxemplaire(const int nbex);
    /******************getters***********************************/
    const string &getNom() const;

    float getPrixachat() const;

    float getPrixvente() const;

    int getNombreExemplaire() const;

    const string &getDescription() const;
};


#endif //TPCOMMERCE_PRODUIT_H
