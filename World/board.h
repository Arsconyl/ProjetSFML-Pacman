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
#include <iostream>
#include <string>
#include <fstream>


class board
{
public:
    Graphe<VArete, VSommet> graphe;
    vector<Sommet<VSommet> *> sommets;
    vector<Arete<VArete, VSommet> *> aretes;
    std::vector<std::vector<std::pair <  int, int>>> graph = std::vector<std::vector<std::pair < int, int>>> (24);
    int score;

    board()
    {
        for (unsigned int i = 0; i < 25; i++)
        {
            sommets.push_back(graphe.creeSommet(VSommet(Vecteur2D(i / 5, i % 5))));
        }

        ifstream fichier("Graphe files/graphe.txt",
                         ios::in);  // on ouvre en lecture

        if (fichier)  // si l'ouverture a fonctionné
        {
            string line;
            int numeroSommet = 0;
            while (getline(fichier, line))  // tant que l'on peut mettre la ligne dans "contenu"
            {

                int len = line.length();
                vector<string> subArray;

                for (int j = 0, k = 0; j < len; j++) {
                    if (line[j] == ',') {
                        string ch = line.substr(k, j - k);
                        k = j + 1;
                        subArray.push_back(ch);
                    }
                    if (j == len - 1) {
                        string ch = line.substr(k, j - k + 1);
                        subArray.push_back(ch);
                    }
                }

                for (int i = 0; i < subArray.size(); i = i + 2) {
                    graph[numeroSommet].push_back(make_pair(stoi(subArray[i]),stoi(subArray[i+1])));

                }

                numeroSommet++;

            }
            fichier.close();
        } else {
            cerr << "Impossible d'ouvrir le fichier !" << endl;
        }


        for(int i=0; i<24; i++){
            for(int j=0; j<graph[i].size(); j++) {
                aretes.push_back(graphe.creeArete(graph[i][j].first, sommets[i], sommets[graph[i][j].second]));
            }
        }

               /* aretes.push_back(graphe.creeArete(-2, sommets[0], sommets[5]));
                aretes.push_back(graphe.creeArete(-1, sommets[0], sommets[6]));
                aretes.push_back(graphe.creeArete( 0, sommets[0], sommets[1]));

                aretes.push_back(graphe.creeArete(-2, sommets[1], sommets[6]));
                aretes.push_back(graphe.creeArete(-1, sommets[1], sommets[7]));
                aretes.push_back(graphe.creeArete( 0, sommets[1], sommets[2]));

                aretes.push_back(graphe.creeArete(-2, sommets[2], sommets[7]));
                aretes.push_back(graphe.creeArete( 0, sommets[2], sommets[3]));

                aretes.push_back(graphe.creeArete(-3, sommets[3], sommets[7]));
                aretes.push_back(graphe.creeArete(-2, sommets[3], sommets[8]));
                aretes.push_back(graphe.creeArete( 0, sommets[3], sommets[4]));

                aretes.push_back(graphe.creeArete(-3, sommets[4], sommets[8]));
                aretes.push_back(graphe.creeArete(-2, sommets[4], sommets[9]));

                aretes.push_back(graphe.creeArete(-2, sommets[5], sommets[10]));
                aretes.push_back(graphe.creeArete(-1, sommets[5], sommets[11]));
                aretes.push_back(graphe.creeArete( 0, sommets[5], sommets[6]));

                aretes.push_back(graphe.creeArete(-2, sommets[6], sommets[11]));
                aretes.push_back(graphe.creeArete(-1, sommets[6], sommets[12]));
                aretes.push_back(graphe.creeArete( 0, sommets[6], sommets[7]));

                aretes.push_back(graphe.creeArete(-2, sommets[7], sommets[12]));
                aretes.push_back(graphe.creeArete( 0, sommets[7], sommets[8]));

                aretes.push_back(graphe.creeArete(-2, sommets[8], sommets[13]));
                aretes.push_back(graphe.creeArete( 0, sommets[8], sommets[9]));
                aretes.push_back(graphe.creeArete(-3, sommets[8], sommets[12]));

                aretes.push_back(graphe.creeArete(-3, sommets[9], sommets[13]));
                aretes.push_back(graphe.creeArete(-2, sommets[9], sommets[14]));

                aretes.push_back(graphe.creeArete(-2, sommets[10], sommets[15]));
                aretes.push_back(graphe.creeArete( 0, sommets[10], sommets[11]));

                aretes.push_back(graphe.creeArete(-3, sommets[11], sommets[15]));
                aretes.push_back(graphe.creeArete(-2, sommets[11], sommets[16]));
                aretes.push_back(graphe.creeArete( 0, sommets[11], sommets[12]));

                aretes.push_back(graphe.creeArete(-3, sommets[12], sommets[16]));
                aretes.push_back(graphe.creeArete(-2, sommets[12], sommets[17]));
                aretes.push_back(graphe.creeArete(-1, sommets[12], sommets[18]));
                aretes.push_back(graphe.creeArete( 0, sommets[12], sommets[13]));

                aretes.push_back(graphe.creeArete(-2, sommets[13], sommets[18]));
                aretes.push_back(graphe.creeArete(-1, sommets[13], sommets[19]));
                aretes.push_back(graphe.creeArete( 0, sommets[13], sommets[14]));

                aretes.push_back(graphe.creeArete(-2, sommets[14], sommets[19]));

                aretes.push_back(graphe.creeArete(-2, sommets[15], sommets[20]));
                aretes.push_back(graphe.creeArete( 0, sommets[15], sommets[16]));

                aretes.push_back(graphe.creeArete(-3, sommets[16], sommets[20]));
                aretes.push_back(graphe.creeArete(-2, sommets[16], sommets[21]));
                aretes.push_back(graphe.creeArete( 0, sommets[16], sommets[17]));

                aretes.push_back(graphe.creeArete(-3, sommets[17], sommets[21]));
                aretes.push_back(graphe.creeArete(-2, sommets[17], sommets[22]));
                aretes.push_back(graphe.creeArete(-1, sommets[17], sommets[23]));
                aretes.push_back(graphe.creeArete( 0, sommets[17], sommets[18]));

                aretes.push_back(graphe.creeArete(-2, sommets[18], sommets[23]));
                aretes.push_back(graphe.creeArete(-1, sommets[18], sommets[24]));
                aretes.push_back(graphe.creeArete( 0, sommets[18], sommets[19]));

                aretes.push_back(graphe.creeArete(-2, sommets[19], sommets[24]));

                aretes.push_back(graphe.creeArete( 0, sommets[20], sommets[21]));

                aretes.push_back(graphe.creeArete( 0, sommets[21], sommets[22]));

                aretes.push_back(graphe.creeArete( 0, sommets[22], sommets[23]));

                aretes.push_back(graphe.creeArete( 0, sommets[23], sommets[24]));
*/



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

    bool aMangayTouteGommes() const
    {
        for (Sommet<VSommet> * s: sommets)
        {
            if (s->v.isGom()) return false;
        }
        return true;
    }

    void reinitialiserGommes()
    {
        for (Sommet<VSommet> * s: sommets)
        {
            s->v.setGom(true);
        }
    }

    void incrementScore()
    {
        score = (score / 2500) * 2500;
        if(score == 1)
            score = 0;

        for (Sommet<VSommet> * s: sommets)
        {
            score+=100 * (!s->v.isGom());
        }
    }


};


#endif //PROJETSFML_PACMAN_BOARD_H
