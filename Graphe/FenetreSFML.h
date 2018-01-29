//
// Created by arnaud on 22/01/18.
//

#ifndef GRAPHES_FENETRESFML_H
#define GRAPHES_FENETRESFML_H

#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Graphe.h"

using namespace sf;

template<class S, class T>
class FenetreSFML:public RenderWindow
{
public:
    FenetreSFML<S, T>():RenderWindow(VideoMode(640, 720), "PacmanSFML"){}
    FenetreSFML<S, T>(FenetreSFML &f):RenderWindow(f){}
    bool dessine(Arete<S, T> *arete);
    bool dessine(Sommet<T> *sommet);

};

template<class S, class T>
bool FenetreSFML<S, T>::dessine(Arete<S, T> *arete)
{
    int x1 = 100+100*(arete->debut->clef / 5), y1 = 100+100*(arete->debut->clef % 5), x2 = 100+100*(arete->fin->clef / 5), y2 = 100+100*(arete->fin->clef % 5);
    RectangleShape A(Vector2f(20, sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))));
    A.setOutlineColor(Color::Cyan);
    A.setOutlineThickness(8);
    A.setFillColor(Color::Black);
    A.rotate(45*arete->v);
    if (arete->v == 0)
        A.setPosition(x1-10, y1);
    else if (arete->v == -3)
        A.setPosition(x1, y1+15);
    else if (arete->v == -2)
        A.setPosition(x1, y1+10);
    else if (arete->v == -1)
        A.setPosition(x1-15, y1);
    draw(A);
    return true;
}

template<class S, class T>
bool FenetreSFML<S, T>::dessine(Sommet<T> *sommet)
{
    CircleShape C(30, 100);
    //C.setPosition((100*(sommet->clef / 5))-C.getRadius()+100, 100*((sommet->clef % 5))-C.getRadius()+100);
    C.setPosition(sommet->v);
    C.setOutlineThickness(10);
    C.setOutlineColor(Color::Cyan);
    C.setFillColor(Color::Black);
    draw(C);
    return true;
}


#endif //GRAPHES_FENETRESFML_H
