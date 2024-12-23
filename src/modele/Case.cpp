#include "Case.hpp"

// Constructeur.
Case::Case(const Position& position, TypeCase type, std::shared_ptr<Piece> piece, bool estOccupee)
    : position(position), type(type), estOccupee(estOccupee), pieceCourrante(piece) {}

// Accesseurs.
const Position& Case::getPosition() const {
    return position;
}

TypeCase Case::getType() const {
    return type;
}

std::shared_ptr<Piece> Case::getPieceCourrante() const {
    return pieceCourrante;
}

bool Case::getEstOccupee() const {
    return estOccupee;
}

// Mutateurs.
void Case::setOccupee(bool occupee) {
    estOccupee = occupee;
}

void Case::setPieceCourrante(std::shared_ptr<Piece> piece) {
    if (type == TypeCase::Paysage) {
        throw std::runtime_error("Erreur : Impossible de placer une pièce sur une case de type Paysage.");
    }
    pieceCourrante = piece;
    estOccupee = (piece != nullptr);
}

// Opérateur d'affectation.
Case& Case::operator=(const Case& autre) {
    if (this != &autre) {
        position = autre.position;
        type = autre.type;
        estOccupee = autre.estOccupee;
        pieceCourrante = autre.pieceCourrante;
    }
    return *this;
}

// Opérateur de sortie.
std::ostream& operator<<(std::ostream& out, const Case& c) {
    out << "Case(Position: " << c.position
        << ", Type: ";
    switch (c.type) {
        case TypeCase::Jeu:
            out << "Jeu";
            break;
        case TypeCase::Gagnante:
            out << "Gagnante";
            break;
        case TypeCase::Paysage:
            out << "Paysage";
            break;
    }
    out << ", EstOccupee: " << (c.estOccupee ? "Oui" : "Non")
        << ", Piece: " << (c.pieceCourrante ? "Présente" : "Aucune") << ")";
    return out;
}
