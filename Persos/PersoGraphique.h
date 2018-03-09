//
// Created by alex on 01/03/18.
//

#include <SFML/Graphics.hpp>
#include "Animation.h"

#ifndef TESTANIMATION_PERSOGRAPHIQUE_H
#define TESTANIMATION_PERSOGRAPHIQUE_H

#define LEFT 1
#define RIGHT 0
#define UP 2
#define DOWN 3
#define UPLEFT 4
#define UPRIGHT 5
#define DOWNLEFT 6
#define DOWNRIGHT 7

using namespace sf;
using namespace std;

class PersoGraphique
{

public:
    PersoGraphique (Texture *texture, Vector2u imageCount, float switchTime, float speed);

    void Update (float deltaTime);

    void draw (RenderWindow &window);

    Texture *getTexture () const;


private:

    RectangleShape body;
    Animation _animation;
    unsigned int _row;
    float _speed;
    Vector2f _movement;
    Texture *_texture;
};


#endif //TESTANIMATION_PERSOGRAPHIQUE_H
