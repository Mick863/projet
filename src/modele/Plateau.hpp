#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "Case.hpp"
#include "Piece.hpp"
#include "Position.hpp"

class Plateau : public std::enable_shared_from_this<Plateau> {
private:
    int nbLigne;                                     // Nombre de lignes du plateau.
    int nbColonne;                                   // Nombre de colonnes du plateau.
    std::vector<std::vector<std::shared_ptr<Case>>> cases; // Matrice des cases.
    std::vector<std::shared_ptr<Piece>> pieces;     // Liste des pièces.
    int niveau;                                      // Niveau du jeu.

public:
    // Constructeur.
    explicit Plateau(int niveau);
    void initPieces(); 

    // Destructeur par défaut.
    ~Plateau() = default;

    // Accesseurs.
    std::shared_ptr<Case> getCase(const Position& position) const; // Retourne un pointeur sur la case à une position donnée.
    std::shared_ptr<Piece> getPiece(const Position& position) const; // Retourne un pointeur sur la pièce à une position donnée.

    // Méthodes principales.
    void ajouterPiece(const std::shared_ptr<Piece>& piece, const Position& position); // Ajoute une pièce à une position donnée.
    bool movePiece(const Position& from, const Position& to); // Déplace une pièce d'une position à une autre.
    bool estPositionValide(const Position& pos) const;        // Vérifie si une position est valide sur le plateau.

    // Surcharge de l'opérateur << pour l'affichage.
    friend std::ostream& operator<<(std::ostream& out, const Plateau& plateau);
};

#endif // PLATEAU_HPP



