#ifndef BOUTON_H
#define BOUTON_H
#include <SFML/Graphics.hpp>

using Position = sf::Vector2f;

class Bouton
{
private:
    //elements graphiques
    sf::RectangleShape m_rect;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

public:
    //constructeurs destructeurs
    Bouton(int x, int y, float w, float h, std::string fichier);

    //getters
    sf::Sprite getSprite();

    //fonction permettant de savoir si la souris (entre autre) est dans le bouton
    bool contient(Position p);

    //fonction d'affichage
    void afficher(sf::RenderWindow &window);
    void changer_sprite(std::string nouveau);
    ~Bouton();
};

#endif // BOUTON_H
