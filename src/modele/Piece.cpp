#include "Piece.hpp"
#include "Case.hpp"
#include "Plateau.hpp"
#include <stdexcept>
#include <iostream>

// Constructeur principal.
Piece::Piece(const std::weak_ptr<Case>& c, 
             std::map<int, std::vector<Position>> b, 
             const std::weak_ptr<Plateau>& p, 
             int rotation)
    : caseCourrante(c), plateau(p), blocks(std::move(b)), rotationState(rotation) {
    if (c.expired()) {
        throw std::invalid_argument("Erreur : La case courante référencée par weak_ptr est expirée ou nulle.");
    }
}

// Retourne la case actuelle (assure que le weak_ptr est valide).
std::shared_ptr<Case> Piece::getCaseCourrante() const {
    auto casePtr = caseCourrante.lock();
    if (!casePtr) {
        throw std::runtime_error("Erreur : Référence faible vers la case courante est expirée ou invalide.");
    }
    return casePtr;
}

// Retourne le plateau (assure que le weak_ptr est valide).
std::shared_ptr<Plateau> Piece::getPlateau() const {
    auto plateauPtr = plateau.lock();
    if (!plateauPtr) {
        throw std::runtime_error("Erreur : Référence faible vers le plateau est expirée ou invalide.");
    }
    return plateauPtr;
}

// Retourne les blocs associés à la pièce.
std::map<int, std::vector<Position>> Piece::getBlocks() const {
    return blocks;
}

// Retourne l'état actuel de rotation.
int Piece::getRotationState() const {
    return rotationState;
}

// Opérateur d'égalité : Compare deux pièces.
bool Piece::operator==(const Piece& piece) const {
    return getCaseCourrante() == piece.getCaseCourrante() &&
           blocks == piece.getBlocks() &&
           rotationState == piece.getRotationState();
}
