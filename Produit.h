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

    void setNom(const string &nom);

    float getPrixachat() const;

    void setPrixachat(float prixachat);

    float getPrixvente() const;

    void setPrixvente(float prixvente);

    int getNombreExemplaire() const;

    void setNombreExemplaire(int nombreExemplaire);

    const string &getDescription() const;

    void setDescription(const string &description);
};


#endif //TPCOMMERCE_PRODUIT_H
