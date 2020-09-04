#include <iostream>
#include "Produit.h"
#include "Magasin.h"
#include "Livre.h"
#include "Cd.h"

int main() {
    /***************liste des pistes******************/
    vector<string> lespistes;
    lespistes.push_back("Natacha");
    lespistes.push_back("Le petit bonhomme en mousse");
    /***********Ajout des produits en magasin**********/
    Magasin m;
    m.ajouterProduit("pain", 1.51, 2.33);
    m.ajouterlivre("les vents", 10, 20, "Baudelaire", "Flammarion");
    m.ajouterCd("Les sardines",5,10,"Patrick Sebastien","Patrick Sebastien",lespistes);
    m.acheterProduit(0,1);
    m.acheterProduit(1,1);
    m.acheterProduit(2,1);
    m.bilan();

}