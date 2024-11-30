#include "CasePaysage.hpp"

// Initialisation de la variable statique
int CasePaysage::nbCasePaysage = 0;

// Constructeur par défaut
CasePaysage::CasePaysage() : Case() {
    ++nbCasePaysage;
}

// Constructeur avec paramètres
CasePaysage::CasePaysage(Position position, Color couleur, Piece* piece)
    : Case(position, couleur, piece) {
    ++nbCasePaysage;
}

// Constructeur de copie
CasePaysage::CasePaysage(const CasePaysage& other) : Case(*other.position, other.couleur, other.piece) {
    ++nbCasePaysage;
}

// Destructeur
CasePaysage::~CasePaysage() {
    --nbCasePaysage;
}

// Opérateur d'affectation
CasePaysage& CasePaysage::operator=(const CasePaysage& other) {
    if (this != &other) {
        this->position = new Position(*other.position);
        this->couleur = other.couleur;
        this->taille = other.taille;
        this->piece = other.piece;
        this->estOccupe = other.estOccupe;
    }
    return *this;
}

// Retourne le nombre de cases paysage
int CasePaysage::getNbCasePaysage() {
    return nbCasePaysage;
}

// Méthode print
void CasePaysage::print(std::ostream& os) const {
    os << "CasePaysage(Position: (" << position->getLigne() << ", " << position->getColonne()
       << "), Couleur: " << static_cast<int>(couleur)
       << ", Occupée: " << (estOccupe ? "Oui" : "Non") << ")";
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const CasePaysage& c) {
    c.print(os);
    return os;
}
