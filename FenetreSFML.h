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
        int x1 = 100+100*(arete->debut->clef / 5), y1 = 100+100*(arete->debut->clef % 5), x2 = 100+100*(arete->fin->clef / 5), y2 = 100+100*(arete->fin->clef % 5);
        sf::RectangleShape A(sf::Vector2f(22, sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))));
        A.setOutlineThickness(8);
        A.setOutlineColor(sf::Color::Cyan);
        A.setFillColor(sf::Color::Black);
        A.rotate(45*arete->v);
        if (arete->v == 0)
            A.setPosition(x1-15, y1);
        else if (arete->v == -3)
            A.setPosition(x1, y1+15);
        else if (arete->v == -2)
            A.setPosition(x1, y1+15);
        else if (arete->v == -1)
            A.setPosition(x1-15, y1);
        draw(A);
        return true;
    }

    bool dessine(Sommet<S> *sommet)
    {
        sf::CircleShape C(30, 100);
        C.setPosition((100*(sommet->clef / 5))-C.getRadius()+100, 100*((sommet->clef % 5))-C.getRadius()+100);
        C.setOutlineThickness(10);
        C.setOutlineColor(sf::Color::Cyan);
        C.setFillColor(sf::Color::Black);
        draw(C);
        return true;
    }
};


#endif //GRAPHES_FENETRESFML_H
