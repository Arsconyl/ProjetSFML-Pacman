
#include <iostream>
#include "Graphe/Graphe.h"
#include "Persos/Pacman.h"
#include "Persos/Fantome.h"
#include "Persos/deplacement.h"
#include "Partie.h"

using namespace std;
using namespace sf;


int main()
{
    /*
    srand(static_cast<unsigned int>(time(NULL)));
    board B;
    Vecteur2D coinBG(-1, -1);
    Vecteur2D coinHD(5, 5);

    float deltatime;
    Clock clock;

    sf::Font font;
    if (!font.loadFromFile("abaddon.ttf"))
    {
        // erreur...
    }

    FenetreGrapheSFML window("PacmanSFML !", coinBG, coinHD, 1280, 720);

    Text score;
    score.setFont(font);
    score.setString("Score");
    score.setCharacterSize(18);
    score.setFillColor(Color::White);
    score.setPosition(vecteur2DToVector2f(window.t.applique(Vecteur2D(1.5, -0.75))));

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

    /*while (window.fenetre.isOpen())
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
        window.fenetre.draw(score);
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
     */
    Vecteur2D coinBG(-1, -1);
    Vecteur2D coinHD(5, 5);
    board B;
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

    Pacman pacman(B.sommets[0], "Pacman", "pacmanRight", &texturesPacman, Vector2u(3, 8), 0.125f,
                  100.0, window.t, 1);
    Fantome fantome1(B.sommets[24], "ghost1", "ghost1", &texturesFantome1, Vector2u(3, 8), 0.125f,
                     100.0, window.t, 1),
            fantome2(B.sommets[23], "ghost2", "ghost2", &texturesFantome2, Vector2u(3, 8), 0.125f, 100.0, window.t, 1),
            fantome3(B.sommets[22], "ghost3", "ghost3", &texturesFantome3, Vector2u(3, 8), 0.125f, 100.0, window.t, 1);

    vector<Fantome*> fantomes;
    fantomes.push_back(&fantome1);
    fantomes.push_back(&fantome2);
    fantomes.push_back(&fantome3);

    Partie p = Partie::Instance();
    p.lancerPartie(window, pacman, fantomes, B);

    return 0;





}
