#include "PieceZ.hpp"

// Constructeur par défaut
PieceZ::PieceZ() : Piece() {
    // Initialisation de la forme Z avec ses rotations
    blocks[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)}; // Orientation initiale
    blocks[1] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)}; // Rotation 90°
    blocks[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)}; // Rotation 180°
    blocks[3] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)}; // Rotation 270°
    rotationState = 0; // Initialement en orientation 0
}

// Constructeur avec initialisation
PieceZ::PieceZ(Case* c) : Piece(c, {}) {
    blocks[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    blocks[1] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
    blocks[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    blocks[3] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    rotationState = 0;
    caseCourrante = c;
}

// Constructeur de copie
PieceZ::PieceZ(const PieceZ& other) : Piece(other.caseCourrante, other.blocks) {
    rotationState = other.rotationState;
}

// Destructeur virtuel
PieceZ::~PieceZ() {
    // Rien de spécial à gérer ici
}

// Méthode pour afficher la pièce sous forme d'une chaîne
std::string PieceZ::print() const {
    return "Z";
}

// Méthode pour effectuer une rotation
void PieceZ::rotation() {
    rotationState = (rotationState + 1) % 4; // Passer à l'état de rotation suivant
    // Met à jour les blocs en fonction du nouvel état
    if (caseCourrante) {
        Position basePosition = caseCourrante->getPosition();
        for (auto& block : blocks[rotationState]) {
            block = Position(basePosition.getLigne() + block.getLigne(), basePosition.getColonne() + block.getColonne());
        }
    }
}

// Surcharge de l'opérateur << pour afficher les détails de la pièce
std::ostream& operator<<(std::ostream& os, const PieceZ& piece) {
    os << "PieceZ - Rotation: " << piece.rotationState << ", Position: ";
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
