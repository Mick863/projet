#ifndef PIECEL_HPP
#define PIECEL_HPP
#include "Piece.hpp"
#include "CaseJeu.hpp"  // Ajout de l'inclusion pour utiliser CaseJeu et CasePaysage
#include "CasePaysage.hpp" // Ajout de l'inclusion pour utiliser CasePaysage

class PieceL : public Piece {
public:
    // Constructeur par défaut
    PieceL();
    // Constructeur avec initialisation
    PieceL(Case* c);
    // Constructeur de copie
    PieceL(const PieceL& other);

    // Destructeur virtuel
    virtual ~PieceL();
    // Surcharge de l'opérateur d'affectation

    std::string print() const;

    void rotation(); 

    friend std::ostream& operator<<(std::ostream& os, const PieceL& piece);
};

#endif
