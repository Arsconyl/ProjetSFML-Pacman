//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_PACMAN_H
#define GRAPHES_PACMAN_H

#include "Personnage.h"

template<class S, class T>
class Pacman : public Personnage<S, T>
{
public:
    explicit Pacman<S, T>(Sommet<T> *position, string image, string nom, int etat=1);
    Pacman<S, T>(Pacman &p);
    virtual ~Pacman ();

    void setPosition (Sommet<T> *position) override;

    //const void dessine (FenetreGrapheSFML &window) override;
};
template<class S, class T>
Pacman<S, T>::Pacman(Pacman<S, T> &p):Personnage<S, T>(p){}
template<class S, class T>
Pacman<S, T>::Pacman(Sommet<T> *position, string image, string nom, int etat):Personnage<S, T>(position, image, nom, etat){}
template<class S, class T>
Pacman<S, T>::~Pacman(){}

template<class S, class T>
void Pacman<S, T>::setPosition (Sommet<T> *position)
{
    Thing<S, T>::setPosition(position);
    this->getPosition()->v.setGom(false);
}

//template<class S, class T>
/*template<>
const void Pacman<VArete, VSommet>::dessine (FenetreGrapheSFML &window)
{
    Time time= milliseconds(100);
    Clock c;
    Texture t1;
    t1.loadFromFile("imgpacman/pacman-spritesheet.png");


    Sprite s[5];
    for (int i = 0; i < 5; i++)
    {
        s[i] = Sprite(t1);
        s[i].setTextureRect(IntRect(i*120,0,110,110));
        s[i].setPosition(vecteur2DToVector2f(window.t.applique(getPosition()->v.getPosition())));
    }

    //window.fenetre.clear(Color::Black);
    window.fenetre.draw(s[0]);
    window.fenetre.display();
    sleep(milliseconds(100));
    //window.fenetre.clear(Color::Black);
    window.fenetre.draw(s[1]);
    window.fenetre.display();
    sleep(milliseconds(100));
    //window.fenetre.clear(Color::Black);
    window.fenetre.draw(s[2]);
    window.fenetre.display();
    sleep(milliseconds(100));
    //window.fenetre.clear(Color::Black);
    window.fenetre.draw(s[3]);
    window.fenetre.display();
    sleep(milliseconds(100));
    //window.fenetre.clear(Color::Black);
    window.fenetre.draw(s[4]);
    window.fenetre.display();
    sleep(milliseconds(100));
}*/


#endif //GRAPHES_PACMAN_H
