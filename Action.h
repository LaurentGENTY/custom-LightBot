#ifndef ACTION_H
#define ACTION_H
#include <SFML/Graphics.hpp>

using Position = sf::Vector2f;

enum class Etat { SAUTER, AVANCER, TOURNERGAUCHE, TOURNERDROITE, INTERAGIR, P1, P2 };

class Action
{
private:
    //elements graphiques
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    //booleen permettant de savoir si l'action est select
    bool m_selec;

    //etat de l'action permettant de savoir à quel type elle appartient
    Etat m_etat;
public:

    //constructeurs destructeurs
    Action(Etat etat,bool select);
    ~Action();

    //getters
    bool isSelect();
    bool getSelect();
    Position getPositionAction();
    std::string action();
    sf::Sprite getSprite();
    Etat getEtatDeLaction();

    //setters
    void setSelect(bool valeur);
    void setSprite();
    void positionSprite(Position p);

    //fonction d'affichage
    void afficher(sf::RenderWindow &window);
};

#endif // ACTION_H
