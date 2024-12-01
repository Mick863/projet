#ifndef PIECE_HPP
#define PIECE_HPP

#include <map>
#include <vector>
#include "Case.hpp"
#include "Position.hpp"
#include "Plateau.hpp"

enum class Direction {
    Haut,     
    Bas,      
    Gauche,   
    Droite    
};

class Plateau; //Déclaration anticipé de Plateau pour éviter le problème des cycles.
class Piece {
public:
    Case* caseCourrante; // Case actuelle où se trouve la pièce
    Plateau plateau;
    std::map<int, std::vector<Position>> blocks; // Map des blocs pour les états de rotation
    int rotationState; // État actuel de rotation

public:
    // Constructeurs et destructeur
    Piece(); // Constructeur par défaut abstrait
    Piece(Case* c, std::map<int, std::vector<Position>> b); // Constructeur avec initialisation
    virtual ~Piece(); // Destructeur virtuel pur

    // Accesseur pour la case courante
    virtual Case* getCaseCourrante() const;

    virtual string print() const;
    Plateau getPlateau();
    // Déplacement de la pièce
    virtual void deplacer(Direction direction);

    // Rotation de la pièce
    virtual void rotation(int rotation) ;

    // Accesseur pour les blocs de la pièce
    virtual std::map<int, std::vector<Position>> getBlocks() ;

    // Vérifie si la pièce est hors des limites
    virtual bool estDehors() const;

    // Surcharge de l'opérateur d'égalité
    virtual bool operator==(const Piece& piece) const;

};

#endif 
