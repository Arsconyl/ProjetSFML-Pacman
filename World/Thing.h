#ifndef PROJETSFML_Thing_GOM_H
#define PROJETSFML_Thing_GOM_H

#include "../Graphe/Sommet.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "../Screen/FenetreSFML.h"

using namespace std;

template<class S, class T>
class Thing
{
private:
    Sommet<T> *positionS;
    int etat, positionNum;
    string nom, image;
public:
    Sommet<T>* getPositionS () const;
    void setPositionS (Sommet<T> *positionS);
    const int getPositionNum () const;
    void setPositionNum (const int &positionNum);
public:
    Thing<S, T>(Sommet<T> *position, int positionNum, string image, string nom, int etat=1);
    Thing<S, T>(Thing<S, T> &p);
    virtual ~Thing<S, T> ();

    inline void toggleEtat();
    inline int getEtat() const;
    string getNom () const;
    void setNom (const string &nom);
    const string &getImage () const;
    void setImage (const string &sprite);

    const void dessine(FenetreSFML<S, T> &window);
};

template<class S, class T>
Thing<S, T>::Thing(Thing<S, T> &p):positionS(p.positionS), positionNum(p.positionNum), image(p.image), nom(p.nom), etat(p.etat){}

template<class S, class T>
Thing<S, T>::Thing(Sommet<T> *positionS, int positionNum, string image, string nom, int etat):positionS(positionS), positionNum(positionNum), image(image), nom(nom), etat(etat){}

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
const void Thing<S, T>::dessine (FenetreSFML<S, T> &window)
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
    sprite.setPosition(positionS->v);
    sprite.setPosition(getPositionS()->v+Vector2f(20,20));
    window.draw(sprite);
}

template<class S, class T>
Sommet<T>* Thing<S, T>::getPositionS () const
{
    return positionS;
}

template<class S, class T>
void Thing<S, T>::setPositionS (Sommet<T> *positionS)
{
    this->positionS = positionS;
}

template<class S, class T>
const int Thing<S, T>::getPositionNum () const
{
    return positionNum;
}

template<class S, class T>
void Thing<S, T>::setPositionNum (const int &positionNum)
{
    this->positionNum = positionNum;
}

#endif //PROJETSFML_Thing<S, T>_GOM_H