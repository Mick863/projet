#include "PieceT.hpp"
#include <iostream>

// Constructeur par défaut
PieceT::PieceT() : Piece() {
    // Initialisation de la forme T avec ses rotations
    blocks[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)}; // Orientation initiale
    blocks[1] = {Position(0, 1), Position(1, 1), Position(1, 0), Position(2, 1)}; // Rotation 90°
    blocks[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation 180°
    blocks[3] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation 270°
    rotationState = 0; // Initialement en orientation 0
}

// Constructeur avec initialisation
PieceT::PieceT(Case* c) : Piece(c, {}) {
    blocks[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    blocks[1] = {Position(0, 1), Position(1, 1), Position(1, 0), Position(2, 1)};
    blocks[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    blocks[3] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    rotationState = 0;
    caseCourrante = c;
}

// Constructeur de copie
PieceT::PieceT(const PieceT& other) : Piece(other.caseCourrante, other.blocks) {
    rotationState = other.rotationState;
}

// Destructeur virtuel
PieceT::~PieceT() {
    // Rien de particulier à libérer
}

std::string PieceT::print() const {
    return "T";
}

// Méthode pour effectuer une rotation
void PieceT::rotation() {
    rotationState = (rotationState + 1) % 4; // Passe à l'état de rotation suivant
    // Ajuste les positions des blocs en fonction de la nouvelle rotation
    if (caseCourrante) { 
        Position basePosition = caseCourrante->getPosition();
        for (auto& block : blocks[rotationState]) {
            block = Position(basePosition.getLigne() + block.getLigne(), basePosition.getColonne() + block.getColonne());
        }
    }
}

// Surcharge de l'opérateur << pour afficher
