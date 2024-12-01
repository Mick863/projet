#ifndef PIECE_HPP
#define PIECE_HPP

#include <map>
#include <vector>
#include "Case.hpp"
#include "Position.hpp"

// Déclaration anticipée de Plateau pour éviter la dépendance circulaire
class Plateau;

enum class Direction {
    Haut,     
    Bas,      
    Gauche,   
    Droite    
};

class Piece {
public:
    Case* caseCourrante; // Case actuelle où se trouve la pièce
    Plateau* plateau;    // Pointeur vers un objet Plateau
    std::map<int, std::vector<Position>> blocks; // Map des blocs pour les états de rotation
    int rotationState; // État actuel de rotation

public:
    // Constructeurs et destructeur
    Piece(); // Constructeur par défaut abstrait
    Piece(Case* c, std::map<int, std::vector<Position>> b, Plateau* p = nullptr); // Constructeur avec initialisation
    virtual ~Piece(); // Destructeur virtuel pur

    // Accesseur pour la case courante
    Case* getCaseCourrante() const;

    string print() const;
    Plateau* getPlateau(); // Retourne un pointeur vers Plateau
    // Déplacement de la pièce
    void deplacer(Direction direction);

    // Rotation de la pièce
    void rotation(int rotation);

    // Accesseur pour les blocs de la pièce
    std::map<int, std::vector<Position>> getBlocks() const;

    // Vérifie si la pièce est hors des limites
    bool estDehors() const;

    // Surcharge de l'opérateur d'égalité
    bool operator==(const Piece& piece) const;

};

#endif



