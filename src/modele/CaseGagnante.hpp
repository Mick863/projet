#include "Case.hpp" 

class CaseGagnante : public CaseJeu {
private:
    static int nbCaseGagnante; // Compteur global du nombre de cases gagnantes

public:
    // Constructeurs
    CaseGagnante();
    CaseGagnante(Position pos, Color c, Piece* p = nullptr);
    CaseGagnante(const CaseGagnante& other);

    // Destructeur
    virtual ~CaseGagnante();

    // Méthodes
    static int getNbCaseGagnante(); // Retourne le nombre total de cases gagnantes
    bool finDeJeu() const;         // Vérifie si la case gagnante a la bonne pièce

    // Opérateur d'affectation
    CaseGagnante& operator=(const CaseGagnante& other);

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const CaseGagnante& c);
};