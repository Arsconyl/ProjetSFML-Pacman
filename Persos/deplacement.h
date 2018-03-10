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
#include <random>
#include "../Graphe/OutilsCarte.h"
#include "../Graphe/AStar.h"

using namespace sf;

class deplacement
{
private:
    template<class S, class T>
    static bool deplacementPacman (Pacman<S, T> &pacman, board &B, int dir, bool sens, TransfoAffine2D &t);

    template<class S, class T>
    static bool deplacementFantome (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, int dir, bool sens, TransfoAffine2D &t);

    template<class S, class T>
    static bool recherchePacmanParDir (board &B, Pacman<S, T> &pacman, Sommet<T> *actual, int dir, bool sens);

    template<class S, class T>
    static bool aVuPacmanParDir (board &B, Fantome<S, T> &fantome, Pacman<S, T> &pacman, TransfoAffine2D &t);

    template<class S, class T>
    static Sommet<T> *recherchePacmanParTemp (board &B, Fantome<S, T> &fantome);

    template<class S, class T>
    static bool aVuPacmanParTemp (board &B, Fantome<S, T> &fantome, Pacman<S, T> &pacman, TransfoAffine2D &t);
public:
    template<class S, class T>
    static bool gestionDeplacementPacman (Pacman<S, T> &pacman, Fantome<S, T> &fantome, board &B, TransfoAffine2D &t, bool (*lvlFantome)(Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t));
    template<class S, class T>
    static bool gestionDeplacementFantomeLvl1 (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t);

    template<class S, class T>
    static bool gestionDeplacementFantomeLvl2 (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t);

    template<class S, class T>
    static bool gestionDeplacementFantomeLvl3 (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t);
};

template<class S, class T>
bool deplacement::deplacementPacman (Pacman<S, T> &pacman, board &B, int dir, bool sens, TransfoAffine2D &t)
{
    /*sens à vrai pour deplacement vers sommet à clef inférieure(haut et gauche) et faux si deplacement vers sommet à clef supérieure (bas et droite)*/
    PElement<pair < Sommet < T> *, Arete <S, T>* > >  *adjacences = B.graphe.adjacences(pacman.getPosition());
    if (sens)
    {
        while(adjacences)
        {
            if((adjacences->valeur->second->v.getDir() == dir) && (adjacences->valeur->first->clef < pacman.getPosition()->clef))
            {
                pacman.setPosition(adjacences->valeur->first, t);
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
                pacman.setPosition(adjacences->valeur->first, t);
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
bool deplacement::deplacementFantome (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, int dir, bool sens, TransfoAffine2D &t)
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
                fantome.setPosition(adjacences->valeur->first, pacman, t);
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
                fantome.setPosition(adjacences->valeur->first, pacman, t);
                return true;
            } else
                adjacences = adjacences->suivant;
        }
        return false;
    }

}

template<class S, class T>
bool deplacement::recherchePacmanParDir (board &B, Pacman<S, T> &pacman, Sommet<T> *actual, int dir, bool sens)
{
    /*sens à vrai pour deplacement vers sommet à clef inférieure(haut et gauche) et faux si deplacement vers sommet à clef supérieure (bas et droite)*/
    if (actual == pacman.getPosition())
        return true;
    else
    {
        PElement<pair<Sommet<T> *, Arete<S, T> *> > *adjacences = B.graphe.adjacences(actual);
        if (sens)
        {
            while (adjacences)
            {
                if ((adjacences->valeur->second->v.getDir() == dir) &&
                    (adjacences->valeur->first->clef < actual->clef))
                {
                    return recherchePacmanParDir(B, pacman, adjacences->valeur->first, dir, sens);
                } else
                    adjacences = adjacences->suivant;
            }
            return false;
        } else
        {
            while (adjacences)
            {
                if ((adjacences->valeur->second->v.getDir() == dir) &&
                    (adjacences->valeur->first->clef > actual->clef))
                {
                    return recherchePacmanParDir(B, pacman, adjacences->valeur->first, dir, sens);
                } else
                    adjacences = adjacences->suivant;
            }
            return false;
        }
    }
}

template<class S, class T>
bool deplacement::aVuPacmanParDir (board &B, Fantome<S, T> &fantome, Pacman<S, T> &pacman, TransfoAffine2D &t)
{
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), -3, true)) //DownLeft
    {
        cout << "DownLeft" << endl;
        return deplacementFantome(fantome, pacman, B, -3, true, t);
    }
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), 0, false)) //Down
    {
        cout << "Down" << endl;
        return deplacementFantome(fantome, pacman, B, 0, false, t);
    }
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), -1, false)) //DownRight
    {
        cout << "DownRight" << endl;
        return deplacementFantome(fantome, pacman, B, -1, false, t);
    }
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), -2, true)) //Left
    {
        cout << "Left" << endl;
        return deplacementFantome(fantome, pacman, B, -2, true, t);
    }
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), -2, false)) //Right
    {
        cout << "Right" << endl;
        return deplacementFantome(fantome, pacman, B, -2, false, t);
    }
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), -1, true)) //UpLeft
    {
        cout << "UpLeft" << endl;
        return deplacementFantome(fantome, pacman, B, -1, true, t);
    }
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), 0, true)) //Up
    {
        cout << "Up" << endl;
        return deplacementFantome(fantome, pacman, B, 0, true, t);
    }
    if (recherchePacmanParDir(B, pacman, fantome.getPosition(), -3, false)) //UpRight
    {
        cout << "UpRight" << endl;
        return deplacementFantome(fantome, pacman, B, -3, false, t);
    }

}

