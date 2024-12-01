#ifndef PIECEZ_HPP
#define PIECEZ_HPP
#include "Piece.hpp"
#include "Plateau.hpp" // Inclure Plateau.hpp ici si utilisé dans la classe

class PieceZ : public Piece {
public:
    // Constructeur par défaut
    PieceZ();
    // Constructeur avec initialisation
    PieceZ(Case* c);
    // Constructeur de copie
    PieceZ(const PieceZ& other);
    // Destructeur virtuel
    virtual ~PieceZ();

    // Surcharge de l'opérateur d'affectation
    PieceZ& operator=(const PieceZ& other);

    string print() const;

    void rotation(); 

    friend std::ostream& operator<<(std::ostream& os, const PieceZ& piece);
};

#endif
