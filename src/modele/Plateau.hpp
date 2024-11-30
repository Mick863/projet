#include <iostream>
using namespace std;

#include <vector>
#include <iostream>
#include "Case.hpp"   
#include "Piece.hpp"  
#include "Position.hpp"
#include <map>

class Plateau {
private:
    std::vector<std::vector<Case>> plateau; // Grille du plateau (matrice de cases)
    int nbLigne;      
    int nbColonne;    
    int niveau;       
    std::vector<Piece> pieces; // Liste des pièces présentes sur le plateau

public:
    // Constructeur
    Plateau(int niveau = 0);

    // Méthodes d'accès
    Case getCase(Position p) const; 
    int getNbLignes() const;        
    int getNbColonnes() const;      

    // Gestion des pièces
    void ajouterPiece(Piece piece, Position p); 
    void supprimerPiece(Piece* piece);        
    // Opérateur d'affectation
    Plateau& operator=(const Plateau& p);
    friend std::ostream& operator<<(std::ostream& os, const Plateau& p);
};
