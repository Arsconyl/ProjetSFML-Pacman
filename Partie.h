//
// Created by alex on 10/03/18.
//

#ifndef PROJETSFML_PACMAN_PARTIE_H
#define PROJETSFML_PACMAN_PARTIE_H


#include <cstdlib>
#include "World/board.h"
#include "Screen/FenetreGrapheSFML.h"
#include "Persos/Pacman.h"
#include "Persos/Fantome.h"

class Partie {
public:
    ~Partie();
    static Partie& Instance();
    void lancerPartie(FenetreGrapheSFML &window, Pacman & pacman, vector<Fantome*> fantomes, board &B);
    void niveau1(Pacman &pacman,vector<Fantome*> fantomes,board &b, FenetreGrapheSFML &window);
    void niveau2(Pacman &pacman,vector<Fantome*> fantomes,board &b, FenetreGrapheSFML &window);
    void niveau3(Pacman &pacman,vector<Fantome*> fantomes,board &b, FenetreGrapheSFML &window);
    void gestionLevel(Pacman &pacman,vector<Fantome*> fantomes, board &B, FenetreGrapheSFML &window);

private:
    Partie();
    int score;
    int level;
   /* static Vecteur2D coinBG, coinHD;
    static board B;

    static Pacman<VArete, VSommet>  pacman;
    static Fantome<VArete, VSommet> fantome1;
    static Fantome<VArete, VSommet> fantome2;
    static Fantome<VArete, VSommet> fantome3;
    static Texture texturesPacman;
    static Texture texturesFantome1;
    static Texture texturesFantome2;
    static Texture texturesFantome3;
    */
   //static FenetreGrapheSFML window;
};


#endif //PROJETSFML_PACMAN_PARTIE_H
