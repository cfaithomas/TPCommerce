//
// Created by eric on 03/09/2020.
//

#include <iostream>
#include <iomanip>
#include "Magasin.h"
Magasin::Magasin() {
    solde=100;
}

void Magasin::ajouterProduit(const string &nom, float prixachat, float prixvente) {
stock.push_back(new Produit(nom,prixachat,prixvente));
}

void Magasin::acheterProduit(int referenceProduit, int nombreExemplaires) {
stock[referenceProduit]->augmenterExemplaire(nombreExemplaires);
solde-=stock[referenceProduit]->getPrixachat()*(float)nombreExemplaires;
}
void Magasin::vendreProduit(int referenceProduit, int nombreExemplaires) {
    stock[referenceProduit]->diminuerxemplaire(nombreExemplaires);
    solde+=stock[referenceProduit]->getPrixvente()*nombreExemplaires;
}
void Magasin::bilan()
{
    cout<<"*******************Bilan du magasin**************************"<<endl;
    for(Produit *p:stock)
    {
        cout<<p->getNom()<<" "<<p->getNombreExemplaire()<<endl;
        p->afficherDescription();
    }
    cout<<"Le solde du magasin est de "<<fixed<<setprecision(2)<<solde<<endl;
}

const vector<Produit *> &Magasin::getStock() const {
    return stock;
}

float Magasin::getSolde() const {
    return solde;
}

Magasin::~Magasin() {
    for(Produit *p:stock)
    {
        delete(p); //on détruit tous les pointeurs crées avec le new
    }

}


