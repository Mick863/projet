#ifndef PLATEAU_HPP
#define PLATEAU_HPP 

#include <iostream>
using namespace std;
#include <sstream>


#include <vector>
#include <iostream>
#include "Case.hpp"
#include "CasePaysage.hpp" 
#include "CaseGagnante.hpp"
#include "CaseJeu.hpp"  
#include "Piece.hpp"  
#include "Position.hpp"
#include <map>

class Piece; //Déclaration anticipé de Piece pour éviter le problème des cycles.

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
    Case& getCaseJeu(Position p);
    int getNbLignes() const;        
    int getNbColonnes() const;      

    // Gestion des pièces
    void ajouterPiece(Piece piece, Position p); 
    void supprimerPiece(Piece piece);        
    // Opérateur d'affectation
    Plateau& operator=(const Plateau& p);
    friend std::ostream& operator<<(std::ostream& os, const Plateau& p);
    std::string print() const;

};

#endif