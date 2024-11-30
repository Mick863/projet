#ifndef PIECEI_HPP
#define PIECEI_HPP
#include "Piece.hpp" 
class PieceI : public Piece {
public:
    // Constructeur par défaut
    PieceI();
    // Constructeur avec initialisation
    PieceI(Case* c);
    // Constructeur de copie
    PieceI(const PieceI& other);

    // Destructeur virtuel
    virtual ~PieceI();
    // Surcharge de l'opérateur d'affectation

    string print() const;

    void rotation(); 

    friend std::ostream& operator<<(std::ostream& os, const PieceI& piece) ;


};
#endif