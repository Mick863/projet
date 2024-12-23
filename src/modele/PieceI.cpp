#include "PieceI.hpp"
#include "Plateau.hpp"
#include <iostream>

// Constructeur
PieceI::PieceI(const std::shared_ptr<Case>& c, const std::shared_ptr<Plateau>& p)
    : Piece(c, {{0, {Position(0, 0), Position(0, 1)}}}, p) {}

// Méthode pour afficher la pièce
std::string PieceI::print() const {
    return "I"; // Représente visuellement une pièce en ligne
}

// Déplace la pièce dans une direction donnée
void PieceI::deplacer(Direction direction) {
    auto caseActuelle = getCaseCourrante();
    auto plateauActuel = getPlateau();

    if (!caseActuelle || !plateauActuel) {
        std::cerr << "Erreur : Déplacement impossible, la pièce n'est pas correctement associée à une case ou un plateau.\n";
        return;
    }

    // Calcul de la nouvelle position pour la case courante
    Position newPos = caseActuelle->getPosition();
    switch (direction) {
        case Direction::Haut:    newPos.setLigne(newPos.getLigne() - 1); break;
        case Direction::Bas:     newPos.setLigne(newPos.getLigne() + 1); break;
        case Direction::Gauche:  newPos.setColonne(newPos.getColonne() - 1); break;
        case Direction::Droite:  newPos.setColonne(newPos.getColonne() + 1); break;
    }

    // Vérification des limites pour les deux cases
    auto secondPos = newPos;
    secondPos.setColonne(secondPos.getColonne() + 1);

    if (!plateauActuel->estPositionValide(newPos) || !plateauActuel->estPositionValide(secondPos)) {
        std::cerr << "Erreur : Déplacement hors des limites du plateau.\n";
        return;
    }

    // Vérification que les deux cases sont libres
    auto nouvelleCase = plateauActuel->getCase(newPos);
    auto caseAdjacente = plateauActuel->getCase(secondPos);

    if (!nouvelleCase || !caseAdjacente || nouvelleCase->getEstOccupee() || caseAdjacente->getEstOccupee()) {
        std::cerr << "Erreur : Les cases cibles sont déjà occupées ou invalides.\n";
        return;
    }

    // Déplacement effectif
    caseActuelle->setPieceCourrante(nullptr); // Libère l'ancienne case courante
    caseAdjacente->setOccupee(false);        // Libère l'ancienne case adjacente

    nouvelleCase->setPieceCourrante(shared_from_this()); // Met à jour la nouvelle case courante
    caseAdjacente->setOccupee(true);                   // Occupe la nouvelle case adjacente

    caseCourrante = nouvelleCase; // Mise à jour de la case courante
}

// Rotation : inutile ici car la pièce I ne change pas de forme
void PieceI::rotation() {
    // Aucun changement requis
    rotationState = 0;
}

// Vérifie si la pièce est hors du plateau
bool PieceI::estDehors() const {
    auto caseActuelle = getCaseCourrante();
    auto plateauActuel = getPlateau();

    if (!caseActuelle || !plateauActuel) {
        return true; // Considérée comme hors des limites
    }

    // Vérifie si les deux cases sont valides
    Position posCourante = caseActuelle->getPosition();
    Position posAdjacente = posCourante;
    posAdjacente.setColonne(posAdjacente.getColonne() + 1);

    return !plateauActuel->estPositionValide(posCourante) || !plateauActuel->estPositionValide(posAdjacente);
}

