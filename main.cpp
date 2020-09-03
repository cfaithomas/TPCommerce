#include <iostream>
#include "Produit.h"
#include "Magasin.h"

int main() {
    Produit p("pain", 1, 2);
    p.augmenterExemplaire(2);
    p.afficherDescription();
    p.editerDescription("Levain");
    cout << p.getNom() << " " << p.getDescription() << " " << p.getNombreExemplaire() << " " << p.getPrixachat() << " "
         << p.getPrixvente() << endl;
    Magasin m;
    m.ajouterProduit("pain", 1, 2);
    m.acheterProduit(0,2);
    m.bilan();
    m.vendreProduit(0,1);
    m.bilan();
}