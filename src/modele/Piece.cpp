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
void Piece::deplacer(Direction direction){
    Plateau plateau = this -> getPlateau();
    switch(direction){
        case "Haut":
            if(plateau.getCaseJeu(Position((*caseCourrante).getPosition().getLigne()+1, (*caseCourrante).getPosition().getColonne()) ){

            }
    }
}