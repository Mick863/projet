#include "Plateau.hpp" 


// Constructeur
Plateau::Plateau(int niveau = 0) : nbLigne(10), nbColonne(10), niveau(niveau) {
    // Initialiser un plateau vide (exemple d'un plateau 10x10)
    plateau.resize(nbLigne, std::vector<Case>(nbColonne));
}

Case& Plateau::getCaseJeu(Position p){
    // Retourne une référence constante de la case à la position donnée
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


// Opérateur d'affectation
Plateau& Plateau::operator=(const Plateau& p) {
    if (this != &p) { 
        nbLigne = p.nbLigne;
        nbColonne = p.nbColonne;
        niveau = p.niveau;
        plateau = p.plateau;  
        pieces = p.pieces;    
    return *this;
}}


void Plateau::supprimerPiece(Piece piece) {
    // Rechercher la pièce manuellement
    auto it = pieces.begin();
    while (it != pieces.end()) {
        if (&(*it) == &piece) { // Comparer les adresses des objets
            break;
        }
        ++it;
    }

    if (it == pieces.end()) {
        std::cerr << "Erreur : La pièce n'est pas présente sur le plateau.\n";
        return;
    }

    // Libérer les cases occupées par la pièce
    Case* caseCourrante = piece.getCaseCourrante();
    if (caseCourrante == nullptr) {
        std::cerr << "Erreur : La case courante de la pièce est nulle.\n";
        return;
    }

    int rotationState = piece.rotationState;
    const auto& blocks = piece.getBlocks().at(rotationState);

    for (const Position& blockPos : blocks) {
        int ligne = caseCourrante->getPosition().getLigne() + blockPos.getLigne();
        int colonne = caseCourrante->getPosition().getColonne() + blockPos.getColonne();

        if (ligne >= 0 && ligne < nbLigne && colonne >= 0 && colonne < nbColonne) {
            Case& caseJeu = plateau[ligne][colonne];
            caseJeu.setEstOccupe(false);
            caseJeu.setPiece(nullptr);
        } else {
            std::cerr << "Erreur : Bloc hors des limites du plateau.\n";
        }
    }

    // Supprimer la pièce de la liste
    pieces.erase(it);

    std::cout << "La pièce a été supprimée avec succès.\n";
}

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

std::string Plateau::print() const {
    std::ostringstream oss;
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            const Case& currentCase = plateau[i][j]; // Accède à la case actuelle

            // Vérifie le type de la case (Paysage, Gagnante ou Jeu)
            const CasePaysage* paysage = dynamic_cast<const CasePaysage*>(&currentCase);
            const CaseGagnante* gagnante = dynamic_cast<const CaseGagnante*>(&currentCase);
            const CaseJeu* jeu = dynamic_cast<const CaseJeu*>(&currentCase);

            if (paysage) {
                oss << "P "; // Case Paysage
            } else if (gagnante) {
                oss << "G "; // Case Gagnante
            } else if (jeu) {
                if (jeu->getPiece() != nullptr) {
                    oss << jeu->getPiece()->print() << " "; // Affiche la pièce présente dans la case Jeu
                } else {
                    oss << "X "; // Case Jeu vide
                }
            } else {
                oss << "? "; // Cas inattendu
            }
        }
        oss << "\n"; // Nouvelle ligne pour la ligne suivante du plateau
    }

    return oss.str();
}
