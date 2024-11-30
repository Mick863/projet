#ifndef CASEJEU_HPP
#define CASEJEU_HPP
#include "Case.hpp"

class CaseJeu : public Case {
protected:
    Piece* piece; // Pointeur vers la pièce occupante

public:
    // Constructeur par défaut
    CaseJeu();

    // Constructeur avec paramètres
    CaseJeu(Position pos, Color couleur, Piece* p = nullptr);

    // Constructeur de copie
    CaseJeu(const CaseJeu& other);

    // Destructeur
    virtual ~CaseJeu();

    // Opérateur d'affectation
    CaseJeu& operator=(const CaseJeu& other);

    // Accesseur pour la pièce
    Piece* getPiece() const;

    // Mutateur pour la pièce
    void setPiece(Piece* p);

    // Surcharge de l'opérateur << pour l'affichage
    friend std::ostream& operator<<(std::ostream& os, const CaseJeu& caseJeu);
};

#endif