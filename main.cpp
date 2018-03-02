
#include <iostream>
#include "Graphe/Graphe.h"
#include "Persos/Pacman.h"
#include "Persos/Fantome.h"
#include "World/board.h"
#include "Persos/deplacement.h"

using namespace std;
using namespace sf;
int main()
{
    board B;

    FenetreSFML<VArete, VSommet> window(700, 720, "PacmanSFML !");
    Pacman<VArete, VSommet> pacman(B.sommets[0], "Pacman", "pacmanRight", 1);
    Fantome<VArete, VSommet> fantome1(B.sommets[24], "ghost1", "ghost1", 1),
            fantome2(B.sommets[23], "ghost2", "ghost2", 1),
            fantome3(B.sommets[22], "ghost3", "ghost3", 1),
            fantome4(B.sommets[19], "ghost4", "ghost4", 1);

    while (window.isOpen())
    {
        sf::Event event{};
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
            if(deplacement::gestionDeplacementPacman(pacman , B))
                deplacement::gestionDeplacementFantomeLvl1(fantome1, B);
            if(pacman.getPosition() == fantome1.getPosition())
                window.close();
        }
        window.clear();
        B.graphe.dessine(window);
        fantome1.dessine(window);
        //fantome2.dessine(window);
        //fantome3.dessine(window);
        //fantome4.dessine(window);
        pacman.dessine(window);
        window.display();
    }
    return 0;
}
