
#include <iostream>
#include "Graphe/Graphe.h"
#include "Persos/Pacman.h"
#include "Persos/Fantome.h"
#include "Persos/deplacement.h"

using namespace std;
using namespace sf;
int main()
{
    board B;
    Vecteur2D coinBG(-1, -1);
    Vecteur2D coinHD(5, 5);

    FenetreGrapheSFML window("PacmanSFML !", coinBG, coinHD, 1280, 720);
    Pacman<VArete, VSommet> pacman(B.sommets[0], "Pacman", "pacmanRight", 1);
    Fantome<VArete, VSommet> fantome1(B.sommets[24], "ghost1", "ghost1", 1),
            fantome2(B.sommets[23], "ghost2", "ghost2", 1),
            fantome3(B.sommets[22], "ghost3", "ghost3", 1);
    while (window.fenetre.isOpen())
    {
        sf::Event event{};
        while (window.fenetre.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.fenetre.close();
                    break;
                }
                default:
                    break;
            }
            if (deplacement::gestionDeplacementPacman(pacman, fantome1, B))
            if(pacman.getPosition() == fantome1.getPosition())
                window.fenetre.close();
        }
        window.fenetre.clear();
        B.graphe.dessine(window);
        fantome1.dessine(window);
        //fantome2.dessine(window);
        //fantome3.dessine(window);
        //fantome4.dessine(window);
        pacman.dessine(window);
        window.fenetre.display();
    }
    return 0;
}
