#include "PieceL.hpp"
#include <iostream>

// Constructeur par défaut
PieceL::PieceL() : Piece() {
    // Initialisation de la forme L avec ses rotations
    blocks[0] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1)}; // Orientation initiale
    blocks[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 0)}; // Rotation 90°
    blocks[2] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)}; // Rotation 180°
    blocks[3] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(0, 2)}; // Rotation 270°
    rotationState = 0; // Initialement en orientation 0
}

// Constructeur avec initialisation
PieceL::PieceL(Case* c) : Piece(c, {}) {
    blocks[0] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1)};
    blocks[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 0)};
    blocks[2] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
    blocks[3] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(0, 2)};
    rotationState = 0;
    caseCourrante = c;
}

// Constructeur de copie
PieceL::PieceL(const PieceL& other) : Piece(other.caseCourrante, other.blocks) {
    rotationState = other.rotationState;
}

// Destructeur virtuel
PieceL::~PieceL() {
    // Rien de particulier à libérer
}

// Méthode pour afficher la pièce sous forme d'une chaîne
std::string PieceL::print() const {
    return "L";
}

// Méthode pour effectuer une rotation
void PieceL::rotation() {
    rotationState = (rotationState + 1) % 4; // Passe à l'état de rotation suivant
    // Ajuste les positions des blocs en fonction de la nouvelle rotation
    if (caseCourrante) {
        Position basePosition = caseCourrante->getPosition();
        for (auto& block : blocks[rotationState]) {
            block = Position(basePosition.getLigne() + block.getLigne(), basePosition.getColonne() + block.getColonne());
        }
    }
}

// Surcharge de l'opérateur << pour afficher les détails de la pièce
std::ostream& operator<<(std::ostream& os, const PieceL& piece) {
    os << "PieceL - Rotation: " << piece.rotationState << ", Position: ";
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
