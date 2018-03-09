
#include <iostream>
#include "Graphe/Graphe.h"
#include "Persos/Pacman.h"
#include "Persos/Fantome.h"
#include "Persos/deplacement.h"

using namespace std;
using namespace sf;
int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    board B;
    Vecteur2D coinBG(-1, -1);
    Vecteur2D coinHD(5, 5);

    float deltatime;
    Clock clock;

    FenetreGrapheSFML window("PacmanSFML !", coinBG, coinHD, 1280, 720);

    Texture texturesPacman = Texture(), texturesFantome1 = Texture(), texturesFantome2 = Texture(), texturesFantome3 = Texture();
    if (!texturesPacman.loadFromFile("imgpacman/TexturesPacman.png"))
        throw ("Erreur lors du chargement des textures.");
    if (!texturesFantome1.loadFromFile("imgpacman/Ghost-B.png"))
        throw ("Erreur lors du chargement des textures.");
    if (!texturesFantome2.loadFromFile("imgpacman/Ghost-R.png"))
        throw ("Erreur lors du chargement des textures.");
    if (!texturesFantome3.loadFromFile("imgpacman/Ghost-Y.png"))
        throw ("Erreur lors du chargement des textures.");

    Pacman<VArete, VSommet> pacman(B.sommets[0], "Pacman", "pacmanRight", &texturesPacman, Vector2u(3, 8), 0.125f,
                                   100.0, window.t, 1);
    Fantome<VArete, VSommet> fantome1(B.sommets[24], "ghost1", "ghost1", &texturesFantome1, Vector2u(3, 8), 0.125f,
                                      100.0, window.t, 1),
            fantome2(B.sommets[23], "ghost2", "ghost2", &texturesFantome2, Vector2u(3, 8), 0.125f, 100.0, window.t, 1),
            fantome3(B.sommets[22], "ghost3", "ghost3", &texturesFantome3, Vector2u(3, 8), 0.125f, 100.0, window.t, 1);
    while (window.fenetre.isOpen())
    {
        sf::Event event{};
        deltatime = clock.restart().asSeconds();
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
            deplacement::gestionDeplacementPacman(pacman, fantome1, B, window.t);
            if(!pacman.getEtat())
                window.fenetre.close();
        }
        window.fenetre.clear();
        B.graphe.dessine(window);
        fantome1.Update(deltatime);
        fantome1.dessine(window);
        //fantome2.dessine(window);
        //fantome3.dessine(window);
        //fantome4.dessine(window);
        pacman.Update(deltatime);
        pacman.dessine(window);
        window.fenetre.display();
    }
    return 0;
}
