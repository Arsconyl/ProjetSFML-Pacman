//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_PACMAN_H
#define GRAPHES_PACMAN_H

#include "Personnage.h"


template<class S, class T>
class Pacman : public Personnage<S, T>
{
public:
    Pacman<S, T>(Sommet<T> position, string image, string nom, int etat=1);
    Pacman<S, T>(Pacman &p);
    virtual ~Pacman ();
};
template<class S, class T>
Pacman<S, T>::Pacman(Pacman<S, T> &p):Personnage<S, T>(p){}
template<class S, class T>
Pacman<S, T>::Pacman(Sommet<T> position, string image, string nom, int etat):Personnage<S, T>(position, image, nom, etat){}
template<class S, class T>
Pacman<S, T>::~Pacman(){}


#endif //GRAPHES_PACMAN_H
