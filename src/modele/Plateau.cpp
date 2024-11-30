#include "Plateau.hpp" 
#include "CaseJeu.hpp"


// Constructeur
Plateau::Plateau(int niveau = 0) : nbLigne(10), nbColonne(10), niveau(niveau) {
    // Initialiser un plateau vide (exemple d'un plateau 10x10)
    plateau.resize(nbLigne, std::vector<Case>(nbColonne));
}

// Méthodes d'accès
CaseJeu Plateau::getCase(Position p) const {
    // Retourne la case à la position p (là où Position gère les indices)
    return plateau[p.getLigne()][p.getColonne()];
}

int Plateau::getNbLignes() const {
    return nbLigne;
}

int Plateau::getNbColonnes() const {
    return nbColonne;
}

// Gestion des pièces
void Plateau::ajouterPiece(Piece piece, Position p) {
    // Ajouter une pièce à la position donnée sur le plateau
    // Supposons qu'une pièce peut être ajoutée si la case est vide
    if (!plateau[p.getLigne()][p.getColonne()].getEstOccupe()) {
        pieces.push_back(piece);
        plateau[p.getLigne()][p.getColonne()].setEstOccupe(true);
    }
}

void supprimerPiece(Piece* piece) {
    // Supprimer une pièce du plateau
    // Si la pièce existe, la supprimer de la liste des pièces et libérer la case
    auto it = std::find(pieces.begin(), pieces.end(), *piece);
    if (it != pieces.end()) {
        pieces.erase(it);  // Retirer la pièce de la liste
        // Trouver la case où elle se trouve et la marquer comme libre
        for (int i = 0; i < nbLigne; ++i) {
            for (int j = 0; j < nbColonne; ++j) {
                if (&plateau[i][j] == piece->getCaseCourrante()) {
                    plateau[i][j].setEstOccupe(false);
                }
            }
        }
    }
}

/*
// Opérateur d'affectation
Plateau& operator=(const Plateau& p) {
    if (this != &p) { 
        nbLigne = p.nbLigne;
        nbColonne = p.nbColonne;
        niveau = p.niveau;
        plateau = p.plateau;  
        pieces = p.pieces;    
    return *this;
}*/

// Opérateur d'affichage
std::ostream& operator<<(std::ostream& os, const Plateau& p) {
    for (int i = 0; i < p.nbLigne; ++i) {
        for (int j = 0; j < p.nbColonne; ++j) {
            // Affichage de chaque case (ici, on suppose que chaque case a un état à afficher)
            os << (p.plateau[i][j].getEstOccupe() ? "X" : ".");
        }
        os << std::endl;
    }
    return os;
}

