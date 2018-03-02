//
// Created by arnaud on 27/02/18.
//

#ifndef PROJETSFML_PACMAN_BOARD_H
#define PROJETSFML_PACMAN_BOARD_H

#include "../Graphe/Graphe.h"
#include "../Graphe/Arete.h"
#include "../Graphe/VSommet.h"
#include "../Graphe/VArete.h"
#include <vector>


class board
{
public:
    Graphe<VArete, VSommet> graphe;
    vector<Sommet<VSommet> *> sommets;
    vector<Arete<VArete, VSommet> *> aretes;

    board()
    {
        for (unsigned int i = 0; i < 25; i++)
        {
            sommets.push_back(graphe.creeSommet(VSommet(Vecteur2D(i / 5, i % 5))));
        }

        aretes.push_back(graphe.creeArete(-2, sommets[0], sommets[5]));
        aretes.push_back(graphe.creeArete(-1, sommets[0], sommets[6]));
        aretes.push_back(graphe.creeArete(0, sommets[0], sommets[1]));
        aretes.push_back(graphe.creeArete(-2, sommets[1], sommets[6]));
        aretes.push_back(graphe.creeArete(-1, sommets[1], sommets[7]));
        aretes.push_back(graphe.creeArete(0, sommets[1], sommets[2]));
        aretes.push_back(graphe.creeArete(-2, sommets[2], sommets[7]));
        aretes.push_back(graphe.creeArete(0, sommets[2], sommets[3]));
        aretes.push_back(graphe.creeArete(-3, sommets[3], sommets[7]));
        aretes.push_back(graphe.creeArete(-2, sommets[3], sommets[8]));
        aretes.push_back(graphe.creeArete(0, sommets[3], sommets[4]));
        aretes.push_back(graphe.creeArete(-3, sommets[4], sommets[8]));
        aretes.push_back(graphe.creeArete(-2, sommets[4], sommets[9]));
        aretes.push_back(graphe.creeArete(-2, sommets[5], sommets[10]));
        aretes.push_back(graphe.creeArete(-1, sommets[5], sommets[11]));
        aretes.push_back(graphe.creeArete(0, sommets[5], sommets[6]));
        aretes.push_back(graphe.creeArete(-2, sommets[6], sommets[11]));
        aretes.push_back(graphe.creeArete(-1, sommets[6], sommets[12]));
        aretes.push_back(graphe.creeArete(0, sommets[6], sommets[7]));
        aretes.push_back(graphe.creeArete(-2, sommets[7], sommets[12]));
        aretes.push_back(graphe.creeArete(0, sommets[7], sommets[8]));
        aretes.push_back(graphe.creeArete(-2, sommets[8], sommets[13]));
        aretes.push_back(graphe.creeArete(0, sommets[8], sommets[9]));
        aretes.push_back(graphe.creeArete(-3, sommets[8], sommets[12]));
        aretes.push_back(graphe.creeArete(-3, sommets[9], sommets[13]));
        aretes.push_back(graphe.creeArete(-2, sommets[9], sommets[14]));
        aretes.push_back(graphe.creeArete(-2, sommets[10], sommets[15]));
        aretes.push_back(graphe.creeArete(0, sommets[10], sommets[11]));
        aretes.push_back(graphe.creeArete(-3, sommets[11], sommets[15]));
        aretes.push_back(graphe.creeArete(-2, sommets[11], sommets[16]));
        aretes.push_back(graphe.creeArete(0, sommets[11], sommets[12]));
        aretes.push_back(graphe.creeArete(-3, sommets[12], sommets[16]));
        aretes.push_back(graphe.creeArete(-2, sommets[12], sommets[17]));
        aretes.push_back(graphe.creeArete(-1, sommets[12], sommets[18]));
        aretes.push_back(graphe.creeArete(0, sommets[12], sommets[13]));
        aretes.push_back(graphe.creeArete(-2, sommets[13], sommets[18]));
        aretes.push_back(graphe.creeArete(-1, sommets[13], sommets[19]));
        aretes.push_back(graphe.creeArete(0, sommets[13], sommets[14]));
        aretes.push_back(graphe.creeArete(-2, sommets[14], sommets[19]));
        aretes.push_back(graphe.creeArete(-2, sommets[15], sommets[20]));
        aretes.push_back(graphe.creeArete(0, sommets[15], sommets[16]));
        aretes.push_back(graphe.creeArete(-3, sommets[16], sommets[20]));
        aretes.push_back(graphe.creeArete(-2, sommets[16], sommets[21]));
        aretes.push_back(graphe.creeArete(0, sommets[16], sommets[17]));
        aretes.push_back(graphe.creeArete(-3, sommets[17], sommets[21]));
        aretes.push_back(graphe.creeArete(-2, sommets[17], sommets[22]));
        aretes.push_back(graphe.creeArete(-1, sommets[17], sommets[23]));
        aretes.push_back(graphe.creeArete(0, sommets[17], sommets[18]));
        aretes.push_back(graphe.creeArete(-2, sommets[18], sommets[23]));
        aretes.push_back(graphe.creeArete(-1, sommets[18], sommets[24]));
        aretes.push_back(graphe.creeArete(0, sommets[18], sommets[19]));
        aretes.push_back(graphe.creeArete(-2, sommets[19], sommets[24]));
        aretes.push_back(graphe.creeArete(0, sommets[20], sommets[21]));
        aretes.push_back(graphe.creeArete(0, sommets[21], sommets[22]));
        aretes.push_back(graphe.creeArete(0, sommets[22], sommets[23]));
        aretes.push_back(graphe.creeArete(0, sommets[23], sommets[24]));
    }

    virtual ~board ()
    = default;

    void refroiditToutesAretes()
    {
        for(unsigned int i = 0; i < aretes.size(); i++)
        {
            aretes[i]->v.operator--();
        }
    }
};


#endif //PROJETSFML_PACMAN_BOARD_H
