//
// Created by eric on 04/09/2020.
//

#ifndef TPCOMMERCE_CD_H
#define TPCOMMERCE_CD_H

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;
class Cd:public Produit {
private:
    string interprete;
    string auteur;
    vector<string> listepistes;
public:
    Cd(const string &nom, float prixachat,  float prixvente, const string &interprete, const string &auteur,
       const vector<string> &listepistes);
    void afficherDescription() override;

};


#endif //TPCOMMERCE_CD_H
