#include "PieceO.hpp"
#include "Case.hpp"
#include "Plateau.hpp"
#include <iostream>

PieceO::PieceO(const std::weak_ptr<Case>& c, const std::weak_ptr<Plateau>& p)
    : Piece(c, {{0, {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)}}}, p, 0) {}

std::string PieceO::print() const {
    return "O";
}

void PieceO::deplacer(Direction direction) {
    auto caseActuelle = getCaseCourrante();
    auto plateauActuel = getPlateau();

    if (!caseActuelle || !plateauActuel) {
        std::cerr << "Erreur : Déplacement impossible, la pièce n'est pas associée à une case ou un plateau.\n";
        return;
    }

    Position newPos = caseActuelle->getPosition();
    switch (direction) {
        case Direction::Haut:    newPos.setLigne(newPos.getLigne() - 1); break;
        case Direction::Bas:     newPos.setLigne(newPos.getLigne() + 1); break;
        case Direction::Gauche:  newPos.setColonne(newPos.getColonne() - 1); break;
        case Direction::Droite:  newPos.setColonne(newPos.getColonne() + 1); break;
    }

    if (!plateauActuel->estPositionValide(newPos)) {
        std::cerr << "Erreur : Déplacement hors limites.\n";
        return;
    }

    auto nouvelleCase = plateauActuel->getCase(newPos);
    if (nouvelleCase && !nouvelleCase->getEstOccupee() && nouvelleCase->getType() != TypeCase::Paysage) {
        caseActuelle->setPieceCourrante(nullptr);
        nouvelleCase->setPieceCourrante(shared_from_this());
        caseCourrante = nouvelleCase;
    } else {
        std::cerr << "Erreur : Déplacement impossible.\n";
    }
}

void PieceO::rotation() {
    rotationState = 0;
}

bool PieceO::estDehors() const {
    auto caseActuelle = getCaseCourrante();
    auto plateauActuel = getPlateau();

    if (!caseActuelle || !plateauActuel) {
        return true;
    }

    return !plateauActuel->estPositionValide(caseActuelle->getPosition());
}

