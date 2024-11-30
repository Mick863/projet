#ifndef PIECEO_HPP
#define PIECEO_HPP
#include "Piece.hpp" 
class PieceO : public Piece {
public:
    // Constructeur par défaut
    PieceO();
    // Constructeur avec initialisation
    PieceO(Case* c);
    // Constructeur de copie
    PieceO(const PieceO& other);

    // Destructeur virtuel
    virtual ~PieceO();
    // Surcharge de l'opérateur d'affectation

    string print() const;

    void rotation(); 

    friend std::ostream& operator<<(std::ostream& os, const PieceO& piece) ;


};
#endif