//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_PACMAN_H
#define GRAPHES_PACMAN_H

#include "Personnage.h"


class Pacman:public Personnage
{
public:
    Pacman(Sommet position, bool etat, string nom);
    Pacman(Pacman &p);
    ~Pacman ();
};

Pacman::Pacman (Sommet position, bool etat, string nom) : Personnage(position, etat, nom) {}

Pacman::Pacman (Pacman &p):Personnage(p) {}

Pacman::~Pacman () {}


#endif //GRAPHES_PACMAN_H
