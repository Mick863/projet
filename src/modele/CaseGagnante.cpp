#include "CaseGagnante.hpp"

CaseGagnante::CaseGagnante() : Case(), nbCaseGagnante(1) {}

// Constructeur avec paramètres
CaseGagnante::CaseGagnante(Position position, Color couleur, int nbCaseGagnante) : Case(position,  couleur), nbCaseGagnante(nbCaseGagnante) {}

// Destructeur
CaseGagnante::~CaseGagnante(){cout<<"Destruction de la case gagnante n°"<<id<<endl;}

// Méthodes spécifiques
int CaseGagnante::getNbCaseGagnante() const { 
    return nbCaseGagnante; 
}

// Vérifie si la condition de fin de jeu est atteinte
bool CaseGagnante::finDeJeu() const {
    if (estOccupe && piece) { // Vérifie si la case est occupée et si une pièce est présente
        return dynamic_cast<PieceO*>(piece) != nullptr; // Vérifie si la pièce est de type PieceO
    }
    return false;
}


// Implémentations des méthodes virtuelles de Case
bool CaseGagnante::getEstOccupe() const {
    return estOccupe;
}

Color CaseGagnante::getCouleur() const{
    return couleur;
}

    int getTaille() const override {
        return taille;
    }

    Position getPosition() const override {
        return position;
    }

    void setEstOccupe(bool b) override {
        estOccupe = b;
    }

    std::ostream& operator<<(std::ostream& os) const{
        os << "CaseGagnante [Position=(" << position.getLigne() << "," << position.getColonne()
           << "), Taille=" << taille
           << ", Couleur=" << static_cast<int>(couleur)
           << ", EstOccupe=" << estOccupe
           << ", NbCaseGagnante=" << nbCaseGagnante << "]";
        return os;
    }

 
