#include "Action.h"
#include <iostream>

Action::Action(Etat etat, bool select)
    : m_etat{etat}
    , m_selec{select}
{
    //selon l'etat, on init un sprite différent
    switch(m_etat){
    case Etat::AVANCER:
        if(!m_texture.loadFromFile("data/avancer.png")){
            std::cout<< "Pas trouve" << std::endl;
        }
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(10,675);
        break;
    case Etat::INTERAGIR:
        if(!m_texture.loadFromFile("data/interagir.png")){
            std::cout<< "Pas trouve" << std::endl;
        }
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(70,675);
        break;
    case Etat::TOURNERDROITE:
        if(!m_texture.loadFromFile("data/tournerdroite.png")){
            std::cout<< "Pas trouve" << std::endl;
        }
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(130,675);
        break;
    case Etat::TOURNERGAUCHE:
        if(!m_texture.loadFromFile("data/tournergauche.png")){
            std::cout<< "Pas trouve" << std::endl;
        }
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(190,675);
        break;
    case Etat::SAUTER:
        if(!m_texture.loadFromFile("data/sauter.png")){
            std::cout<< "Pas trouve" << std::endl;
        }
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(250,675);
        break;
    case Etat::P1:
        if(!m_texture.loadFromFile("data/p1.png")){
            std::cout<< "Pas trouve" << std::endl;
        }
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(310,675);
        break;
    case Etat::P2:
        if(!m_texture.loadFromFile("data/p2.png")){
            std::cout<< "Pas trouve" << std::endl;
        }
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(370,675);
        break;
    }
}

Action::~Action()
{

}



void Action::afficher(sf::RenderWindow &window)
{
    //affichage du sprite
    window.draw(m_sprite);
}

std::string Action::action()
{
    //selon l'état, on renvoie une chaine de caractère correspondant à l'action
    switch(m_etat)
    {
    case Etat::AVANCER:
        return "AVANCER";
        break;
    case Etat::INTERAGIR:
        return "INTERAGIR";
        break;
    case Etat::TOURNERDROITE:
        return "TOURNERDROITE";
        break;
    case Etat::TOURNERGAUCHE:
        return "TOURNERGAUCHE";
        break;
    case Etat::SAUTER:
        return "SAUTER";
        break;
    case Etat::P1:
        return "P1";
        break;
    case Etat::P2:
        return "P2";
        break;
    }
    return "ERREUR";
}

Position Action::getPositionAction()
{
    //Retourne la position de l'action afin de pouvoir la placer
    return m_sprite.getPosition();
}

void Action::setSelect(bool valeur)
{
    //permet d'affecter telle ou telle action select
    m_selec = valeur;
}

sf::Sprite Action::getSprite()
{
    //retourne le sprite pour l'afficher
    return m_sprite;
}

bool Action::isSelect()
{
    //retourne la valeur de m_selec et permet de savoir si l'action est select
    return m_selec;
}


void Action::setSprite()
{
    //selon que l'aciton soit selectionnée ou pas
    if(m_selec)
    {
        //si elle est select, selon son etat on affiche un sprite en surbirllance différent
        switch(m_etat)
        {
        case Etat::AVANCER:
            m_texture.loadFromFile("data/avancerS.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::SAUTER:
            m_texture.loadFromFile("data/sauterS.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::TOURNERDROITE:
            m_texture.loadFromFile("data/tournerdroiteS.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::TOURNERGAUCHE:
            m_texture.loadFromFile("data/tournergaucheS.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::INTERAGIR:
            m_texture.loadFromFile("data/interagirS.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::P1:
            m_texture.loadFromFile("data/p1S.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::P2:
            m_texture.loadFromFile("data/p2S.png");
            m_sprite.setTexture(m_texture);
            break;
        }
    }
    //inverse
    if(!m_selec)
    {
        switch(m_etat)
        {
        case Etat::AVANCER:
            m_texture.loadFromFile("data/avancer.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::SAUTER:
            m_texture.loadFromFile("data/sauter.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::TOURNERDROITE:
            m_texture.loadFromFile("data/tournerdroite.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::TOURNERGAUCHE:
            m_texture.loadFromFile("data/tournergauche.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::INTERAGIR:
            m_texture.loadFromFile("data/interagir.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::P1:
            m_texture.loadFromFile("data/p1.png");
            m_sprite.setTexture(m_texture);
            break;
        case Etat::P2:
            m_texture.loadFromFile("data/p2.png");
            m_sprite.setTexture(m_texture);
            break;
        }
        m_sprite.setScale({1.,1.});
    }
}

bool Action::getSelect()
{
    //svoir si une action est select
    return m_selec;
}

void Action::positionSprite(Position p)
{
    //retourne la pos du sprite
    m_sprite.setPosition(p);
}

Etat Action::getEtatDeLaction()
{
    //permet de connaitre l'état de l'action
    return m_etat;
}
