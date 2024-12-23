#include "Position.hpp"
#include <stdexcept>
#include "config.hpp"

// Constructeur de la classe Position
Position::Position(int Ligne, int Colonne) {
    if (Ligne < 0 || Ligne >= NB_LIGNES || Colonne < 0 || Colonne >= NB_COLONNES) {
        throw std::out_of_range("Position hors des limites du plateau");
    }
    this->Ligne = Ligne;
    this->Colonne = Colonne;
}

// Constructeur avec validation des limites du plateau
Position::Position(int Ligne, int Colonne, int nbLigne, int nbColonne) {
    if (Ligne < 0 || Ligne >= nbLigne || Colonne < 0 || Colonne >= nbColonne) {
        throw std::out_of_range("Position hors des limites du plateau");
    }
    this->Ligne = Ligne;
    this->Colonne = Colonne;
}

// Accesseur pour obtenir la ligne
int Position::getLigne() const {
    return Ligne;
} 

bool Position::operator==(const Position &p) const{
    return p.getLigne() == Ligne 
                    && p.getColonne() == Colonne;
} 


// Accesseur pour obtenir la colonne
int Position::getColonne() const {
    return Colonne;
}

// Mutateur pour définir la ligne avec validation des limites
void Position::setLigne(int ligne) {
    if (ligne < 0 || ligne >= NB_LIGNES) {
        throw std::out_of_range("Ligne hors des limites du plateau");
    }
    Ligne = ligne;
}

// Mutateur pour définir la colonne avec validation des limites
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
