#ifndef PIECEO_HPP
#define PIECEO_HPP

#include "Piece.hpp"

class PieceO : public Piece {
public:
    // Constructeur.
    PieceO(const std::weak_ptr<Case>& c, const std::weak_ptr<Plateau>& p);

    // Implémentations des méthodes virtuelles.
    std::string print() const override;
    void deplacer(Direction direction) override;
    void rotation() override;
    bool estDehors() const override;
};

#endif




