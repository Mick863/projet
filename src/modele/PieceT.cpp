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

void PieceT::rotation() {
    // Calcule l'état de rotation suivant (4 états possibles pour la pièce T)
    int nouvelEtatRotation = (rotationState + 1) % 4;

    // Calcule les nouvelles positions des blocs selon le nouvel état de rotation
    std::vector<Position> nouvellesPositions;
    Position basePosition = caseCourrante->getPosition(); // Position de la case actuelle

    // Détermine les nouvelles positions des blocs après la rotation
    for (const auto& block : blocks[nouvelEtatRotation]) {
        Position nouvellePos(basePosition.getLigne() + block.getLigne(), basePosition.getColonne() + block.getColonne());
        nouvellesPositions.push_back(nouvellePos);
    }

    // Vérifie si les nouvelles positions sont valides (dans les limites et non occupées)
    for (const auto& pos : nouvellesPositions) {
        // Vérifie si la position est à l'intérieur du plateau
        if (pos.getLigne() < 0 || pos.getLigne() >= plateau.getNbLignes() ||
            pos.getColonne() < 0 || pos.getColonne() >= plateau.getNbColonnes()) {
            // Position hors du plateau, annule la rotation
            return;
        }

        // Vérifie si la case est occupée ou est une case paysage
        CaseJeu& caseCible = plateau.getCaseJeu(pos);
        if (caseCible.getEstOccupe() || dynamic_cast<CasePaysage*>(&caseCible)) {
            // La case est occupée ou est une case paysage, annule la rotation
            return;
        }
    }

    // Si toutes les vérifications sont passées, applique la rotation
    rotationState = nouvelEtatRotation; // Met à jour l'état de rotation

    // Met à jour les positions des blocs de la pièce en fonction de la nouvelle rotation
    blocks[rotationState] = nouvellesPositions;
}


