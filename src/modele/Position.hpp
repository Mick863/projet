#include <iostream>
using namespace std;

class Position{
    private:
        int Ligne;
        int Colonne;

    public:
        Position(int Ligne , int Colonne);
        int getLigne() const;
        int getColonne() const;
        virtual ~Position();
        Position &operator=(const Position &p);
        friend ostream & operator<<(ostream & out, const Position &position);
};


