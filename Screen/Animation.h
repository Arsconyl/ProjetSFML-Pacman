//
// Created by arnaud on 12/02/18.
//

#ifndef PROJETSFML_PACMAN_ANIMATION_H
#define PROJETSFML_PACMAN_ANIMATION_H


#include "../Persos/Personnage.h"
#include "../Persos/Pacman.h"

class Animation
{
public:
    template <class S, class T>
    static void AnimePacmanDroit(FenetreSFML<S, T> fen, Pacman pacman);

};


#endif //PROJETSFML_PACMAN_ANIMATION_H
