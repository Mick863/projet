#include "PieceI.hpp"
#include <iostream>

// Constructeur par défaut
PieceI::PieceI() : Piece() {
    // Initialisation de la forme I avec ses rotations
    blocks[0] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}; // Orientation verticale
    blocks[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(0, 3)}; // Orientation horizontale
    rotationState = 0; // Orientation initiale
}

// Constructeur avec initialisation
PieceI::PieceI(Case* c) : Piece(c, {}) {
    blocks[0] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)};
    blocks[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(0, 3)};
    rotationState = 0;
    caseCourrante = c;
}

// Constructeur de copie
PieceI::PieceI(const PieceI& other) : Piece(other.caseCourrante, other.blocks) {
    rotationState = other.rotationState;
}

// Destructeur virtuel
PieceI::~PieceI() {
    // Rien de particulier à libérer
}

// Méthode pour afficher la pièce sous forme d'une chaîne
std::string PieceI::print() const {
    return "I";
}

// Méthode pour effectuer une rotation
void PieceI::rotation() {
    rotationState = (rotationState + 1) % 2; // Passe à l'état de rotation suivant (0 ou 1)
    // Ajuste les positions des blocs en fonction de la nouvelle rotation
    if (caseCourrante) {
        Position basePosition = caseCourrante->getPosition();
        for (auto& block : blocks[rotationState]) {
            block = Position(basePosition.getLigne() + block.getLigne(), basePosition.getColonne() + block.getColonne());
        }
    }
}

// Surcharge de l'opérateur << pour afficher les détails de la pièce
std::ostream& operator<<(std::ostream& os, const PieceI& piece) {
    os << "PieceI - Rotation: " << piece.rotationState << ", Position: ";
    if (piece.caseCourrante) {
        os << "(" << piece.caseCourrante->getPosition().getLigne() << ", "
           << piece.caseCourrante->getPosition().getColonne() << ")";
    } else {
        os << "Aucune case courante";
    }
    os << ", Blocs: ";
    for (const auto& pos : piece.blocks.at(piece.rotationState)) {
        os << "(" << pos.getLigne() << ", " << pos.getColonne() << ") ";
    }
    return os;
}
