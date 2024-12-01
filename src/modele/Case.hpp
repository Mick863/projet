#ifndef CASE_HPP
#define CASE_HPP

#include "Position.hpp"
class Piece; // Déclaration anticipée
class CasePaysage; // Déclaration anticipée
class CaseJeu; // Déclaration anticipée

class Case {
protected:
    Position* position; 
    bool estOccupe;   
    Color couleur;   
    int taille;       
    Piece* piece; 

public:
    Case();
    Case(Position position, Color couleur, Piece* piece = nullptr);
    virtual ~Case();
    void setPiece(Piece* piece);

    bool getEstOccupe() const;
    Color getCouleur() const;
    int getTaille() const;
    Position getPosition() const;
    void setEstOccupe(bool b);
    void print(std::ostream& os) const;
    std::ostream& operator<<(std::ostream& os);
    CaseType getType() const;
};

#endif
