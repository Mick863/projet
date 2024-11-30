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
    PieceO& operator=(const PieceO& p);

    string print() const;

    Case* getCaseCourrante() const ;

    void deplacer(Direction direction);

    void rotation();

    std::map<int, std::vector<Position>> getBlocks() const;

    bool PieceO::operator==(const Piece& piece) const;

    bool estDehors() const;

    friend std::ostream& operator<<(std::ostream& os, const PieceO& piece);

};
#endif