#include "PieceT.hpp"
#include "Plateau.hpp"  // Inclure Plateau.hpp ici pour accéder aux méthodes Plateau
#include <iostream>
#include "Position.hpp"

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

// Surcharge de l'opérateur d'affectation
PieceT& PieceT::operator=(const PieceT& other) {
    if (this != &other) {
        Piece::operator=(other); // Appelle l'opérateur d'affectation de la classe de base
        rotationState = other.rotationState;
        caseCourrante = other.caseCourrante;
    }
    return *this;
}

// Surcharge de l'opérateur << pour afficher les détails de la pièce
std::ostream& operator<<(std::ostream& os, const PieceT& piece) {
    os << "PieceT - Rotation: " << piece.rotationState << ", Position: "
       << piece.caseCourrante->getPosition() << ", Blocs: ";
    
    // Afficher les positions des blocs pour chaque état de rotation
    for (const auto& block : piece.blocks) {
        os << "Rotation " << block.first << ": ";
        for (const auto& pos : block.second) {
            os << "(" << pos.getLigne() << ", " << pos.getColonne() << ") ";
        }
    }
    return os;
}

// Méthode pour afficher la pièce sous forme d'une chaîne
string PieceT::print() const {
    return "T";
}

// Méthode pour effectuer une rotation
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

    // Vérifie si les nouvelles positions sont valides (dans les limites du plateau et non occupées)
    for (const auto& pos : nouvellesPositions) {
        // Vérifie si la position est à l'intérieur du plateau
        if (pos.getLigne() < 0 || pos.getLigne() >= plateau->getNbLignes() ||
            pos.getColonne() < 0 || pos.getColonne() >= plateau->getNbColonnes()) {
            // Position hors du plateau, annule la rotation
            return;
        }

        // Vérifie si la case est occupée ou est une case paysage
        try {
            CaseJeu& caseCible = plateau->getCaseJeu(pos);
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

    // Met à jour les positions des blocs de la pièce en fonction de la nouvelle rotation
    blocks[rotationState] = nouvellesPositions;
}

