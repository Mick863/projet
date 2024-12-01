#include "CaseJeu.hpp"
#include "Piece.hpp"
#include "Position.hpp"

// Constructeur par défaut
CaseJeu::CaseJeu() : Case() {}

// Constructeur avec initialisation
CaseJeu::CaseJeu(Position pos, Color couleur, Piece* p)
    : Case(pos, couleur, p) {}  // Initialisation correcte de la classe de base avec 'p'

// Constructeur de copie
CaseJeu::CaseJeu(const CaseJeu& other)
    : Case(other) {} // Appel du constructeur de copie de la classe de base 'Case'

// Destructeur
CaseJeu::~CaseJeu() {}

// Surcharge de l'opérateur d'affectation
CaseJeu& CaseJeu::operator=(const CaseJeu& other) {
    if (this != &other) {
        Case::operator=(other);  // Appelle l'opérateur d'affectation de la classe de base
        piece = other.piece;     // Copie le pointeur de pièce (non dupliqué)
    }
    return *this;
}

// Récupère la pièce associée à cette case
Piece* CaseJeu::getPiece() const {
    return piece;
}

// Surcharge de l'opérateur << pour afficher la case
std::ostream& operator<<(std::ostream& os, const CaseJeu& caseJeu) {
    os << "CaseJeu [Position: " << caseJeu.getPosition()
       << ", Couleur: " << static_cast<int>(caseJeu.getCouleur())
       << ", Est Occupée: " << caseJeu.getEstOccupe()
       << ", Piece: " << (caseJeu.piece ? caseJeu.piece->print() : "Aucune") << "]";
    return os;
}

// Retourne le type de la case
CaseType CaseJeu::getType() const {
    return CaseType::Jeu;
}
