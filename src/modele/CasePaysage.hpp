#ifndef CASEPAYSAGE_HPP
#define CASEPAYSAGE_HPP

#include "Case.hpp"

class CasePaysage : public Case {
public:
    static int nbCasePaysage; 

    CasePaysage();
    CasePaysage(Position position, Color couleur, Piece* piece = nullptr);
    CasePaysage(const CasePaysage& other);
    virtual ~CasePaysage();
    CasePaysage& operator=(const CasePaysage& other);

    static int getNbCasePaysage(); 
    void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const CasePaysage& c);
    CaseType getType() const;
};

#endif


