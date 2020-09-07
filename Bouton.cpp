#include "Bouton.h"
#include <iostream>
Bouton::Bouton(int x, int y, float w, float h, std::string fichier)
{
    //init du rectangle (inutile)
    //EDIT : le rect servait a avoir une taille pour le sprite
    m_rect.setPosition(x,y);
    m_rect.setSize({w,h});

    //init sprites
    if(!m_texture.loadFromFile(fichier))
    {
        std::cout << "Pas trouve" << std::endl;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_rect.getPosition());
    m_sprite.setScale({1,1});

}

bool Bouton::contient(Position p)
{
    //si P est contenu dans les positions du rect alors renvoie true (on aurait pu remplacer
    //par getgloabalbounds du sprite
    if(p.x > m_rect.getPosition().x && p.x <= m_rect.getPosition().x+m_rect.getSize().x &&
            p.y > m_rect.getPosition().y && p.y <= m_rect.getPosition().y+m_rect.getSize().y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Bouton::afficher(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

void Bouton::changer_sprite(std::string nouveau)
{
    if(!m_texture.loadFromFile(nouveau))
    {
        std::cout << "Pas trouve" << std::endl;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_rect.getPosition());
    m_sprite.setScale({1,1});
}

Bouton::~Bouton()
{

}

sf::Sprite Bouton::getSprite()
{
    return m_sprite;
}
