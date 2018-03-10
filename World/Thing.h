#ifndef PROJETSFML_Thing_GOM_H
#define PROJETSFML_Thing_GOM_H

#include "../Graphe/Sommet.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "../Screen/FenetreSFML.h"
#include "../Screen/FenetreGrapheSFML.h"
#include "../Screen/TransfoAffine2D.h"

using namespace std;

class Thing
{
public:
    Sommet<VSommet> *position;
private:
    int etat;
    string nom, image;
public:
    Sommet<VSommet>* getPosition () const;

    virtual void setPosition (Sommet<VSommet> *position);
public:
    explicit Thing(Sommet<VSommet> *position, string image, string nom, int etat=1);
    Thing(Thing &p);
    virtual ~Thing ();

    inline void setEtat(bool etat);
    inline int getEtat() const;
    string getNom () const;
    void setNom (const string &nom);
    const string &getImage () const;
    void setImage (const string &sprite);

    virtual const void dessine (FenetreGrapheSFML &window) = 0;
};


Thing::Thing(Thing &p):position(p.position), image(p.image), nom(p.nom), etat(p.etat){}


Thing::Thing(Sommet<VSommet> *position, string image, string nom, int etat):position(position), image(image), nom(nom), etat(etat){}


Thing::~Thing(){};


inline void Thing::setEtat(bool etat)
{
    Thing::etat = etat;
}

void Thing::setNom(const string &nom)
{
    Thing::nom = nom;
}

inline int Thing::getEtat () const
{
    return etat;
}


inline string Thing::getNom () const
{
    return nom;
}


const string &Thing::getImage () const
{
    return image;
}


void Thing::setImage (const string &sprite)
{
    Thing::image = sprite;
}

/*
const void Thing::dessine (FenetreGrapheSFML &window)
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
}*/


Sommet<VSommet>* Thing::getPosition () const
{
    return position;
}


void Thing::setPosition (Sommet<VSommet> *position)
{
    this->position = position;
}

#endif //PROJETSFML_Thing_GOM_H