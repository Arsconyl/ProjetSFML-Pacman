//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_FANTOME_H
#define GRAPHES_FANTOME_H


#include "Personnage.h"


class Fantome:public Personnage
{
public:
    Fantome(Sommet position, bool etat, string nom);
    Fantome(Fantome &p);
    ~Fantome ();
};

Fantome::Fantome (Sommet position, bool etat, string nom) : Personnage(position, etat, nom) {}

Fantome::Fantome (Fantome &p):Personnage(p) {}

Fantome::~Fantome () {}


#endif //GRAPHES_FANTOME_H
