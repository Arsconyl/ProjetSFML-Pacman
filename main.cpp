﻿
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

    Pacman pacman(B.sommets[0], "Pacman", "pacmanRight", &texturesPacman, Vector2u(3, 8), 0.125f, 100.0, window.t, 1);
    vector<Fantome*> fantomes;

    fantomes.push_back(new Fantome(B.sommets[24], "ghost1", "ghost1", &texturesFantome1, Vector2u(3, 8), 0.125f, 100.0, window.t, 1));
    fantomes.push_back(new Fantome(B.sommets[23], "ghost2", "ghost2", &texturesFantome2, Vector2u(3, 8), 0.125f, 100.0, window.t, 1));
    fantomes.push_back(new Fantome(B.sommets[22], "ghost3", "ghost3", &texturesFantome3, Vector2u(3, 8), 0.125f, 100.0, window.t, 1));

    /*fantomes.push_back(&fantome1);
    fantomes.push_back(&fantome2);
    fantomes.push_back(&fantome3);*/

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
            deplacement::gestionPartie(pacman, fantomes, B, window.t, deplacement::gestionDeplacementFantomeLvl2);
            if(!pacman.getEtat())
                window.fenetre.close();
        }
        window.fenetre.clear();
        B.graphe.dessine(window);
        fantomes[0]->Update(deltatime);
        fantomes[0]->dessine(window);
        fantomes[1]->Update(deltatime);
        fantomes[1]->dessine(window);
        fantomes[2]->Update(deltatime);
        fantomes[2]->dessine(window);
        pacman.Update(deltatime);
        pacman.dessine(window);
        window.fenetre.display();
    }
    return 0;
}
