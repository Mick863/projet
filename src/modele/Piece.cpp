#include "Piece.hpp"
#include "Case.hpp"
#include "Plateau.hpp"
#include <stdexcept>

// Constructeur principal.
Piece::Piece(const std::weak_ptr<Case>& c, 
             std::map<int, std::vector<Position>> b, 
             const std::weak_ptr<Plateau>& p, 
             int rotation)
    : caseCourrante(c), blocks(std::move(b)), plateau(p), rotationState(rotation) {
    if (c.expired()) {
        throw std::invalid_argument("Case pointer is null or expired");
    }
}

std::shared_ptr<Case> Piece::getCaseCourrante() const {
    auto casePtr = caseCourrante.lock();
    if (!casePtr) {
        throw std::runtime_error("Erreur : Référence faible vers la case courante est expirée");
    }
    return casePtr;
}

std::shared_ptr<Plateau> Piece::getPlateau() const {
    auto plateauPtr = plateau.lock();
    if (!plateauPtr) {
        throw std::runtime_error("Erreur : Référence faible vers le plateau est expirée");
    }
    return plateauPtr;
}


// Accesseur pour les blocs.
std::map<int, std::vector<Position>> Piece::getBlocks() const {
    return blocks;
}

// Accesseur pour l'état de rotation.
int Piece::getRotationState() const {
    return rotationState;
}

// Opérateur d'égalité.
bool Piece::operator==(const Piece& piece) const {
    return getCaseCourrante() == piece.getCaseCourrante() &&
           blocks == piece.getBlocks() &&
           rotationState == piece.getRotationState();
}
