#ifndef PIECET_HPP
#define PIECET_HPP
#include "Piece.hpp" 
class PieceT : public Piece {
public:
    // Constructeur par défaut
    PieceT();
    // Constructeur avec initialisation
    PieceT(Case* c);
    // Constructeur de copie
    PieceT(const PieceT& other);

    // Destructeur virtuel
    virtual ~PieceT();
    // Surcharge de l'opérateur d'affectation

    string print() const;

    void rotation(); 

    friend std::ostream& operator<<(std::ostream& os, const PieceT& piece) ;


};
#endif