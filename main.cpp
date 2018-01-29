
#include <iostream>
#include "Graphe/Graphe.h"
#include "Persos/Pacman.h"
#include "World/Gom.h"
#include "SFML/System.hpp"

using namespace std;
using namespace sf;
int main()
{
    Graphe<int, Vector2f> g1;
    Sommet<Vector2f> *S[25];

    for(unsigned int i = 0; i<25; i++)
    {
        S[i] = g1.creeSommet(Vector2f((100*(i / 5))+70, 100*((i % 5))+70));
    }

    Arete<int, Vector2f> *A[54];

    A[0] = g1.creeArete(-2, S[0], S[5]);
    A[1] = g1.creeArete(-1, S[0], S[6]);
    A[2] = g1.creeArete(0, S[0], S[1]);
    A[3] = g1.creeArete(-2, S[1], S[6]);
    A[4] = g1.creeArete(-1, S[1], S[7]);
    A[5] = g1.creeArete(0, S[1], S[2]);
    A[6] = g1.creeArete(-2, S[2], S[7]);
    A[7] = g1.creeArete(0, S[2], S[3]);
    A[8] = g1.creeArete(-2, S[3], S[8]);
    A[9] = g1.creeArete(0, S[3], S[4]);
    A[10] = g1.creeArete(-3, S[4], S[8]);
    A[11] = g1.creeArete(-2, S[4], S[9]);
    A[12] = g1.creeArete(-2, S[5], S[10]);
    A[13] = g1.creeArete(-1, S[5], S[11]);
    A[14] = g1.creeArete(0, S[5], S[6]);
    A[15] = g1.creeArete(-2, S[6], S[11]);
    A[16] = g1.creeArete(-1, S[6], S[12]);
    A[17] = g1.creeArete(0, S[6], S[7]);
    A[18] = g1.creeArete(-2, S[7], S[12]);
    A[19] = g1.creeArete(0, S[7], S[8]);
    A[20] = g1.creeArete(-2, S[8], S[13]);
    A[21] = g1.creeArete(0, S[8], S[9]);
    A[22] = g1.creeArete(-3, S[8], S[12]);
    A[23] = g1.creeArete(-3, S[9], S[13]);
    A[24] = g1.creeArete(-2, S[9], S[14]);
    A[25] = g1.creeArete(-2, S[10], S[15]);
    A[26] = g1.creeArete(0, S[10], S[11]);
    A[27] = g1.creeArete(-3, S[11], S[15]);
    A[28] = g1.creeArete(-2, S[11], S[16]);
    A[29] = g1.creeArete(0, S[11], S[12]);
    A[30] = g1.creeArete(-3, S[12], S[16]);
    A[33] = g1.creeArete(-2, S[12], S[17]);
    A[34] = g1.creeArete(-1, S[12], S[18]);
    A[35] = g1.creeArete(0, S[12], S[13]);
    A[36] = g1.creeArete(-2, S[13], S[18]);
    A[37] = g1.creeArete(-1, S[13], S[19]);
    A[38] = g1.creeArete(0, S[13], S[14]);
    A[39] = g1.creeArete(-2, S[14], S[19]);
    A[40] = g1.creeArete(-2, S[15], S[20]);
    A[41] = g1.creeArete(0, S[15], S[16]);
    A[42] = g1.creeArete(-3, S[16], S[20]);
    A[43] = g1.creeArete(-2, S[16], S[21]);
    A[44] = g1.creeArete(0, S[16], S[17]);
    A[45] = g1.creeArete(-3, S[17], S[21]);
    A[46] = g1.creeArete(-2, S[17], S[22]);
    A[47] = g1.creeArete(-1, S[17], S[23]);
    A[48] = g1.creeArete(0, S[17], S[18]);
    A[46] = g1.creeArete(-2, S[18], S[23]);
    A[47] = g1.creeArete(-1, S[18], S[24]);
    A[48] = g1.creeArete(0, S[18], S[19]);
    A[49] = g1.creeArete(-2, S[19], S[24]);
    A[50] = g1.creeArete(0, S[20], S[21]);
    A[51] = g1.creeArete(0, S[21], S[22]);
    A[52] = g1.creeArete(0, S[22], S[23]);
    A[53] = g1.creeArete(0, S[23], S[24]);

    A[54] = g1.creeArete(-3, S[3], S[7]);

    FenetreSFML<int, Vector2f> window;
    Pacman<int, Vector2f> pacman(*S[0], "Pacman", "pacmanRight");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                default:
                    break;
            }
        }
        window.clear();
        g1.dessine(window);
        pacman.dessine(&window);
        window.display();
    }
    return 0;
}
