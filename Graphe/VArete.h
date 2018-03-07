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
    int dir, temp;
    inline void setDir (int dir);
public:
    VArete (int dir, int temp = 0);
    virtual ~VArete ();
    VArete (const VArete &va);

    explicit operator string () const;
    void operator--();
    void rechauffe();

    friend ostream& operator<< (ostream &o, const VArete &va);

    inline int getDir () const;
    inline int getTemp () const;
    inline void setTemp (int temp);
};

inline void VArete::setDir (int dir)
{
    VArete::dir = dir;
}

inline void VArete::setTemp (int temp)
{
    VArete::temp = temp;
}

VArete::VArete (int dir, int temp) : dir(dir), temp(temp)
{}

VArete::~VArete ()
= default;

VArete::VArete (const VArete &va): dir(va.dir), temp(va.temp)
{}

inline int VArete::getDir () const
{
    return dir;
}

inline int VArete::getTemp () const
{
    return temp;
}

VArete::operator string () const
{
    ostringstream oss;

    oss << "VArete : Dir : " << dir << " temp : " << temp;
    return oss.str();
}

ostream &operator<< (ostream &o, const VArete &va)
{
    o << (string)va;
}

void VArete::operator-- ()
{
    if(temp > 0)
    {
        temp--;
    }
}

void VArete::rechauffe ()
{
    this->temp = 5;
}


#endif //PROJETSFML_PACMAN_VARETE_H
