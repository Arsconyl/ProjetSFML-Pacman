#include "../Fenetre/Sommet.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;


class Thing
{
private:
    Sommet position;
    bool etat;
    string nom;
    sf::Texture texture;
    void setTexture (const sf::Texture &texture);
public:
    Thing(Sommet position, bool etat, string nom, sf::Texture texture);
    Thing(Thing &p);
    virtual ~Thing ();

    inline void setPosition(Sommet &pos);
    inline void toggleEtat();
    inline Sommet getPosition() const;
    inline bool getEtat() const;
    string getNom () const;
    void setNom (const string &nom);
};

Thing::Thing(Thing &p):position(p.position), etat(p.etat), nom(p.nom){}

Thing::Thing(Sommet position, bool etat, string nom, sf::Texture texture):position(position), etat(etat), nom(nom), texture(texture){}
Thing::~Thing(){}
inline void Thing::setPosition(Sommet &pos)
{
    position = pos;
}
inline void Thing::toggleEtat()
{
    etat = !etat;
}

void Thing::setNom(const string &nom)
{
    Thing::nom = nom;
}

inline bool Thing::getEtat () const
{
    return etat;
}

inline Sommet Thing::getPosition () const
{
    return position;
}

inline string Thing::getNom () const
{
    return nom;
}