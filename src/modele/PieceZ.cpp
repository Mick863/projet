#include "PieceZ.hpp"
#include "Plateau.hpp"  // Inclure Plateau.hpp ici pour utiliser ses méthodes
#include <iostream>

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

// Surcharge de l'opérateur d'affectation
PieceZ& PieceZ::operator=(const PieceZ& other) {
    if (this != &other) {
        Piece::operator=(other);  // Appelle l'opérateur d'affectation de la classe de base
        rotationState = other.rotationState;
        caseCourrante = other.caseCourrante;
    }
    return *this;
}

// Méthode pour afficher la pièce sous forme d'une chaîne
std::string PieceZ::print() const {
    return "Z";
}

// Méthode pour effectuer une rotation
void PieceZ::rotation() {
    // Calcule l'état de rotation suivant (la pièce Z a 4 états de rotation)
    int nouvelEtatRotation = (rotationState + 1) % 4;

    // Calcule les nouvelles positions des blocs selon le nouvel état de rotation
    std::vector<Position> nouvellesPositions;
    Position basePosition = caseCourrante->getPosition(); // Position de la case courante

    // Détermine les nouvelles positions des blocs après la rotation
    for (const auto& block : blocks[nouvelEtatRotation]) {
        Position nouvellePos(basePosition.getLigne() + block.getLigne(), basePosition.getColonne() + block.getColonne());
        nouvellesPositions.push_back(nouvellePos);
    }

    // Vérifie si les nouvelles positions sont valides (dans les limites du plateau et non occupées)
    for (const auto& pos : nouvellesPositions) {
        // Vérifie si la position est à l'intérieur du plateau
        if (pos.getLigne() < 0 || pos.getLigne() >= plateau->getNbLignes() ||  // Utilisez "->" ici
            pos.getColonne() < 0 || pos.getColonne() >= plateau->getNbColonnes()) {  // Utilisez "->" ici
            // Position hors du plateau, annule la rotation
            return;
        }

        // Vérifie si la case est occupée ou est une case paysage
        try {
            CaseJeu& caseCible = plateau->getCaseJeu(pos);  // Utilisez "->" ici
            if (caseCible.getEstOccupe() || dynamic_cast<CasePaysage*>(&caseCible)) {
                // La case est occupée ou est une case paysage, annule la rotation
                return;
            }
        } catch (const std::runtime_error& e) {
            // Si la case n'est pas une CaseJeu (peut-être une CasePaysage), continue la vérification
            continue;
        }
    }

    // Si toutes les vérifications sont passées, applique la rotation
    rotationState = nouvelEtatRotation; // Met à jour l'état de rotation

    // Met à jour les positions des blocs de la pièce en fonction du nouvel état de rotation
    blocks[rotationState] = nouvellesPositions;
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
