#include "PieceO.hpp"
#include "Piece.hpp"
#include "Position.hpp"
#include "Case.hpp"
#include <iostream>

using namespace std;

// Constructeur par défaut
PieceO::PieceO() : Piece(nullptr, {{0, {Position(0, 0)}}}) {
    rotationState = 0; // Le carré reste toujours le même
}

// Constructeur avec initialisation
PieceO::PieceO(Case* c) : Piece(c, {{0, {Position(0, 0)}}}) {
    rotationState = 0; // Toujours 0 car PieceO ne change pas en fonction de la rotation
}

// Constructeur de copie
PieceO::PieceO(const PieceO& other) : Piece(other.caseCourrante, other.blocks) {
    rotationState = other.rotationState;
    caseCourrante = other.caseCourrante;
}

// Destructeur
PieceO::~PieceO() {
    // Rien de particulier à libérer
}

// Surcharge de l'opérateur d'affectation
PieceO& PieceO::operator=(const PieceO& other) {
    if (this != &other) {
        Piece::operator=(other); // Appelle l'opérateur d'affectation de la classe de base
        rotationState = other.rotationState;
        caseCourrante = other.caseCourrante;
    }
    return *this;
}

// Surcharge de l'opérateur << pour afficher les détails de la pièce
std::ostream& operator<<(std::ostream& os, const PieceO& piece) {
    os << "PieceO - Rotation: " << piece.rotationState << ", Position: "
       << piece.caseCourrante->getPosition() << ", Blocs: ";
    
    // Afficher les positions des blocs pour chaque état de rotation (toujours identiques)
    for (const auto& block : piece.blocks) {
        os << "Rotation " << block.first << ": ";
        for (const auto& pos : block.second) {
            os << "(" << pos.getLigne() << ", " << pos.getColonne() << ") ";
        }
    }
    return os;
}

// Méthode pour afficher la pièce sous forme d'une chaîne
string PieceO::print() const {
    return "O";
}

// Méthode pour effectuer une rotation
void PieceO::rotation() {
    // La pièce O ne change pas de forme lors de la rotation, donc rien à faire
    // rotationState peut rester 0.
    // Si nécessaire, tu peux ajouter un comportement spécial.
}


