#ifndef CONFIG_HPP
#define CONFIG_HPP

// Définition des dimensions du plateau
extern const int NB_LIGNES;
extern const int NB_COLONNES;

enum class Color {
    Rouge,  // 0
    Vert,   // 1
    Bleu,   // 2
    Jaune,  // 3
    Noir,   // 4
    Blanc   // 5
};

enum class CaseType { Paysage, Jeu, Gagnante , Normal}; 
#endif
