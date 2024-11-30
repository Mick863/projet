#include "Case.hpp"
#include "Position.hpp"
#include <iostream>

// Constructeurs
Case::Case()
    : position(nullptr), estOccupe(false), couleur(Color::Bleu), taille(1) , piece(nullptr){}

Case::Case(Position pos, Color couleur , Piece * piece)
    : position(new Position(pos)), estOccupe(false), couleur(couleur), taille(1) , piece(piece) {}

// Destructeur
Case::~Case() {
    delete position; // Libère la mémoire allouée à l'objet Position
}

// Méthodes concrètes
bool Case::getEstOccupe() const {
    return estOccupe;
}

Color Case::getCouleur() const {
    return couleur;
}

int Case::getTaille() const {
    return taille;
}

Position Case::getPosition() const {
    if (position != nullptr) {
        return *position;
    }
    return Position(-1, -1); // Retourne une position invalide si non initialisée
}

void Case::setEstOccupe(bool b) {
    estOccupe = b;
}

void Case::print(std::ostream& os) const {
    os << "Case [Position: ";
    if (position != nullptr) {
        os << "(" << position->getLigne() << ", " << position->getColonne() << ")";
    } else {
        os << "Non définie";
    }
    os << ", Couleur: " << static_cast<int>(couleur)
       << ", Occupée: " << (estOccupe ? "Oui" : "Non")
       << ", Taille: " << taille << "]";
}

void Case::setPiece(Piece * piece){
    if(!estOccupe){
        this -> piece = piece;
    }   
}
