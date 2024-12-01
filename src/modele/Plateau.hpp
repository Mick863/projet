#ifndef PLATEAU_HPP
#define PLATEAU_HPP 

#include <iostream>
#include <vector>
#include <map>
#include "Case.hpp"
#include "CasePaysage.hpp"
#include "CaseGagnante.hpp"
#include "CaseJeu.hpp"
#include "Position.hpp"

// Déclaration anticipée de Piece pour éviter la dépendance circulaire
class Piece;

class Plateau {
private:
    std::vector<std::vector<Case>> plateau; // Grille du plateau (matrice de cases)
    int nbLigne;      
    int nbColonne;    
    int niveau;       
    std::vector<Piece*> pieces; // Liste des pointeurs vers les pièces présentes sur le plateau

public:
    // Constructeur
    Plateau(int niveau = 0);
    virtual ~Plateau();
    // Méthodes d'accès
    CaseJeu& getCaseJeu(Position p);
    CasePaysage& getCasePaysage(Position p);
    int getNbLignes() const;        
    int getNbColonnes() const;      

    // Gestion des pièces
    void ajouterPiece(Piece* piece, Position p);  // Changer les paramètres pour accepter un pointeur
    void supprimerPiece(Piece* piece);            // Changer les paramètres pour accepter un pointeur
        
    // Opérateur d'affectation
    Plateau& operator=(const Plateau& p);
    friend std::ostream& operator<<(std::ostream& os, const Plateau& p);
    std::string print() const;
    std::vector<std::vector<Case>>& getPlateau();
};

#endif
