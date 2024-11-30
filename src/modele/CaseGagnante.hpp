#include "Case.hpp" 

class CaseGagnante : public Case{
    private : 
        Piece *piece;
        int nbCaseGagnante; 
        static int id;
    public : 
        CaseGagnante(Position position, Color couleur, int nbCaseGagnante);
        CaseGagnante();
        bool finDeJeu() const;
        int getNbCaseGagnante() const;
}