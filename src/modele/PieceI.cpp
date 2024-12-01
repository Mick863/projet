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
    // Calcule l'état de rotation suivant
    int nouvelEtatRotation = (rotationState + 1) % 2;

    // Calcule les nouvelles positions des blocs selon l'état de rotation suivant
    std::vector<Position> nouvellesPositions;
    Position basePosition = caseCourrante->getPosition(); // Position de la case actuelle

    // Détermine les nouvelles positions des blocs après rotation
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
