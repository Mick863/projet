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

void PieceL::rotation() {
    // Calcule l'état de rotation suivant
    int nouvelEtatRotation = (rotationState + 1) % 4; // L'état de rotation passe de 0 à 3 (4 rotations possibles)

    // Calcule les nouvelles positions des blocs selon le nouvel état de rotation
    std::vector<Position> nouvellesPositions;
    Position basePosition = caseCourrante->getPosition(); // Position de la case actuelle

    // Détermine les nouvelles positions des blocs après rotation
    for (const auto& block : blocks[nouvelEtatRotation]) {
        Position nouvellePos(basePosition.getLigne() + block.getLigne(), basePosition.getColonne() + block.getColonne());
        nouvellesPositions.push_back(nouvellePos);
    }

    // Vérifie si les nouvelles positions sont valides (dans les limites du plateau et non occupées)
    for (const auto& pos : nouvellesPositions) {
        // Vérifie si la position est à l'intérieur du plateau
        if (pos.getLigne() < 0 || pos.getLigne() >= plateau.getNbLignes() ||
            pos.getColonne() < 0 || pos.getColonne() >= plateau.getNbColonnes()) {
            // Position hors du plateau, annule la rotation
            return;
        }

        // Vérifie si la case est occupée ou est une case paysage
        try {
            CaseJeu& caseCible = plateau.getCaseJeu(pos);
            if (caseCible.getEstOccupe() || dynamic_cast<CasePaysage*>(&caseCible)) {
                // La case est occupée ou est une case paysage, annule la rotation
                return;
            }
        } catch (const std::runtime_error& e) {
            // Si la case n'est pas une CaseJeu, on passe à la prochaine vérification
            // Si la case est de type CasePaysage ou autre, on l'ignore.
            continue;
        }
    }

    // Si toutes les vérifications sont passées, applique la rotation
    rotationState = nouvelEtatRotation; // Met à jour l'état de rotation

    // Met à jour les positions des blocs de la pièce en fonction de la nouvelle rotation
    blocks[rotationState] = nouvellesPositions;
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
