#include <iostream>
#include "Produit.h"
#include "Magasin.h"
#include "Livre.h"
#include "Cd.h"

int main() {

    /*Magasin m;
    m.ajouterProduit("pain", 1.51, 2.33);
    m.acheterProduit(0,2);
    m.bilan();
    m.vendreProduit(0,1);
    m.bilan();*/
    Livre livre( "les vents", 10, 20, "Baudelaire", "Flammarion");
    livre.editerDescription("Roman");
    livre.afficherDescription();
    vector<string> lespistes;
    lespistes.push_back("Natacha");
    lespistes.push_back("Le petit bonhomme en mousse");
    Cd cd1("Les sardines",5,10,"Patrick Sebastien","Patrick Sebastien",lespistes);
    cd1.afficherDescription();

}