//
// Created by eric on 03/09/2020.
//

#include <iostream>
#include "Produit.h"

Produit::Produit(const string &nom, float prixachat, float prixvente) : nom(nom), prixachat(prixachat),
                                                                        prixvente(prixvente) {
    description="Pas de description";
    nombreExemplaire=0;
}

void Produit::afficherDescription() {

    cout<<description<<endl;

}

void Produit::editerDescription(const string &description) {
    Produit::description = description;
}

void Produit::augmenterExemplaire(const int nbex) {
nombreExemplaire+=nbex;
}

void Produit::diminuerxemplaire(const int nbex) {
    nombreExemplaire-=nbex;
}

const string &Produit::getNom() const {
    return nom;
}

void Produit::setNom(const string &nom) {
    Produit::nom = nom;
}

float Produit::getPrixachat() const {
    return prixachat;
}

void Produit::setPrixachat(float prixachat) {
    Produit::prixachat = prixachat;
}

float Produit::getPrixvente() const {
    return prixvente;
}

void Produit::setPrixvente(float prixvente) {
    Produit::prixvente = prixvente;
}

int Produit::getNombreExemplaire() const {
    return nombreExemplaire;
}

void Produit::setNombreExemplaire(int nombreExemplaire) {
    Produit::nombreExemplaire = nombreExemplaire;
}

const string &Produit::getDescription() const {
    return description;
}

void Produit::setDescription(const string &description) {
    Produit::description = description;
}
