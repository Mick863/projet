#ifndef POSITION_HPP 
#define POSITION_HPP  
#include <iostream>
#include <stdexcept>
#include "config.hpp"
using namespace std;

class Position{
    private:
        int Ligne;
        int Colonne;


    public:
        Position(int Ligne , int Colonne);
        Position(int Ligne , int Colonne, int nbLigne, int nbColonne);
        Position(const Position &p) = default;
        int getLigne() const;
        int getColonne() const;
        void setLigne(int ligne);
        void setColonne(int colonne);
        virtual ~Position();
        Position &operator=(const Position &p);
        bool operator==(const Position &p) const;
        friend ostream & operator<<(ostream & out, const Position &position);
};

#endif  // POSITION_HPP
