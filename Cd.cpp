//
// Created by eric on 04/09/2020.
//

#include <iostream>
#include "Cd.h"

Cd::Cd(const string &nom, float prixachat, float prixvente, const string &interprete, const string &auteur,
       const vector<string> &listepistes) : Produit(nom, prixachat, prixvente), interprete(interprete), auteur(auteur),
                                            listepistes(listepistes) {}

void Cd::afficherDescription() {
    Produit::afficherDescription();
    cout<<interprete<<" "<<auteur<<endl;
    for(int i=0;i<listepistes.size();i++)
    {
        cout<<i<<")"<<listepistes[i]<<endl;
    }
}
