//
// Created by arnaud on 28/02/18.
//

#ifndef PROJETSFML_PACMAN_DEPLACEMENT_H
#define PROJETSFML_PACMAN_DEPLACEMENT_H


#include <SFML/Window/Keyboard.hpp>
#include "Pacman.h"
#include "../World/board.h"
#include "Fantome.h"
#include <cstdlib>

using namespace sf;

class deplacement
{
private:
    template<class S, class T>
    static bool deplacementPacman(Pacman<S, T> &pacman, board &B, int dir, bool comp);

    template<class S, class T>
    static bool deplacementFantome (Fantome<S, T> &fantome, board &B, int dir, bool comp);
public:
    template<class S, class T>
    static bool gestionDeplacementPacman(Pacman<S, T> &pacman, board &B);
    template<class S, class T>
    static bool gestionDeplacementFantomeLvl1(Fantome<S, T> &fantome, board &B);

    template<class S, class T>
    static bool gestionDeplacementFantomeLvl2 (Fantome<S, T> &fantome, Pacman<S, T> pacman, board &B);
};

template<class S, class T>
bool deplacement::deplacementPacman (Pacman<S, T> &pacman, board &B, int dir, bool comp)
{
    /*Comp à vrai pour deplacement vers sommet à clef inférieure(haut et gauche) et faux si deplacement vers sommet à clef supérieure (bas et droite)*/
    PElement<pair < Sommet < T> *, Arete <S, T>* > >  *adjacences = B.graphe.adjacences(pacman.getPosition());
    if(comp)
    {
        while(adjacences)
        {
            if((adjacences->valeur->second->v.getDir() == dir) && (adjacences->valeur->first->clef < pacman.getPosition()->clef))
            {
                pacman.setPosition(adjacences->valeur->first);
                B.refroiditToutesAretes();
                adjacences->valeur->second->v.rechauffe();
                return true;
            }
            else
                adjacences = adjacences->suivant;
        }
        return false;
    }
    else
    {
        while(adjacences)
        {
            if((adjacences->valeur->second->v.getDir() == dir) && (adjacences->valeur->first->clef > pacman.getPosition()->clef))
            {
                pacman.setPosition(adjacences->valeur->first);
                B.refroiditToutesAretes();
                adjacences->valeur->second->v.rechauffe();
                return true;
            }
            else
                adjacences = adjacences->suivant;
        }
        return false;
    }

}

template<class S, class T>
bool deplacement::deplacementFantome (Fantome<S, T> &fantome, board &B, int dir, bool comp)
{
    PElement<pair<Sommet<T> *, Arete<S, T> *> > *adjacences = B.graphe.adjacences(fantome.getPosition());
    if (comp)
    {
        while (adjacences)
        {
            if ((adjacences->valeur->second->v.getDir() == dir) &&
                (adjacences->valeur->first->clef < fantome.getPosition()->clef))
            {
                fantome.setPosition(adjacences->valeur->first);
                return true;
            } else
                adjacences = adjacences->suivant;
        }
        return false;
    } else
    {
        while (adjacences)
        {
            if ((adjacences->valeur->second->v.getDir() == dir) &&
                (adjacences->valeur->first->clef > fantome.getPosition()->clef))
            {
                fantome.setPosition(adjacences->valeur->first);
                return true;
            } else
                adjacences = adjacences->suivant;
        }
        return false;
    }

}

template<class S, class T>
bool deplacement::gestionDeplacementPacman (Pacman<S, T> &pacman, board &B)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) //DownLeft
    {
        return deplacementPacman(pacman, B, -3, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) //Down
    {
        return deplacementPacman(pacman, B, 0, false);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) //DownRight
    {
        return deplacementPacman(pacman, B, -1, false);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) //Left
    {
        return deplacementPacman(pacman, B, -2, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) //Right
    {
        return deplacementPacman(pacman, B, -2, false);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) //UpLeft
    {
        return deplacementPacman(pacman, B, -1, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) //Up
    {
        return deplacementPacman(pacman, B, 0, true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) //UpRight
    {
        return deplacementPacman(pacman, B, -3, false);
    }
}

template<class S, class T>
bool deplacement::gestionDeplacementFantomeLvl1(Fantome<S, T> &fantome, board &B)
{
    PElement <Sommet<T>> *voisins = B.graphe.voisins(fantome.getPosition());
    int nbVoisins = PElement<Sommet<T>>::taille(voisins), i=1;
    int dir = rand() % nbVoisins;
    while(i <= dir)
    {
        voisins = voisins->suivant;
        i++;
    }
    fantome.setPosition(voisins->valeur);

}

template<class S, class T>
bool deplacement::gestionDeplacementFantomeLvl2 (Fantome<S, T> &fantome, Pacman<S, T> pacman, board &B)
{
    int aVuPacman = fantome.aVuPacman(B, pacman);
    if (aVuPacman != 1)
    {
        deplacementFantome(fantome, B, aVuPacman,)
    } else
        return gestionDeplacementFantomeLvl1(fantome, B);
}


#endif //PROJETSFML_PACMAN_DEPLACEMENT_H
