#include "CaseJeu.hpp"

CaseJeu::CaseJeu() : Case(), piece(nullptr) {}

CaseJeu::CaseJeu(Position pos, Color couleur, Piece* p)
    : Case(pos, couleur), piece(p) {}

CaseJeu::CaseJeu(const CaseJeu& other)
    : Case(other), piece(other.piece) {} // Appelle le constructeur de copie de Case

CaseJeu::~CaseJeu() {}

CaseJeu& CaseJeu::operator=(const CaseJeu& other) {
    if (this != &other) {
        Case::operator=(other); // Appelle l'opérateur d'affectation de Case
        piece = other.piece;    // Copie le pointeur de pièce (non dupliqué)
    }
    return *this;
}

Piece* CaseJeu::getPiece() const {
    return piece;
}

void CaseJeu::setPiece(Piece* p) {
    piece = p;
}

std::ostream& operator<<(std::ostream& os, const CaseJeu& caseJeu) {
    os << "CaseJeu [Position: " << caseJeu.getPosition()
       << ", Couleur: " << static_cast<int>(caseJeu.getCouleur())
       << ", Est Occupée: " << caseJeu.getEstOccupe()
       << ", Piece: " << (caseJeu.piece ? caseJeu.piece->print() : "Aucune") << "]";
    return os;
}