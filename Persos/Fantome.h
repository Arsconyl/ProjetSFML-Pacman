//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_FANTOME_H
#define GRAPHES_FANTOME_H


#include "Personnage.h"


template<class S, class T>
class Fantome : public Personnage<S, T>
{
public:
    Fantome<S, T>(Sommet<T> *positionS, int positionNum, string image, string nom, int etat=1);
    Fantome<S, T>(Fantome &p);
    virtual ~Fantome ();
};
template<class S, class T>
Fantome<S, T>::Fantome(Fantome<S, T> &p):Personnage<S, T>(p){}
template<class S, class T>
Fantome<S, T>::Fantome(Sommet<T> *positionS, int positionNum, string image, string nom, int etat):Personnage<S, T>(positionS, positionNum, image, nom, etat){}
template<class S, class T>
Fantome<S, T>::~Fantome(){}


#endif //GRAPHES_FANTOME_H
