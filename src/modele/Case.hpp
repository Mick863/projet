#include "Position.hpp"
#include "Piece.hpp"
#include <iostream>

// Enumération pour les couleurs
enum class Color {
    Rouge,  // 0
    Vert,   // 1
    Bleu,   // 2
    Jaune,  // 3
    Noir,   // 4
    Blanc   // 5
};

// Classe abstraite Case
class Case {
protected:
    Position *position; // Position de la case
    bool estOccupe;    // Indique si la case est occupée
    Color couleur;     // Couleur de la case
    int taille;        // Taille de la case

public:
    // Constructeur par défaut abstrait
    Case();
    Case(Position position, Color couleur);

    // Constructeur avec paramètres abstrait
    virtual ~Case();

    // Méthodes virtuelles pures
    virtual bool getEstOccupe() const ;           // Retourne si la case est occupée
    virtual Color getCouleur() const ;           // Retourne la couleur de la case
    virtual int getTaille() const ;              // Retourne la taille de la case
    virtual Position getPosition() const ;       // Retourne la position de la case
    virtual void setEstOccupe(bool b) ;          // Modifie l'état d'occupation
    virtual void print(std::ostream& os) const ; // Affiche les informations de la case
    virtual std::ostream& operator<<(std::ostream& os) ;
};



