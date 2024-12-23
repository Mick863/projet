#include "/home/dev/projet_lanage_objet/projet/src/modele/Case.hpp"
#include "/home/dev/projet_lanage_objet/projet/src/modele/Position.hpp"
#include "/home/dev/projet_lanage_objet/projet/src/modele/Piece.hpp"
#include "/home/dev/projet_lanage_objet/projet/src/modele/PieceO.hpp"
#include "/home/dev/projet_lanage_objet/projet/src/modele/Plateau.hpp"
#include "/home/dev/projet_lanage_objet/projet/src/modele/config.hpp"

#include <iostream>
#include <cassert>
#include <memory>

void testCaseCreation() {
    Position pos(2, 3);
    auto caseJeu = std::make_shared<Case>(pos, TypeCase::Jeu);
    auto casePaysage = std::make_shared<Case>(pos, TypeCase::Paysage);

    assert(caseJeu->getPosition() == pos);
    assert(caseJeu->getType() == TypeCase::Jeu);
    assert(!caseJeu->getEstOccupee());

    assert(casePaysage->getType() == TypeCase::Paysage);
    std::cout << "Test de création de cases réussi.\n";
}

void testCaseOccupation() {
    Position pos(1, 1);
    auto caseTest = std::make_shared<Case>(pos, TypeCase::Jeu);
    auto plateau = std::make_shared<Plateau>(1);
    auto pieceTest = std::make_shared<PieceO>(caseTest, plateau);

    caseTest->setPieceCourrante(pieceTest);
    assert(caseTest->getEstOccupee());
    assert(caseTest->getPieceCourrante() == pieceTest);

    caseTest->setPieceCourrante(nullptr);
    assert(!caseTest->getEstOccupee());
    std::cout << "Test d'occupation des cases réussi.\n";
}

void testPlateauInitPieces() {
    auto plateau = std::make_shared<Plateau>(1);
    plateau->initPieces();

    auto pieceO = plateau->getPiece(Position(2, 0));
    assert(pieceO != nullptr);
    assert(pieceO->print() == "O");
    std::cout << "Test d'initialisation des pièces réussi.\n";
}

void testPieceODeplacementValide() {
    auto plateau = std::make_shared<Plateau>(1);
    plateau->initPieces();

    auto pieceO = plateau->getPiece(Position(2, 0));
    assert(pieceO != nullptr);

    pieceO->deplacer(Direction::Droite);
    assert(plateau->getPiece(Position(2, 1)) == pieceO);

    pieceO->deplacer(Direction::Gauche);
    assert(plateau->getPiece(Position(2, 0)) == pieceO);

    std::cout << "Test de déplacement valide pour PieceO réussi.\n";
}

void testPieceODeplacementPaysage() {
    auto plateau = std::make_shared<Plateau>(1);
    plateau->initPieces();

    auto pieceO = plateau->getPiece(Position(2, 0));
    assert(pieceO != nullptr);

    pieceO->deplacer(Direction::Haut); // Tentative de déplacement sur une case Paysage
    assert(plateau->getPiece(Position(2, 0)) == pieceO);

    std::cout << "Test de déplacement sur une case Paysage réussi.\n";
}

void testPieceODeplacementHorsLimites() {
    auto plateau = std::make_shared<Plateau>(1);
    plateau->initPieces();

    auto pieceO = plateau->getPiece(Position(2, 0));
    assert(pieceO != nullptr);

    pieceO->deplacer(Direction::Haut); // Hors limites
    pieceO->deplacer(Direction::Haut); // Toujours hors limites

    assert(plateau->getPiece(Position(2, 0)) == pieceO);
    std::cout << "Test de déplacement hors des limites réussi.\n";
}

void testPlateauAffichage() {
    auto plateau = std::make_shared<Plateau>(1);
    plateau->initPieces();

    std::cout << "Affichage du plateau :\n" << *plateau;
    std::cout << "Test d'affichage du plateau réussi.\n";
}

int main() {
    testCaseCreation();
    testCaseOccupation();
    testPlateauInitPieces();
    testPieceODeplacementValide();
    testPieceODeplacementPaysage();
    testPieceODeplacementHorsLimites();
    testPlateauAffichage();

    std::cout << "Tous les tests sont passés avec succès.\n";
    return 0;
}
