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

class deplacement
{
public:
    template<class S, class T>
    static bool gestionDeplacementPacman(Pacman<S, T> &pacman, board &B);
    template<class S, class T>
    static bool gestionDeplacementFantomeLvl1(Fantome<S, T> &fantome, board &B);
};
template<class S, class T>
bool deplacement::gestionDeplacementPacman (Pacman<S, T> &pacman, board &B)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()-4]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()-4]);
            pacman.setPositionNum(pacman.getPositionNum()-4);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()+1]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()+1]);
            pacman.setPositionNum(pacman.getPositionNum()+1);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()+6]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()+6]);
            pacman.setPositionNum(pacman.getPositionNum()+6);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()-5]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()-5]);
            pacman.setPositionNum(pacman.getPositionNum()-5);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()+5]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()+5]);
            pacman.setPositionNum(pacman.getPositionNum()+5);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()-6]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()-6]);
            pacman.setPositionNum(pacman.getPositionNum()-6);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()+-1]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()-1]);
            pacman.setPositionNum(pacman.getPositionNum()-1);
            return true;
        }
        else
        {
            return false;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
    {
        if(B.graphe.getAreteParSommets(pacman.getPositionS(), B.sommets[pacman.getPositionNum()+4]))
        {
            pacman.setPositionS(B.sommets[pacman.getPositionNum()+4]);
            pacman.setPositionNum(pacman.getPositionNum()+4);
            return true;
        }

        else
        {
            return false;
        }
    }
}

template<class S, class T>
bool deplacement::gestionDeplacementFantomeLvl1(Fantome<S, T> &fantome, board &B)
{
    PElement <Sommet<T>> *voisins = B.graphe.voisins(fantome.getPositionS());
    int nbVoisins = PElement<Sommet<T>>::taille(voisins), i=1;
    int dir = rand() % nbVoisins;
    while(i <= dir)
    {
        voisins = voisins->suivant;
        i++;
    }
    fantome.setPositionS(voisins->valeur);

}



#endif //PROJETSFML_PACMAN_DEPLACEMENT_H
