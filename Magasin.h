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
    void acheterProduit(int referenceProduit,int nombreExemplaires);
    void vendreProduit(int referenceProduit, int  nombreExemplaires);

    const vector<Produit *> &getStock() const;

    float getSolde() const;

    void bilan();
};


#endif //TPCOMMERCE_MAGASIN_H