template<class S, class T>
Sommet<T> *deplacement::recherchePacmanParTemp (board &B, Fantome<S, T> &fantome)
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
bool deplacement::aVuPacmanParTemp (board &B, Fantome<S, T> &fantome, Pacman<S, T> &pacman, TransfoAffine2D &t)
{
    Sommet<T> *trouve = recherchePacmanParTemp(B, fantome);
    if (trouve)
    {
        fantome.setPosition(trouve, pacman, t);
        return true;
    } else
        return false;
}

template<class S, class T>
bool deplacement::gestionDeplacementPacman (Pacman<S, T> &pacman, Fantome<S, T> &fantome, board &B, TransfoAffine2D &t, bool (*lvlFantome)(Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t))
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) //DownLeft
    {
        if (deplacementPacman(pacman, B, -3, true, t))
            return lvlFantome(fantome, pacman, B, t);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) //Down
    {
        if(deplacementPacman(pacman, B, 0, false, t))
            return lvlFantome(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) //DownRight
    {
       if(deplacementPacman(pacman, B, -1, false, t))
            return lvlFantome(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) //Left
    {
        if(deplacementPacman(pacman, B, -2, true, t))
            return lvlFantome(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) //Right
    {
        if(deplacementPacman(pacman, B, -2, false, t))
            return lvlFantome(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) //UpLeft
    {
        if(deplacementPacman(pacman, B, -1, true, t))
            return lvlFantome(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) //Up
    {
        if(deplacementPacman(pacman, B, 0, true, t))
            return lvlFantome(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) //UpRight
    {
        if(deplacementPacman(pacman, B, -3, false, t))
            return lvlFantome(fantome, pacman, B, t);
    }
    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) //DownLeft
    {
        if (deplacementPacman(pacman, B, -3, true, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) //Down
    {
        if(deplacementPacman(pacman, B, 0, false, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) //DownRight
    {
       if(deplacementPacman(pacman, B, -1, false, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) //Left
    {
        if(deplacementPacman(pacman, B, -2, true, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) //Right
    {
        if(deplacementPacman(pacman, B, -2, false, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) //UpLeft
    {
        if(deplacementPacman(pacman, B, -1, true, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) //Up
    {
        if(deplacementPacman(pacman, B, 0, true, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) //UpRight
    {
        if(deplacementPacman(pacman, B, -3, false, t))
            return deplacement::gestionDeplacementFantomeLvl2(fantome, pacman, B, t);
    }*/
}

template<class S, class T>
bool deplacement::gestionDeplacementFantomeLvl1 (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t)
{
    PElement <Sommet<T>> *voisins = B.graphe.voisins(fantome.getPosition());
    int nbVoisins = PElement<Sommet<T>>::taille(voisins), i=1;
    int dir = rand() % nbVoisins;
    //default_random_engine generator;
    //uniform_int_distribution<int> distribution(1, nbVoisins);
    //int dir = distribution(generator);
    while(i <= dir)
    {
        voisins = voisins->suivant;
        i++;
    }
    fantome.setPosition(voisins->valeur, pacman, t);


}

template<class S, class T>
bool deplacement::gestionDeplacementFantomeLvl2 (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t)
{
    if (!aVuPacmanParDir(B, fantome, pacman, t))
    {
        if (!aVuPacmanParTemp(B, fantome, pacman, t))
            return gestionDeplacementFantomeLvl1(fantome, pacman, B, t);
        else
            ;
    }
    else
        ;
}


template<class S, class T>
bool deplacement::gestionDeplacementFantomeLvl3 (Fantome<S, T> &fantome, Pacman<S, T> &pacman, board &B, TransfoAffine2D &t) {
    Sommet<VSommet> * resultat;
    OutilsCarte::cible = pacman.getPosition();

    //cout << pacman.getEtat() << endl;

    resultat = AStarT< Graphe<VArete,VSommet>,Sommet<VSommet> >::aStar( B.graphe, fantome.getPosition(),  OutilsCarte::hh);

    if (resultat == NULL)
    {
        cout << "Chemin AStar non trouvé" << endl;
        return false;
    }

    else
    {
        PElement<Sommet<VSommet>> * chem;
        chemin(pacman.getPosition(), chem);
        if(PElement<Sommet<VSommet>>::taille(chem) > 1)
        {
            fantome.setPosition(chem->suivant->valeur, pacman, t);
        }
        return true;
    }
};


#endif //PROJETSFML_PACMAN_DEPLACEMENT_H
