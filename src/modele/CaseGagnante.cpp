#include "CaseGagnante.hpp"
// Initialisation de l'attribut statique
int CaseGagnante::nbCaseGagnante = 0;

// Implémentations
CaseGagnante::CaseGagnante() : CaseJeu() {
    nbCaseGagnante++;
}

CaseGagnante::CaseGagnante(Position pos, Color c, Piece* p)
    : CaseJeu(pos, c, p) {
    nbCaseGagnante++;
}

CaseGagnante::CaseGagnante(const CaseGagnante& other)
    : CaseJeu(other) { // Appelle le constructeur de copie de CaseJeu
    nbCaseGagnante++;
}

CaseGagnante::~CaseGagnante() {
    nbCaseGagnante--;
}

int CaseGagnante::getNbCaseGagnante() {
    return nbCaseGagnante;
}

bool CaseGagnante::finDeJeu() const {
    return this->getPiece() != nullptr; // La fin de jeu se déclenche si une pièce occupe la case gagnante
}

CaseGagnante& CaseGagnante::operator=(const CaseGagnante& other) {
    if (this != &other) {
        CaseJeu::operator=(other); // Appelle l'opérateur d'affectation de CaseJeu
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const CaseGagnante& c) {
    os << "CaseGagnante [Position: " << c.getPosition()
       << ", Couleur: " << static_cast<int>(c.getCouleur())
       << ", Est Occupée: " << c.getEstOccupe()
       << ", Piece: " << (c.getPiece() ? c.getPiece()->print() : "Aucune")
       << ", Nombre Total de Cases Gagnantes: " << CaseGagnante::getNbCaseGagnante() << "]";
    return os;
}

