#include "Piece.hpp" 
#include "Plateau.hpp"

Piece::Piece() : caseCourrante(nullptr), rotationState(0) {}
Piece::Piece(Case* c, std::map<int, std::vector<Position>> b)
    : caseCourrante(c), blocks(b), rotationState(0) {
    // Initialisation des membres avec les paramètres passés.
    // caseCourrante est initialisée avec la case donnée
    // blocks est initialisé avec la map -- entoure la piece dans la grille
    // rotationState est initialisé à 0 (par défaut)
}


Plateau Piece::getPlateau(){
    return plateau;
}


#include "Piece.hpp"
#include "Plateau.hpp"
#include <stdexcept>

void Piece::deplacer(Direction direction) {
    if (!caseCourrante) {
        throw std::runtime_error("La pièce n'a pas de case associée !");
    }

    // Obtenez la position actuelle
    Position positionActuelle = caseCourrante->getPosition();
    Position nouvellePosition = positionActuelle;

    // Calculez la nouvelle position en fonction de la direction
    switch (direction) {
    case Direction::Haut:
        nouvellePosition.setLigne(positionActuelle.getLigne() - 1);
        break;
    case Direction::Bas:
        nouvellePosition.setLigne(positionActuelle.getLigne() + 1);
        break;
    case Direction::Gauche:
        nouvellePosition.setColonne(positionActuelle.getColonne() - 1);
        break;
    case Direction::Droite:
        nouvellePosition.setColonne(positionActuelle.getColonne() + 1);
        break;
    default:
        throw std::invalid_argument("Direction invalide !");
    }

    // Vérifiez si la nouvelle position est en dehors du plateau
    if (nouvellePosition.getLigne() < 0 || nouvellePosition.getLigne() >= plateau.getNbLignes() ||
        nouvellePosition.getColonne() < 0 || nouvellePosition.getColonne() >= plateau.getNbColonnes()) {
        throw std::out_of_range("La nouvelle position est en dehors du plateau !");
    }

    // Vérifiez si la nouvelle case est une case paysage
    CaseJeu& caseCible = plateau.getCaseJeu(nouvellePosition);
    if (dynamic_cast<CasePaysage*>(&caseCible)) {
        throw std::runtime_error("La case cible est une case paysage, vous ne pouvez pas y déplacer la pièce !");
    }

    // Vérifiez si la case cible est occupée (par une autre pièce)
    if (caseCible.getEstOccupe()) {
        throw std::runtime_error("La case cible est déjà occupée par une autre pièce !");
    }

    // Mettre à jour les blocs de la pièce et vérifier les bordures
    if (blocks.find(rotationState) != blocks.end()) {
        std::vector<Position>& blocsActuels = blocks[rotationState];

        // Vérifiez que tous les blocs de la pièce restent dans les limites du plateau après le déplacement
        for (Position& pos : blocsActuels) {
            Position nouvellePositionBloc = pos; // Créez une copie de la position du bloc avant modification

            // Déplacez la position du bloc en fonction de la direction
            switch (direction) {
            case Direction::Haut:
                nouvellePositionBloc.setLigne(nouvellePositionBloc.getLigne() - 1);
                break;
            case Direction::Bas:
                nouvellePositionBloc.setLigne(nouvellePositionBloc.getLigne() + 1);
                break;
            case Direction::Gauche:
                nouvellePositionBloc.setColonne(nouvellePositionBloc.getColonne() - 1);
                break;
            case Direction::Droite:
                nouvellePositionBloc.setColonne(nouvellePositionBloc.getColonne() + 1);
                break;
            }

            // Vérifiez si le bloc est à l'extérieur du plateau
            if (nouvellePositionBloc.getLigne() < 0 || nouvellePositionBloc.getLigne() >= plateau.getNbLignes() ||
                nouvellePositionBloc.getColonne() < 0 || nouvellePositionBloc.getColonne() >= plateau.getNbColonnes()) {
                throw std::out_of_range("Un ou plusieurs blocs de la pièce sortent des limites du plateau !");
            }

            // Vérifiez si la case du bloc est occupée ou est une case paysage
            CaseJeu& caseBloc = plateau.getCaseJeu(nouvellePositionBloc);
            if (dynamic_cast<CasePaysage*>(&caseBloc) || caseBloc.getEstOccupe()) {
                throw std::runtime_error("Le déplacement de la pièce entraînerait un chevauchement avec une case occupée ou une case paysage !");
            }
        }

        // Si toutes les vérifications sont passées, appliquez le déplacement
        // Libérez l'ancienne case
        caseCourrante->setEstOccupe(false);

        // Déplacez la pièce vers la nouvelle position
        caseCourrante = &caseCible;
        caseCourrante->setEstOccupe(true);

        // Déplacez chaque bloc en fonction de la direction
        for (Position& pos : blocsActuels) {
            switch (direction) {
            case Direction::Haut:
                pos.setLigne(pos.getLigne() - 1);
                break;
            case Direction::Bas:
                pos.setLigne(pos.getLigne() + 1);
                break;
            case Direction::Gauche:
                pos.setColonne(pos.getColonne() - 1);
                break;
            case Direction::Droite:
                pos.setColonne(pos.getColonne() + 1);
                break;
            }
        }
    }
}
