#ifndef CASEJEU_HPP
#define CASEJEU_HPP

#include "Case.hpp"

class CaseJeu : public Case {
public:
    CaseJeu();
    CaseJeu(Position pos, Color couleur, Piece* p = nullptr);
    CaseJeu(const CaseJeu& other);
    virtual ~CaseJeu();
    CaseJeu& operator=(const CaseJeu& other);

    Piece* getPiece() const;
    friend std::ostream& operator<<(std::ostream& os, const CaseJeu& caseJeu);

    CaseType getType() const;
};

#endif

