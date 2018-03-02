//
// Created by arnaud on 01/03/18.
//

#ifndef PROJETSFML_PACMAN_VARETE_H
#define PROJETSFML_PACMAN_VARETE_H

#include <utility>
#include <sstream>
#include <string>

using namespace std;

class VArete
{
private:
    int sens1, sens2;
public:
    inline void setSens1 (int sens1);
    inline void setSens2 (int sens2);
public:
    VArete (int sens1, int sens2);
    virtual ~VArete ();
    VArete (const VArete &va);

    explicit operator string () const;

    friend ostream& operator<< (ostream &o, const VArete &va);

    int getSens1 () const;

    int getSens2 () const;
};

inline void VArete::setSens1 (int sens1)
{
    VArete::sens1 = sens1;
}

inline void VArete::setSens2 (int sens2)
{
    VArete::sens2 = sens2;
}

VArete::VArete (int sens1, int sens2) : sens1(sens1), sens2(sens2)
{}

VArete::~VArete ()
= default;

VArete::VArete (const VArete &va): sens1(va.sens1), sens2(va.sens2)
{}

inline int VArete::getSens1 () const
{
    return sens1;
}

inline int VArete::getSens2 () const
{
    return sens2;
}

VArete::operator string () const
{
    ostringstream oss;

    oss <<"VArete : Sens 1 : " << sens1 << " Sens2 : " << sens2;
    return oss.str();
}

ostream &operator<< (ostream &o, const VArete &va)
{
    o << (string)va;
}


#endif //PROJETSFML_PACMAN_VARETE_H
