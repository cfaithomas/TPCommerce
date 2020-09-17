//
// Created by eric on 03/09/2020.
//

#ifndef TPCOMMERCE_MAGASIN_H
#define TPCOMMERCE_MAGASIN_H

#include "Produit.h"

# include<vector>

class Magasin {
private:
    vector<Produit*> stock;
    float solde;
public:
    Magasin();

    virtual ~Magasin();

    void ajouterProduit(const string &nom,float prixachat,float prixvente);
    void ajouterCd(const string &nom, float prixachat,  float prixvente, const string &interprete, const string &auteur,const vector<string> &listepistes);
    void ajouterlivre(const string &nom,float prixachat,float prixvente,const string &auteur,const string &editeur);
    void acheterProduit(int referenceProduit,int nombreExemplaires);
    void vendreProduit(int referenceProduit, int  nombreExemplaires);

    const vector<Produit *> &getStock() const;

    float getSolde() const;

    void bilan();

    void interaction(); //menu principal

    void submenu(const string &type); //sous menu avec en parametre le type (cd,livre ou produit)

    int choixproduit(const string &type); //permet de choisir la référence d'un produit avec un type (cd,livre ou produit)

    int choixqte(); //saisie des quantités

    const string saisieinformation(const string &type); //saisie des toutes les informations textuelles (auteur,editeur,nom)

    float saisieprix(const string &type); //saisie des prix parametre(cd,livre,produit)

    vector<string> saisielistetitre(); //saisie des pistes du cd
};


#endif //TPCOMMERCE_MAGASIN_H
