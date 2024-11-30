#ifndef CASEPAYSAGE_HPP
#define CASEPAYSAGE_HPP

#include "Case.hpp"

class CasePaysage : public Case {
public:
    static int nbCasePaysage; // Variable statique pour compter les cases de type paysage

    // Constructeurs et destructeur
    CasePaysage();
    CasePaysage(Position position, Color couleur, Piece* piece = nullptr);
    CasePaysage(const CasePaysage& other);
    virtual ~CasePaysage();

    // Opérateur d'affectation
    CasePaysage& operator=(const CasePaysage& other);

    // Méthodes
    static int getNbCasePaysage(); // Retourne le nombre de cases paysages
    virtual void print(std::ostream& os) const override;

    // Opérateur << pour l'affichage
    friend std::ostream& operator<<(std::ostream& os, const CasePaysage& c);
};

#endif
