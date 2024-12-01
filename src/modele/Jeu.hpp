#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "PieceO.hpp"

class Jeu {
private:
    Plateau plateau;      // Le plateau de jeu
    Piece *piece;         // Changer PieceO en Piece* pour que ça soit un pointeur générique
    bool jeuTermine;      // Indique si le jeu est terminé

public:
    // Constructeur
    Jeu();

    virtual ~Jeu();

    // Démarre la simulation du jeu
    void lancer();

    // Vérifie si la pièce est sur la case gagnante
    bool verifierVictoire() const;

    // Demande au joueur de saisir une direction pour déplacer la pièce
    Direction lireDirection();

    // Déplace la pièce dans la direction spécifiée
    void deplacerPiece(Direction direction);

    // Affiche l'état actuel du plateau
    void afficherEtat() const;
};

#endif 

