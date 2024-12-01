#include "Jeu.hpp"
#include "Piece.hpp"
#include <iostream>
#include <stdexcept>

// Constructeur
Jeu::Jeu() : plateau(0), jeuTermine(false) {
    // Initialisation du plateau
    for (int i = 0; i < 5; ++i) {
        std::vector<Case> ligne;
        for (int j = 0; j < 10; ++j) {
            if (i < 2 || i > 3) {
                // Les deux premières et les deux dernières lignes sont des cases paysages
                ligne.emplace_back(CasePaysage(Position(i, j), Color::Bleu));
            } else {
                // Les deux lignes du milieu sont des cases de jeu
                ligne.emplace_back(CaseJeu(Position(i, j), Color::Blanc));
            }
        }
        plateau.getPlateau().push_back(ligne);
    }

    // Définir la case gagnante
    plateau.getPlateau()[2][4] = CaseGagnante(Position(2, 4), Color::Rouge);

    // Initialisation de la pièce O à la position (2, 0)
    piece = new PieceO(&plateau.getCaseJeu(Position(2, 0))); // Allocation dynamique
    plateau.ajouterPiece(piece, Position(2, 0)); // Passer le pointeur
}

// Lancer la simulation du jeu
void Jeu::lancer() {
    while (!jeuTermine) {
        std::cout << plateau.print() << std::endl; // Affiche le plateau

        // Demander au joueur une direction
        std::cout << "Entrez une direction (Haut, Bas, Gauche, Droite): ";
        std::string directionInput;
        std::cin >> directionInput;

        Direction direction;

        // Convertir l'entrée utilisateur en Direction
        if (directionInput == "Haut") {
            direction = Direction::Haut;
        } else if (directionInput == "Bas") {
            direction = Direction::Bas;
        } else if (directionInput == "Gauche") {
            direction = Direction::Gauche;
        } else if (directionInput == "Droite") {
            direction = Direction::Droite;
        } else {
            std::cout << "Direction invalide. Réessayez." << std::endl;
            continue;
        }

        // Déplacer la pièce
        piece->deplacer(direction);

        // Vérifier si la pièce a atteint la case gagnante
        Position positionCourante = piece->getCaseCourrante()->getPosition();
        CaseJeu& caseCourrante = plateau.getCaseJeu(positionCourante);

        // Vérifier si la case est de type Gagnante
        if (caseCourrante.getType() == CaseType::Gagnante) {
            jeuTermine = true;
            std::cout << "Félicitations ! Vous avez atteint la case gagnante !" << std::endl;
        }
    }
}

Jeu::~Jeu(){
    delete piece;
}