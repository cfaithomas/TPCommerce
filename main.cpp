#include <iostream>
#include "Produit.h"

int main() {
Produit p("pain",1,2);
p.augmenterExemplaire(2);
p.afficherDescription();
p.editerDescription("Levain");
cout<<p.getNom()<<" "<<p.getDescription()<<" "<<p.getNombreExemplaire()<<" "<<p.getPrixachat()<<" "<<p.getPrixvente()<<endl;
}
