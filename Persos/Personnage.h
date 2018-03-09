//
// Created by arnaud on 24/01/18.
//

#ifndef GRAPHES_PERSONNAGE_H
#define GRAPHES_PERSONNAGE_H

#include "../Graphe/Sommet.h"
#include "../World/Thing.h"
#include <string>

using namespace std;

template<class S, class T>
class Personnage : public Thing<S, T>
{
private:
    RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    Vector2f movement;
    Texture *texture;
public:
    explicit Personnage<S, T> (Sommet<T> *position, string image, string nom, Texture *texture, Vector2u imageCount,
                               float switchTime, float speed, TransfoAffine2D &t, int etat = 1);
    Personnage<S, T>(Personnage &p);
    virtual ~Personnage ();

    void Update (float deltaTime);

    virtual const void dessine (FenetreGrapheSFML &window);

    Texture *getTexture () const;

    virtual void setPosition (Sommet<T> *position, TransfoAffine2D t);
};
template<class S, class T>
Personnage<S, T>::Personnage (Personnage<S, T> &p):Thing<S, T>(p), animation(p.animation)
{};

template<class S, class T>
Personnage<S, T>::Personnage (Sommet<T> *position, string nom, string image, Texture *texture, Vector2u imageCount,
                              float switchTime, float speed, TransfoAffine2D &t, int etat):
        Thing<S, T>(position, image, nom, etat), animation(texture, imageCount, switchTime), speed(speed), row(0)
{
    this->getPosition()->v.setGom(false);
    body.setSize(Vector2f(64.0f, 64.0f));
    body.setPosition(vecteur2DToVector2f(t.applique(this->getPosition()->v.getPosition()) - Vecteur2D(32, 32)));
    //t = Texture();
    //if(!t.loadFromFile("imgpacman/Textures.png")) throw ("Erreur lors du chargement des textures.");
    body.setTexture(texture);
}
template<class S, class T>
Personnage<S, T>::~Personnage(){};

template<class S, class T>
void Personnage<S, T>::Update (float deltaTime)
{
    movement.x = 0.0f;
    movement.y = 0.0f;
    if (Keyboard::isKeyPressed(Keyboard::Numpad4)) //Left
    {
        movement.x -= speed * deltaTime;
        movement.y = 0.0f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad6)) //Right
    {
        movement.x += speed * deltaTime;
        movement.y = 0.0f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad8)) //Up
    {
        movement.y -= speed * deltaTime;
        movement.x = 0.0f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad2)) //Down
    {
        movement.y += speed * deltaTime;
        movement.x = 0.0f;
    }


    if (Keyboard::isKeyPressed(Keyboard::Numpad7)) //UpLeft
    {
        movement.x -= speed * deltaTime;
        movement.y -= speed * deltaTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad9)) //DownRight
    {
        movement.x += speed * deltaTime;
        movement.y -= speed * deltaTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad1)) //UpLeft
    {
        movement.x -= speed * deltaTime;
        movement.y += speed * deltaTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad3)) //UpRight
    {
        movement.x += speed * deltaTime;
        movement.y += speed * deltaTime;
    }

    if (movement.x < 0)
    {
        if (movement.y < 0)         //UpLeft
        {
            row = 7;
        } else if (movement.y > 0)    //DownLeft
        {
            row = 6;
        } else                        //Left
        {
            row = 3;
        }
    } else if (movement.x > 0)
    {
        if (movement.y < 0)         //UpRight
        {
            row = 4;
        } else if (movement.y > 0)    //DownRight
        {
            row = 5;
        } else                        //Right
        {
            row = 1;
        }
    } else // movement.x = 0
    {
        if (movement.y < 0)         //Down
        {
            row = 0;
        } else if (movement.y > 0)    //Up
        {
            row = 2;
        } else                        //Immobile
        {

        }


    }
    animation.Update(row, deltaTime);
    body.setTextureRect(animation._textureRect);
    //body.move(movement.x, movement.y);

}

template<class S, class T>
const void Personnage<S, T>::dessine (FenetreGrapheSFML &window)
{
    window.fenetre.draw(body);
}

template<class S, class T>
Texture *Personnage<S, T>::getTexture () const
{
    return texture;
}

template<class S, class T>
void Personnage<S, T>::setPosition (Sommet<T> *position, TransfoAffine2D t)
{
    Thing<S, T>::setPosition(position);
    body.setPosition(vecteur2DToVector2f(t.applique(this->getPosition()->v.getPosition()) - Vecteur2D(32, 32)));
}


#endif //GRAPHES_PERSONNAGE_H