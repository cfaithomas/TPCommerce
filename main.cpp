#include <iostream>
#include "Produit.h"
#include "Magasin.h"
#include "Livre.h"

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

}