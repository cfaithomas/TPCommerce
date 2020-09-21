//
// Created by eric on 03/09/2020.
//

#include <iostream>
#include <iomanip>
#include "Magasin.h"
#include "Cd.h"
#include "Livre.h"

Magasin::Magasin() {
    solde=100;
}

void Magasin::ajouterProduit(const string &nom, float prixachat, float prixvente) {
    stock.push_back(new Produit(nom,prixachat,prixvente));
}

void Magasin::acheterProduit(int referenceProduit, int nombreExemplaires) {
    stock[referenceProduit]->augmenterExemplaire(nombreExemplaires);
    solde-=stock[referenceProduit]->getPrixachat()*nombreExemplaires;
}

void Magasin::vendreProduit(int referenceProduit, int nombreExemplaires) {
    stock[referenceProduit]->diminuerxemplaire(nombreExemplaires);
    solde+=stock[referenceProduit]->getPrixvente()*nombreExemplaires;
}

void Magasin::bilan()
{
    cout<<"*******************Bilan du magasin**************************"<<endl;
    for(Produit *p:stock)
    {
        cout<<"NOM:"<<" "<<p->getNom()<<" Nombre d'exemplaires: "<<p->getNombreExemplaire()<<endl;
        p->afficherDescription();
        cout<<"***************************************************************"<<endl;
    }
    cout<<"Le solde du magasin est de "<<fixed<<setprecision(2)<<solde<<endl;
}

const vector<Produit *> &Magasin::getStock() const {
    return stock;
}

float Magasin::getSolde() const {
    return solde;
}

Magasin::~Magasin() {
    for(Produit *p:stock)
    {
        delete(p); //on détruit tous les pointeurs crées avec le new
    }

}

void
Magasin::ajouterCd(const string &nom, float prixachat, float prixvente, const string &interprete, const string &auteur,
                   const vector<string> &listepistes) {
    stock.push_back(new Cd(nom,prixvente,prixachat,interprete,auteur,listepistes));
}

void Magasin::ajouterlivre(const string &nom, float prixachat, float prixvente, const string &auteur,
                           const string &editeur) {
    stock.push_back(new Livre(nom,prixachat,prixvente,auteur,editeur));
}

void Magasin::interaction() {
    int saisie=0;
    cout<<"1-opération Produit \n";
    cout<<"2-opération Livre \n";
    cout<<"3-opération CD \n";
    cout<<"4-Afficher un bilan\n";
    cin>>saisie;
    switch(saisie)
    {
        case 1:
            this->submenu("produit");
            break;

        case 2:

            this->submenu("livre");
            break;
        case 3:

            this->submenu("cd");
            break;
        case 4:
            this->bilan();
            break;
    }
    interaction();
}

void Magasin::submenu(const string &type) {
    int saisie=0;


    cout<<"1-Vendre un "<<type<<"\n";
    cout<<"2-Acheter un "<<type<<"\n";
    cout<<"3-Afficher la description d'un "<<type<<"\n";
    cout<<"4-Ajouter un "<<type<<"\n";
    cout<<"5-Editer la description\n";
    cout<<"6-Retour au menu principal\n";
    cin>>saisie;
    switch(saisie) {
        case 1:
            while(true) {
                try {
                    vendreProduit(this->choixproduit(type), this->choixqte());
                    break; //casse la boucle si pas d'exception
                }
                    catch (logic_error & le)
                    {
                        cin.clear(); //remet cin en état ok
                        cout << le.what() << endl;
                    }
                }
        break; //break case

        case 2:
            while(true) {
                try {
                    acheterProduit(this->choixproduit(type), this->choixqte());
                    break;
                }
                catch (logic_error &le) {
                    cin.clear(); //remet cin en état ok
                    cout << le.what() << endl;
                }
            }
            break;
        case 3:
            stock[choixproduit(type)]->afficherDescription();
            break;

        case 4:
            while (true) {
                try {
                    if (type == "produit") {


                        this->ajouterProduit(this->saisieinformation("nom"), this->saisieprix("achat"),
                                             this->saisieprix("vente"));

                    }
                 else if (type == "livre") {
                    while (true) {
                        this->ajouterlivre(saisieinformation("nom"), saisieprix("achat"), this->saisieprix("vente"),
                                           this->saisieinformation("editeur"), this->saisieinformation("auteur"));

                    }
                } else {
                    while (true) {
                        this->ajouterCd(saisieinformation("nom"), saisieprix("achat"), this->saisieprix("vente"),
                                        this->saisieinformation("auteur"), this->saisieinformation("editeur"),
                                        this->saisielistetitre());

                    }
                }
            break;
            } catch (logic_error & le)
            {
                cin.clear(); //remet cin en état ok
                cout << le.what() << endl;
            }
    }

            break;
        case 5:
            stock[choixproduit(type)]->editerDescription(this->saisieinformation("nouvelle description"));
            break;

        case 6:
            interaction();



    }
    submenu(type);
}
int Magasin::choixproduit(const string &type) {
    int saisie=0;
    cin.ignore(256,'\n'); //ignore ce qui q été précedemment saisi
    cout<<"Veuillez donner le numéro du "<<type<<endl;
    cin>>saisie;
    if (saisie<0||cin.fail())
        throw logic_error("le numéro doit être positif ou égale à zéro et numérique");
    return saisie;
}

int Magasin::choixqte() {
    int saisie=0;
    cin.ignore(256,'\n'); //ignore ce qui q été précedemment saisi
    cout<<"Quelle quantité"<<endl;
    cin>>saisie;
    if (saisie<= 0||cin.fail())
        throw logic_error("le quantité doit être au minimum de 1 et numérique");
    return saisie;
}

const string Magasin::saisieinformation(const string &type) {
    string saisie="";
    cout<<"Veuillez saisir l'information pour "<<type<<endl;
    cin>>saisie;
    return saisie;



}

float Magasin::saisieprix(const string &type)
{
    float prix=0;
    cin.ignore(256,'\n'); //ignore ce qui q été précedemment saisi
    cout << "Veuillez saisir prix " << type << "\n";
    cin >> prix;
    if (prix < 0||cin.fail())
        throw logic_error("le prix doit être positif et numérique");
    return prix;
}

vector<string> Magasin::saisielistetitre() {
    vector<string> listetitres;
    string saisie="";
    int i=0;
    while(saisie!="F")
    {
        cout<<"Veuillez saisir un titre ou (F) pour fin"<<endl;
        cin>>saisie;
        listetitres.push_back(saisie);
    }
    return listetitres;
}



