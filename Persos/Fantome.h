//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_FANTOME_H
#define GRAPHES_FANTOME_H


#include "Personnage.h"
#include "../World/board.h"


template<class S, class T>
class Fantome : public Personnage<S, T>
{
public:
    explicit Fantome<S, T>(Sommet<T> *position, string image, string nom, int etat=1);
    Fantome<S, T>(Fantome &p);
    virtual ~Fantome ();

    bool recherchePacmanDir (board &B, Pacman<S, T> pacman, Sommet<T> *s, int dir, int sens = 0);

    int aVuPacman (board &B, Pacman<S, T> pacman);
};
template<class S, class T>
Fantome<S, T>::Fantome(Fantome<S, T> &p):Personnage<S, T>(p){}

template<class S, class T>
Fantome<S, T>::Fantome(Sommet<T> *position, string image, string nom, int etat):Personnage<S, T>(position, image, nom, etat){}
template<class S, class T>
Fantome<S, T>::~Fantome ()
{}

template<class S, class T>
bool Fantome<S, T>::recherchePacmanDir (board &B, Pacman<S, T> pacman, Sommet<T> *s, int dir, int sens)
{
    PElement<pair<Sommet<T> *, Arete<S, T> *> > *adjacences = B.graphe.adjacences(s);
    while (adjacences)
    {
        if (adjacences->valeur->second->v.getDir() == dir)
        {
            if (adjacences->valeur->first == pacman.getPosition())
            {
                return true;
            } else
                return recherchePacmanDir(B, pacman, adjacences->valeur->first, dir);
        } else
            adjacences = adjacences->suivant;
    }
    return false;
}

template<class S, class T>
int Fantome<S, T>::aVuPacman (board &B, Pacman<S, T> pacman)
{
    if (recherchePacmanDir(B, pacman, getPosition(), 0))
        return 0;
    else if (recherchePacmanDir(B, pacman, getPosition(), -1))
        return -1;
    else if (recherchePacmanDir(B, pacman, getPosition(), -2))
        return -2;
    else if (recherchePacmanDir(B, pacman, getPosition(), -3))
        return -3;
    else
        return 1;

};


#endif //GRAPHES_FANTOME_H
