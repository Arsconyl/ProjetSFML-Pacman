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
    static bool deplacementPacman (Pacman<S, T> &pacman, board &B, int dir, bool sens);

    template<class S, class T>
    static bool deplacementFantome (Fantome<S, T> &fantome, board &B, int dir, bool sens);

    template<class S, class T>
    static bool recherchePacmanParDir (board &B, Pacman<S, T> pacman, Fantome<S, T> &fantome, int dir, bool sens);

    template<class S, class T>
    static bool aVuPacmanParDir (board &B, Fantome<S, T> &fantome, Pacman<S, T> pacman);

    template<class S, class T>
    static Sommet<T> *recherchePacmanParTemp (board &B, Pacman<S, T> pacman, Fantome<S, T> &fantome);

    template<class S, class T>
    static bool aVuPacmanParTemp (board &B, Fantome<S, T> &fantome, Pacman<S, T> pacman);
public:
    template<class S, class T>
    static bool gestionDeplacementPacman(Pacman<S, T> &pacman, board &B);
    template<class S, class T>
    static bool gestionDeplacementFantomeLvl1(Fantome<S, T> &fantome, board &B);

    template<class S, class T>
    static bool gestionDeplacementFantomeLvl2 (Fantome<S, T> &fantome, Pacman<S, T> pacman, board &B);
};

template<class S, class T>
bool deplacement::deplacementPacman (Pacman<S, T> &pacman, board &B, int dir, bool sens)
{
    /*sens à vrai pour deplacement vers sommet à clef inférieure(haut et gauche) et faux si deplacement vers sommet à clef supérieure (bas et droite)*/
    PElement<pair < Sommet < T> *, Arete <S, T>* > >  *adjacences = B.graphe.adjacences(pacman.getPosition());
    if (sens)
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
bool deplacement::deplacementFantome (Fantome<S, T> &fantome, board &B, int dir, bool sens)
{
    /*sens à vrai pour deplacement vers sommet à clef inférieure(haut et gauche) et faux si deplacement vers sommet à clef supérieure (bas et droite)*/
    PElement<pair<Sommet<T> *, Arete<S, T> *> > *adjacences = B.graphe.adjacences(fantome.getPosition());
    if (sens)
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
bool deplacement::recherchePacmanParDir (board &B, Pacman<S, T> pacman, Fantome<S, T> &fantome, int dir, bool sens)
{
    /*sens à vrai pour deplacement vers sommet à clef inférieure(haut et gauche) et faux si deplacement vers sommet à clef supérieure (bas et droite)*/
    PElement<pair<Sommet<T> *, Arete<S, T> *> > *adjacences = B.graphe.adjacences(fantome.getPosition());
    if (sens)
    {
        while (adjacences)
        {
            if ((adjacences->valeur->second->v.getDir() == dir) &&
                (adjacences->valeur->first->clef < fantome.getPosition()->clef))
            {
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
                return true;
            } else
                adjacences = adjacences->suivant;
        }
        return false;
    }
}

template<class S, class T>
bool deplacement::aVuPacmanParDir (board &B, Fantome<S, T> &fantome, Pacman<S, T> pacman)
{
    if (recherchePacmanParDir(B, pacman, fantome, -3, true)) //DownLeft
    {
        return deplacementFantome(fantome, B, -3, true);
    }
    if (recherchePacmanParDir(B, pacman, fantome, 0, false)) //Down
    {
        return deplacementFantome(fantome, B, 0, false);
    }
    if (recherchePacmanParDir(B, pacman, fantome, -1, false)) //DownRight
    {
        return deplacementFantome(fantome, B, -1, false);
    }
    if (recherchePacmanParDir(B, pacman, fantome, -2, true)) //Left
    {
        return deplacementFantome(fantome, B, -2, true);
    }
    if (recherchePacmanParDir(B, pacman, fantome, -2, false)) //Right
    {
        return deplacementFantome(fantome, B, -2, false);
    }
    if (recherchePacmanParDir(B, pacman, fantome, -1, true)) //UpLeft
    {
        return deplacementFantome(fantome, B, -1, true);
    }
    if (recherchePacmanParDir(B, pacman, fantome, 0, true)) //Up
    {
        return deplacementFantome(fantome, B, 0, true);
    }
    if (recherchePacmanParDir(B, pacman, fantome, -3, false)) //UpRight
    {
        return deplacementFantome(fantome, B, -3, false);
    }

}

template<class S, class T>
Sommet<T> *deplacement::recherchePacmanParTemp (board &B, Pacman<S, T> pacman, Fantome<S, T> &fantome)
{
    /*sens à vrai pour deplacement vers sommet à clef inférieure(haut et gauche) et faux si deplacement vers sommet à clef supérieure (bas et droite)*/
    PElement<pair<Sommet<T> *, Arete<S, T> *> > *adjacences = B.graphe.adjacences(fantome.getPosition());
    int tempTrouvee = 0;
    Sommet<T> *chemin4 = NULL, *chemin3 = NULL, *chemin2 = NULL, *chemin1 = NULL;
    while (adjacences)
    {
        if (adjacences->valeur->second->v.getTemp() == 4)
        {
            tempTrouvee = 4;
            chemin4 = adjacences->valeur->first;
            break;
        } else if (adjacences->valeur->second->v.getTemp() == 3)
        {
            if (tempTrouvee < 3)
            {
                tempTrouvee = 3;
                chemin3 = adjacences->valeur->first;
            }
        } else if (adjacences->valeur->second->v.getTemp() == 2)
        {
            if (tempTrouvee < 2)
            {
                tempTrouvee = 2;
                chemin2 = adjacences->valeur->first;
            }
        } else if (adjacences->valeur->second->v.getTemp() == 1)
        {
            if (tempTrouvee < 1)
            {
                tempTrouvee = 1;
                chemin1 = adjacences->valeur->first;
            }
        }
        adjacences = adjacences->suivant;
    }
    cout << tempTrouvee << endl;
    switch (tempTrouvee)
    {
        case 0:
            return NULL;
        case 1:
            return chemin1;
        case 2:
            return chemin2;
        case 3:
            return chemin3;
        case 4:
            return chemin4;
        default:
            return NULL;
    }
}

template<class S, class T>
bool deplacement::aVuPacmanParTemp (board &B, Fantome<S, T> &fantome, Pacman<S, T> pacman)
{
    Sommet<T> *trouve = recherchePacmanParTemp(B, pacman, fantome);
    if (trouve)
    {
        fantome.setPosition(trouve);
        return true;
    } else
        return false;
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
    //if(aVuPacmanParDir(B, fantome, pacman))
    //    return true;
    if (aVuPacmanParTemp(B, fantome, pacman))
    {
        return true;
    } else
        return gestionDeplacementFantomeLvl1(fantome, B);

}


#endif //PROJETSFML_PACMAN_DEPLACEMENT_H
