#ifndef PIECEZ_HPP
#define PIECEZ_HPP
#include "Piece.hpp"
#include "Plateau.hpp"
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

    string print() const;

    void rotation(); 

    friend std::ostream& operator<<(std::ostream& os, const PieceZ& piece);

};
#endif