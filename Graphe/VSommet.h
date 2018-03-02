//
// Created by arnaud on 28/02/18.
//

#ifndef PROJETSFML_PACMAN_VSOMMET_H
#define PROJETSFML_PACMAN_VSOMMET_H


#include <SFML/System.hpp>
#include "InfoAStar.h"

class VSommet
{
private:
    bool Perso, Gom;
    InfoAStar infoAStar;
    sf::Vector2f position;
public:
    explicit VSommet (sf::Vector2f position, bool Perso = false, bool Gom = true, const InfoAStar &infoAStar = InfoAStar());
    virtual ~VSommet ();
    VSommet (const VSommet &vs);

    inline bool isPerso () const;
    inline void setPerso (bool Perso);
    inline bool isGom () const;
    inline void setGom (bool Gom);
    inline const InfoAStar &getInfoAStar () const;
    inline void setInfoAStar (const InfoAStar &infoAStar);
    inline const sf::Vector2f &getPosition () const;
    inline void setPosition (const sf::Vector2f &position);

};

VSommet::VSommet (sf::Vector2f position, bool Perso, bool Gom, const InfoAStar &infoAStar) : position(position), Perso(Perso), Gom(Gom), infoAStar(infoAStar)
{}

VSommet::~VSommet ()
= default;

VSommet::VSommet (const VSommet &vs) : position(vs.position), Perso(vs.Perso), Gom(vs.Gom), infoAStar(vs.infoAStar)
{}

inline bool VSommet::isPerso () const
{
    return Perso;
}

inline void VSommet::setPerso (bool Perso)
{
    VSommet::Perso = Perso;
}

inline bool VSommet::isGom () const
{
    return Gom;
}

inline void VSommet::setGom (bool Gom)
{
    VSommet::Gom = Gom;
}

inline const InfoAStar &VSommet::getInfoAStar () const
{
    return infoAStar;
}

inline void VSommet::setInfoAStar (const InfoAStar &infoAStar)
{
    VSommet::infoAStar = infoAStar;
}

inline const sf::Vector2f &VSommet::getPosition () const
{
    return position;
}

inline void VSommet::setPosition (const sf::Vector2f &position)
{
    VSommet::position = position;
}


#endif //PROJETSFML_PACMAN_VSOMMET_H
