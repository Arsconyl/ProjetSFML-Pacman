//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_PERSONNAGE_H
#define GRAPHES_PERSONNAGE_H

#include "../Graphe/Sommet.h"
#include "../World/Thing.h"
#include <string>

using namespace std;

template<class S, class T>
class Personnage : public Thing<S, T>
{
public:
    Personnage<S, T>(Sommet<T> position, string image, string nom, int etat=1);
    Personnage<S, T>(Personnage &p);
    virtual ~Personnage ();
};
template<class S, class T>
Personnage<S, T>::Personnage(Personnage<S, T> &p):Thing<S, T>(p){}
template<class S, class T>
Personnage<S, T>::Personnage(Sommet<T> position, string nom, string image, int etat):Thing<S, T>(position, image, nom, etat){}
template<class S, class T>
Personnage<S, T>::~Personnage(){}


#endif //GRAPHES_PERSONNAGE_H