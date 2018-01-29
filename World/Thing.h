#ifndef PROJETSFML_Thing_GOM_H
#define PROJETSFML_Thing_GOM_H

#include "../Graphe/Sommet.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "../Graphe/FenetreSFML.h"

using namespace std;

template<class S, class T>
class Thing
{
private:
    Sommet<T> position;
    int etat;
public:
    const Sommet<T> &getPosition () const;

    void setPosition (const Sommet<T> &position);

private:
    string nom, image;
public:
    Thing<S, T>(Sommet<T> position, string image, string nom, int etat=1);
    Thing<S, T>(Thing<S, T> &p);
    virtual ~Thing<S, T> ();

    inline void toggleEtat();
    inline int getEtat() const;
    string getNom () const;
    void setNom (const string &nom);
    const string &getImage () const;
    void setImage (const string &sprite);

    const void dessine(FenetreSFML<S, T> *window);
};

template<class S, class T>
Thing<S, T>::Thing(Thing<S, T> &p):position(p.position), image(p.image), nom(p.nom), etat(p.etat){}

template<class S, class T>
Thing<S, T>::Thing(Sommet<T> position, string image, string nom, int etat):position(position), image(image), nom(nom), etat(etat){}

template<class S, class T>
Thing<S, T>::~Thing<S, T>(){}

template<class S, class T>
inline void Thing<S, T>::toggleEtat()
{
    etat = !etat;
}
template<class S, class T>
void Thing<S, T>::setNom(const string &nom)
{
    Thing<S, T>::nom = nom;
}
template<class S, class T>
inline int Thing<S, T>::getEtat () const
{
    return etat;
}

template<class S, class T>
inline string Thing<S, T>::getNom () const
{
    return nom;
}

template<class S, class T>
const string &Thing<S, T>::getImage () const
{
    return image;
}

template<class S, class T>
void Thing<S, T>::setImage (const string &sprite)
{
    Thing<S, T>::image = sprite;
}

template<class S, class T>
const void Thing<S, T>::dessine (FenetreSFML<S, T> *window)
{
    sf::Image img;
    img.loadFromFile("images/" + image + ".png");
    img.createMaskFromColor(Color::Black);
    sf::Texture texture;
    if (!texture.loadFromImage(img))
    {
        Erreur("Chargement" + image);
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(position.v);
    sprite.setPosition(getPosition().v+Vector2f(15,15));
    window->draw(sprite);
}

template<class S, class T>
const Sommet<T> &Thing<S, T>::getPosition () const
{
    return position;
}

template<class S, class T>
void Thing<S, T>::setPosition (const Sommet<T> &position)
{
    Thing::position = position;
}

#endif //PROJETSFML_Thing<S, T>_GOM_H