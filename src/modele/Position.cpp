#include "Position.hpp"
#include <stdexcept>

Position::Position(int Ligne, int Colonne) {
    if (Ligne < 0 || Ligne >= NB_LIGNES || Colonne < 0 || Colonne >= NB_COLONNES) {
        throw std::out_of_range("Position hors des limites du plateau");
    }
    this->Ligne = Ligne;
    this->Colonne = Colonne;
}

void Position::setLigne(int ligne) {
    if (ligne < 0 || ligne >= NB_LIGNES) {
        throw std::out_of_range("Ligne hors des limites du plateau");
    }
    Ligne = ligne;
}

void Position::setColonne(int colonne) {
    if (colonne < 0 || colonne >= NB_COLONNES) {
        throw std::out_of_range("Colonne hors des limites du plateau");
    }
    Colonne = colonne;
}

// Destructeur virtuel
Position::~Position() {
    // Pas de gestion particulière ici, car aucune mémoire dynamique n'est allouée.
    // Cependant, cela pourrait être nécessaire si des ressources étaient allouées dans le futur.
}

// Opérateur d'assignation
Position& Position::operator=(const Position& p) {
    // Vérifie l'auto-assignation
    if (this != &p) {
        this->Ligne = p.Ligne;
        this->Colonne = p.Colonne;
    }
    return *this; // Retourne l'objet courant pour permettre l'enchaînement des affectations
}

// Surcharge de l'opérateur d'affichage
ostream& operator<<(ostream& out, const Position& position) {
    out << "(" << position.getLigne() << ", " << position.getColonne() << ")";
    return out; // Permet de chaîner les appels à l'opérateur <<
}