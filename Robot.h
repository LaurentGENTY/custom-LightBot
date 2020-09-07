#ifndef ROBOT_H
#define ROBOT_H
#include <SFML/Graphics.hpp>
#include "Cases.h"

using Position = sf::Vector2f;
//Direction : 0 = NordEst
//1 = Est
//2 = SudEst
//3 = SudOuest
//4 =Ouest
//5 =NOrdOuest

class Robot
{
private:

    //tableau de cases
    std::array<std::array<Cases*,10>,10> &m_grille;

    //position
    Position m_position={0,0};

    //elements graphiques
    sf::Texture m_textureSE;
    sf::Texture m_textureSW;
    sf::Texture m_textureW;
    sf::Texture m_textureNW;
    sf::Texture m_textureNE;
    sf::Texture m_textureE;
    sf::Sprite m_sprite;

    //entier definissant sa direction
    int m_dir=0;
    int m_dir_initiale;

    //autres
    Position pos_tableau={0,0};
    bool m_est_etat_saut =false;

public:

    //constructeurs destructeurs
    Robot( std::array<std::array<Cases*,10>,10> & grille, int dir);
    ~Robot();

    //getters
    int getDirection();

    //setters
    void setDirection(int dir);
    void avancer();
    void tourner_droite();
    void tourner_gauche();
    void sauter(){m_est_etat_saut=true;}
    void allumer();
    void changerSprite();
    void reinitialiser();
    //affichage
    void afficher(sf::RenderWindow &window);

};

#endif // ROBOT_H
