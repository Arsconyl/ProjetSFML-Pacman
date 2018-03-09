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
    explicit Fantome<S, T> (Sommet<T> *position, string image, string nom, Texture *texture, Vector2u imageCount,
                            float switchTime, float speed, TransfoAffine2D t, int etat = 1);
    Fantome<S, T>(Fantome &p);
    virtual ~Fantome ();

    void setPosition (Sommet<T> *position, TransfoAffine2D &t);
};
template<class S, class T>
Fantome<S, T>::Fantome(Fantome<S, T> &p):Personnage<S, T>(p){}

template<class S, class T>
Fantome<S, T>::Fantome (Sommet<T> *position, string nom, string image, Texture *texture, Vector2u imageCount,
                        float switchTime, float speed, TransfoAffine2D t, int etat):Personnage<S, T>(position, image,
                                                                                                     nom, texture,
                                                                                                     imageCount,
                                                                                                     switchTime, speed,
                                                                                                     t, etat)
{}
template<class S, class T>
Fantome<S, T>::~Fantome ()
{};

template<class S, class T>
void Fantome<S, T>::setPosition (Sommet<T> *position, TransfoAffine2D &t)
{
    Personnage<S, T>::setPosition(position, t);
}


#endif //GRAPHES_FANTOME_H
