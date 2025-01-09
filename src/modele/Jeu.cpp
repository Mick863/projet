#include "Plateau.hpp"
#include <iostream>
#include <string>

int main() {
    auto plateau = std::make_shared<Plateau>(1); // Initialisation du plateau.
    plateau->initPieces(); // Ajout de la pièce O à sa position initiale.

    std::string commande;
    bool partieEnCours = true;

    // Position actuelle de la pièce O.
    Position positionActuelle(2, 0);

    std::cout << "Bienvenue dans le jeu !\n";
    std::cout << "Votre objectif est d'amener la pièce O à la case gagnante.\n";
    std::cout << "Commandes disponibles : '1 : Aller à gauche', '2 : Aller à droite'.\n\n";

    while (partieEnCours) {
        std::cout << *plateau; // Affiche l'état actuel du plateau.
        std::cout << "Entrez une commande : ";
        std::getline(std::cin, commande);

        auto pieceO = plateau->getPiece(positionActuelle); // Récupérer la pièce à sa position actuelle.
        if (!pieceO) {
            std::cout << "Erreur : Pièce O introuvable.\n";
            break;
        }

        // Vérification et exécution de la commande.
        if (commande == "1") { // Aller à gauche
            pieceO->deplacer(Direction::Gauche);
            positionActuelle.setColonne(positionActuelle.getColonne() - 1); // Mettre à jour la position actuelle.
        } else if (commande == "2") { // Aller à droite
            pieceO->deplacer(Direction::Droite);
            positionActuelle.setColonne(positionActuelle.getColonne() + 1); // Mettre à jour la position actuelle.
        } else if (commande == "Aller en haut" || commande == "Aller en bas") {
            std::cout << "Déplacement interdit : Vous ne pouvez pas aller en haut ou en bas.\n";
        } else {
            std::cout << "Commande invalide. Réessayez.\n";
        }

        // Vérification si la pièce a atteint la case gagnante.
        if (positionActuelle == Position(2, 4)) { // Vérifier si la position actuelle est la case gagnante.
            std::cout << "Félicitations ! Vous avez gagné !\n";
            partieEnCours = false;
        }
    }

    return 0;
}


