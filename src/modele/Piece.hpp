#ifndef PIECE_HPP
#define PIECE_HPP

#include <map>
#include <vector>
#include "Case.hpp"
#include "Position.hpp"

enum class Direction {
    Haut,     
    Bas,      
    Gauche,   
    Droite    
};
class Piece {
public:
    Case* caseCourrante; // Case actuelle où se trouve la pièce
    std::map<int, std::vector<Position>> blocks; // Map des blocs pour les états de rotation
    int rotationState; // État actuel de rotation

public:
    // Constructeurs et destructeur
    Piece(); // Constructeur par défaut abstrait
    Piece(Case* c, std::map<int, std::vector<Position>> b); // Constructeur avec initialisation
    virtual ~Piece(); // Destructeur virtuel pur

    // Accesseur pour la case courante
    virtual Case* getCaseCourrante() const = 0;

    virtual string print() const =0;

    // Déplacement de la pièce
    virtual void deplacer(Direction direction) = 0;

    // Rotation de la pièce
    virtual void rotation() = 0;

    // Accesseur pour les blocs de la pièce
    virtual std::map<int, std::vector<Position>> getBlocks() const = 0;

    // Vérifie si la pièce est hors des limites
    virtual bool estDehors() const = 0;

    // Surcharge de l'opérateur d'égalité
    virtual bool operator==(const Piece& piece) const = 0;

};

#endif 
