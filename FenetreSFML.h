//
// Created by arnaud on 22/01/18.
//

#ifndef GRAPHES_FENETRESFML_H
#define GRAPHES_FENETRESFML_H

#include <math.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


template<class T, class S>
class FenetreSFML:public sf::RenderWindow
{
public:
    FenetreSFML():RenderWindow(sf::VideoMode(640, 720), "Graphe"){}
    bool dessine(Arete<T, S> *arete)
    {
        /*sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f((int)(100+100*(arete->debut->clef % 2)), (int)(100+100*(arete->debut->clef /2)))),
                        sf::Vertex(sf::Vector2f((int)(100+100*(arete->fin->clef % 2)), (int)(100+100*(arete->fin->clef /2))))
                };
        draw(line, 2, sf::Lines);*/
        int x1 = 100+100*(arete->debut->clef % 2), x2 = 100+100*(arete->debut->clef /2), y1 = 100+100*(arete->fin->clef % 2), y2 = 100+100*(arete->fin->clef /2);
        sf::RectangleShape A(sf::Vector2f(20, sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))));
        A.rotate(45*arete->v);
        A.setPosition(x1-25, y1-25);
        draw(A);
        cout << A.getPosition().x <<  " " <<A.getPosition().y << endl;
        return true;
    }

    bool dessine(Sommet<S> *sommet)
    {
        sf::CircleShape circle(25, 100);
        circle.setPosition((100*(sommet->clef / 2))-circle.getRadius()+100, 100*((sommet->clef % 2))-circle.getRadius()+100);
        draw(circle);
        return true;
    }
};


#endif //GRAPHES_FENETRESFML_H
