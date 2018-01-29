//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_PERSONNAGE_H
#define GRAPHES_PERSONNAGE_H

#include "../Fenetre/Sommet.h"
#include "../World/Thing.h"
#include <string>

using namespace std;


class Personnage : public Thing
{
private:
    Sommet position;
    bool etat;
    string nom;
public:
    Personnage(Sommet position, bool etat, string nom);
    Personnage(Personnage &p);
    virtual ~Personnage ();

    inline void setPosition(Sommet &pos);
    inline void toggleEtat();
    inline Sommet getPosition() const;
    inline bool getEtat() const;
    string getNom () const;
    void setNom (const string &nom);
};

Personnage::Personnage(Personnage &p):position(p.position), etat(p.etat), nom(p.nom){}

Personnage::Personnage(Sommet position, bool etat, string nom):position(position), etat(etat), nom(nom){}
Personnage::~Personnage(){}
inline void Personnage::setPosition(Sommet &pos)
{
    position = pos;
}
inline void Personnage::toggleEtat()
{
    etat = !etat;
}

void Personnage::setNom(const string &nom)
{
    Personnage::nom = nom;
}

inline bool Personnage::getEtat () const
{
    return etat;
}

inline Sommet Personnage::getPosition () const
{
    return position;
}

inline string Personnage::getNom () const
{
    return nom;
}


#endif //GRAPHES_PERSONNAGE_H