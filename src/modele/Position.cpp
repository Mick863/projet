#include "Position.hpp"
#include <iostream>


Position::Position(int Ligne, int Colonne) : Ligne(Ligne), Colonne(Colonne) {}

int Position::getLigne() const {
        return Ligne;
}

int Position::getColonne() const {
        return Colonne;
}

Position::~Position() {}

Position& Position::operator=(const Position& p) {
    if (this != &p) { 
        Ligne = p.Ligne;
        Colonne = p.Colonne;
    }
    return *this;
}

ostream & operator<<(std::ostream& out, const Position& position) {
    out << "(" << position.Ligne << ", " << position.Colonne << ")";
    return out;
}




