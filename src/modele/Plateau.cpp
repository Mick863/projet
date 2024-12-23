#include "Plateau.hpp"
#include "PieceO.hpp"
#include <iostream>

Plateau::Plateau(int niveau) : niveau(niveau) {
    nbLigne = 5;
    nbColonne = 5;
    cases.resize(nbLigne);

    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            Position pos(i, j);
            if (i == 2 && j == 4) {
                cases[i].push_back(std::make_shared<Case>(pos, TypeCase::Gagnante));
            } else if (i == 2) {
                cases[i].push_back(std::make_shared<Case>(pos, TypeCase::Jeu));
            } else {
                cases[i].push_back(std::make_shared<Case>(pos, TypeCase::Paysage));
            }
        }
    }
}

void Plateau::initPieces() {
    auto caseInitiale = getCase(Position(2, 0));
    if (!caseInitiale) {
        throw std::runtime_error("Erreur : Case initiale introuvable");
    }

    auto pieceO = std::make_shared<PieceO>(caseInitiale, shared_from_this());
    ajouterPiece(pieceO, Position(2, 0));
}

void Plateau::ajouterPiece(const std::shared_ptr<Piece>& piece, const Position& position) {
    if (!estPositionValide(position)) {
        throw std::runtime_error("Erreur : La position est invalide.");
    }

    auto targetCase = getCase(position);
    if (!targetCase) {
        throw std::runtime_error("Erreur : Case introuvable.");
    }

    if (targetCase->getType() == TypeCase::Paysage) {
        throw std::runtime_error("Erreur : Impossible de placer une pièce sur une case de type Paysage.");
    }

    if (targetCase->getEstOccupee()) {
        throw std::runtime_error("Erreur : La case est déjà occupée.");
    }

    targetCase->setPieceCourrante(piece);
    pieces.push_back(piece);

    std::cout << "Pièce ajoutée à la position (" 
              << position.getLigne() << ", " 
              << position.getColonne() << ").\n";
}

std::shared_ptr<Case> Plateau::getCase(const Position& position) const {
    if (estPositionValide(position)) {
        return cases[position.getLigne()][position.getColonne()];
    }
    return nullptr;
}

std::shared_ptr<Piece> Plateau::getPiece(const Position& position) const {
    auto targetCase = getCase(position);
    if (targetCase) {
        return targetCase->getPieceCourrante();
    }
    return nullptr;
}

bool Plateau::movePiece(const Position& from, const Position& to) {
    if (!estPositionValide(from) || !estPositionValide(to)) {
        return false;
    }

    auto caseFrom = getCase(from);
    auto caseTo = getCase(to);

    if (caseFrom && caseTo && caseFrom->getPieceCourrante()) {
        caseTo->setPieceCourrante(caseFrom->getPieceCourrante());
        caseFrom->setPieceCourrante(nullptr);
        return true;
    }
    return false;
}

bool Plateau::estPositionValide(const Position& pos) const {
    return pos.getLigne() >= 0 && pos.getLigne() < nbLigne &&
           pos.getColonne() >= 0 && pos.getColonne() < nbColonne;
}

std::ostream& operator<<(std::ostream& out, const Plateau& plateau) {
    for (int i = 0; i < plateau.nbLigne; ++i) {
        for (int j = 0; j < plateau.nbColonne; ++j) {
            auto c = plateau.cases[i][j];
            if (c->getType() == TypeCase::Paysage) {
                out << "X "; // Case de type Paysage.
            } else if (c->getType() == TypeCase::Gagnante) {
                out << ". "; // Case gagnante affichée comme vide.
            } else if (auto piece = c->getPieceCourrante()) {
                out << piece->print() << " "; // Représentation de la pièce.
            } else {
                out << ". "; // Case vide de type Jeu.
            }
        }
        out << "\n";
    }
    return out;
}