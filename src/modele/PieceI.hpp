#ifndef PIECEI_HPP
#define PIECEI_HPP

#include "Piece.hpp"
#include <string>
#include <memory>

class PieceI : public Piece {
public:
    // Constructeur
    PieceI(const std::shared_ptr<Case>& c, 
           const std::shared_ptr<Plateau>& p);

    // Implémentations des méthodes virtuelles
    std::string print() const override;                 // Affiche "II"
    void deplacer(Direction direction) override;        // Déplace la pièce
    void rotation() override;                           // Effectue la rotation (inutile ici)
    bool estDehors() const override;                    // Vérifie si la pièce est hors du plateau
};

#endif
