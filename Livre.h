//
// Created by eric on 04/09/2020.
//

#ifndef TPCOMMERCE_LIVRE_H
#define TPCOMMERCE_LIVRE_H


#include "Produit.h"

class Livre: public Produit {
private:
    string editeur;
    string auteur;
public:
    Livre(const string &nom,float prixachat,float prixvente,const string &auteur,const string &editeur);

    void afficherDescription() override;

};


#endif //TPCOMMERCE_LIVRE_H
