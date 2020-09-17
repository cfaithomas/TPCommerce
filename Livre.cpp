//
// Created by eric on 04/09/2020.
//

#include <iostream>
#include "Livre.h"

Livre::Livre(const string &nom, float prixachat, float prixvente, const string &auteur, const string &editeur):
Produit(nom,prixachat,prixvente),auteur(auteur),editeur(editeur) {

}

void Livre::afficherDescription() {
    Produit::afficherDescription();
    cout<<"Auteur:"<<auteur<<" Editeur:"<<editeur<<endl;
}
