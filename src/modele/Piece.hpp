#ifndef PIECE_HPP
#define PIECE_HPP

#include <map>
#include <vector>
#include <memory>
#include <string>
#include "Case.hpp"
#include "Position.hpp"

// Déclarations anticipées pour éviter les inclusions circulaires.
class Case;
class Plateau;

// Enum pour les directions.
enum class Direction {
    Haut,
    Bas,
    Gauche,
    Droite
};

class Piece : public std::enable_shared_from_this<Piece> {
protected:
    std::weak_ptr<Case> caseCourrante;               // Référence faible vers la case actuelle.
    std::weak_ptr<Plateau> plateau;                  // Référence faible vers le plateau.
    std::map<int, std::vector<Position>> blocks;     // Map des blocs pour les états de rotation.
    int rotationState;                               // État actuel de rotation.

public:
    // Constructeur et destructeur.
    Piece(const std::weak_ptr<Case>& c, 
          std::map<int, std::vector<Position>> b, 
          const std::weak_ptr<Plateau>& p = std::weak_ptr<Plateau>(), 
          int rotation = 0);
    virtual ~Piece() = default;

    // Accesseurs.
    std::shared_ptr<Case> getCaseCourrante() const;
    std::shared_ptr<Plateau> getPlateau() const;
    std::map<int, std::vector<Position>> getBlocks() const;
    int getRotationState() const;

    // Méthodes principales (méthodes virtuelles pures).
    virtual std::string print() const = 0;             // Méthode virtuelle pure pour l'affichage.
    virtual void deplacer(Direction direction) = 0;    // Méthode virtuelle pure pour le déplacement.
    virtual void rotation() = 0;                       // Méthode virtuelle pure pour la rotation.
    virtual bool estDehors() const = 0;                // Méthode virtuelle pure pour vérifier les limites.

    // Opérateurs.
    bool operator==(const Piece& piece) const;
};

#endif // PIECE_HPP
