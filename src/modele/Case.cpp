#include "Case.hpp" 

Case::Case() : position(new Position(0,0)), estOccupe(false) , taille(30), couleur(Color::Blanc){}
Case::Case(Position position, Color couleur) : position(new Position(0,0)), estOccupe(false) , couleur(Color::Blanc) , taille(30)  {}
