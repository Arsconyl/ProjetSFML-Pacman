#ifndef PROJETSFML_Thing_GOM_H
#define PROJETSFML_Thing_GOM_H

#include "../Graphe/Sommet.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "../Screen/FenetreSFML.h"
#include "../Screen/FenetreGrapheSFML.h"
#include "../Screen/TransfoAffine2D.h"

using namespace std;

template<class S, class T>
class Thing
{
private:
    Sommet<T> *position;
    int etat;
    string nom, image;
public:
    Sommet<T>* getPosition () const;
    void setPosition (Sommet<T> *position);
public:
    explicit Thing<S, T>(Sommet<T> *position, string image, string nom, int etat=1);
    Thing<S, T>(Thing<S, T> &p);
    virtual ~Thing<S, T> ();

    inline void toggleEtat();
    inline int getEtat() const;
    string getNom () const;
    void setNom (const string &nom);
    const string &getImage () const;
    void setImage (const string &sprite);

    const void dessine (FenetreGrapheSFML &window);
};

template<class S, class T>
Thing<S, T>::Thing(Thing<S, T> &p):position(p.position), image(p.image), nom(p.nom), etat(p.etat){}

template<class S, class T>
Thing<S, T>::Thing(Sommet<T> *position, string image, string nom, int etat):position(position), image(image), nom(nom), etat(etat){}

template<class S, class T>
Thing<S, T>::~Thing<S, T>(){};

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
const void Thing<S, T>::dessine (FenetreGrapheSFML &window)
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
    sprite.setPosition(vecteur2DToVector2f(window.t.applique(position->v.getPosition()) - 10 * Vecteur2D(1, 1)));
    window.fenetre.draw(sprite);
}

template<class S, class T>
Sommet<T>* Thing<S, T>::getPosition () const
{
    return position;
}

template<class S, class T>
void Thing<S, T>::setPosition (Sommet<T> *position)
{
    this->position = position;
}

#endif //PROJETSFML_Thing<S, T>_GOM_H