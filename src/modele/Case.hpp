#include "Position.hpp" 

enum class Color {
    Rouge,     // 0
    Vert,      // 1
    Bleu,      // 2
    Jaune,     // 3
    Noir,      // 4
    Blanc      // 5
};

class Case{
    private: 
        Position position;
        bool estOccupe;
        Color couleur;
        int taille; 
    
public:
    // Constructeur par défaut
    Case();

    // Constructeur avec paramètres
    Case(Position position, int taille, Color couleur);

    // Destructeur
    ~Case();

    // Constructeur par copie
    Case(const Case& caseObj);

    // Opérateur d'affectation
    Case& operator=(const Case& caseObj);

    // Méthodes d'accès
    bool getEstOccupe() const;
    Color getCouleur() const;
    int getTaille() const;
    Position getPosition() const;

    // Méthode de modification
    void setEstOccupe(bool b);

    // Surcharge de l'opérateur de flux
    friend std::ostream& operator<<(std::ostream& os, const Case& caseObj);
};
