#ifndef CASE_HPP
#define CASE_HPP

#include "Position.hpp"
#include "Piece.hpp"
#include <memory>
#include <iostream>

enum class TypeCase {
    Jeu,
    Gagnante,
    Paysage
};

// Déclaration anticipée des classes.
class Piece;

class Case {
private:
    Position position;                     // Position de la case.
    TypeCase type;                         // Type de la case (Jeu, Gagnante, Paysage).
    bool estOccupee;                       // Indique si la case est occupée.
    std::shared_ptr<Piece> pieceCourrante;  // Pointeur partagé vers la pièce actuelle.

public:
    // Constructeur.
    Case(const Position& position, TypeCase type, std::shared_ptr<Piece> piece = nullptr, bool estOccupee = false);

    // Destructeur par défaut.
    ~Case() = default;

    // Accesseurs.
    const Position& getPosition() const;
    TypeCase getType() const;
    std::shared_ptr<Piece> getPieceCourrante() const;
    bool getEstOccupee() const;

    // Mutateurs.
    void setOccupee(bool occupee);
    void setPieceCourrante(std::shared_ptr<Piece> piece);

    // Opérateur d'affectation.
    Case& operator=(const Case& autre);

    // Opérateur de sortie.
    friend std::ostream& operator<<(std::ostream& out, const Case& c);
};

#endif


