//
// Created by alex on 01/03/18.
//

#include "PersoGraphique.h"


PersoGraphique::PersoGraphique (Texture *texture, Vector2u imageCount, float switchTime, float speed) :
        _animation(texture, imageCount, switchTime),
        _speed(speed),
        _row(0)
{
    body.setSize(Vector2f(64.0f, 64.0f));
    body.setPosition(200.0f, 200.0f);
    //t = Texture();
    //if(!t.loadFromFile("imgpacman/Textures.png")) throw ("Erreur lors du chargement des textures.");
    body.setTexture(texture);
}

void PersoGraphique::draw (RenderWindow &window)
{
    window.draw(body);
}

void PersoGraphique::Update (float deltaTime)
{
    _movement.x = 0.0f;
    _movement.y = 0.0f;
    if (Keyboard::isKeyPressed(Keyboard::Numpad4)) //Left
    {
        _movement.x -= _speed * deltaTime;
        _movement.y = 0.0f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad6)) //Right
    {
        _movement.x += _speed * deltaTime;
        _movement.y = 0.0f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad8)) //Up
    {
        _movement.y -= _speed * deltaTime;
        _movement.x = 0.0f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad2)) //Down
    {
        _movement.y += _speed * deltaTime;
        _movement.x = 0.0f;
    }


    if (Keyboard::isKeyPressed(Keyboard::Numpad7)) //UpLeft
    {
        _movement.x -= _speed * deltaTime;
        _movement.y -= _speed * deltaTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad9)) //DownRight
    {
        _movement.x += _speed * deltaTime;
        _movement.y -= _speed * deltaTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad1)) //UpLeft
    {
        _movement.x -= _speed * deltaTime;
        _movement.y += _speed * deltaTime;
    }

    if (Keyboard::isKeyPressed(Keyboard::Numpad3)) //UpRight
    {
        _movement.x += _speed * deltaTime;
        _movement.y += _speed * deltaTime;
    }

    if (_movement.x < 0)
    {
        if (_movement.y < 0)         //UpLeft
        {
            _row = 7;
        } else if (_movement.y > 0)    //DownLeft
        {
            _row = 6;
        } else                        //Left
        {
            _row = 3;
        }
    } else if (_movement.x > 0)
    {
        if (_movement.y < 0)         //UpRight
        {
            _row = 4;
        } else if (_movement.y > 0)    //DownRight
        {
            _row = 5;
        } else                        //Right
        {
            _row = 1;
        }
    } else // _movement.x = 0
    {
        if (_movement.y < 0)         //Down
        {
            _row = 0;
        } else if (_movement.y > 0)    //Up
        {
            _row = 2;
        } else                        //Immobile
        {

        }


    }
    _animation.Update(_row, deltaTime);
    body.setTextureRect(_animation._textureRect);
    //body.move(_movement.x, _movement.y);

}

Texture *PersoGraphique::getTexture () const
{
    return _texture;
}



