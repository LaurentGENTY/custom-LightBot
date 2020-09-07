#include "AppliTransition.h"
#include <iostream>
#include "ChangementFenetre.h"

AppliTransition::AppliTransition(sf::RenderWindow &window)
    : Application(window)
{
    m_window.setTitle("Transition");

    if(!m_text_background.loadFromFile("data/background.png"))
    {
        std::cout << "Pas trouvé" << std::endl;
    }
    m_text_background.loadFromFile("data/background.png");
    m_background.setTexture(m_text_background);
    m_background.setPosition(0,0);
    m_background.setScale({1.,1.});

    if(!m_choix_texture.loadFromFile("data/transition.png"))
    {
        std::cout << "Pas trouvé" << std::endl;
    }

    m_choix_texture.loadFromFile("data/transition.png");
    m_choix_sprite.setTexture(m_choix_texture);
    m_choix_sprite.setPosition({500,400});
    m_choix_sprite.setScale({1.,1.});

    m_boutons["normaux"] = new Bouton(200,700,250.,100.,"data/normaux.png");
    m_boutons["edit"] = new Bouton(700,700,250.,100.,"data/edit.png");
    m_boutons["fin"] = new Bouton(1100,900,50.,50.,"data/fin.png");
    m_boutons["retour"] = new Bouton(1000,25,50.,50.,"data/retourchoix.png");


}

AppliTransition::~AppliTransition()
{
    for(auto a : m_boutons)
    {
        delete a.second;
    }
}

void AppliTransition::draw(sf::RenderWindow &window)
{
    window.clear(sf::Color(0,0,0));

    window.draw(m_background);
    window.draw(m_choix_sprite);

    for(auto a : m_boutons)
    {
        a.second->afficher(window);
    }

}

void AppliTransition::loop()
{
    m_window.clear(sf::Color(154,124,0));

    draw(m_window);

    m_window.display();
}

void AppliTransition::mouse_button_pressed()
{
    if(m_boutons.at("retour")->contient(m_mouse))
    {
        std::cout << "RETOUR MENU" << std::endl;
        stop();
        ChangementFenetre::allerMenu(m_window);
    }
    else if(m_boutons.at("normaux")->contient(m_mouse))
    {
        std::cout << "Souris dans Jouer" << std::endl;
        stop();
        ChangementFenetre::allerChoixNiveau(m_window,false);
    }
    else if(m_boutons.at("fin")->contient(m_mouse))
    {
        stop();
    }
    else if(m_boutons.at("edit")->contient(m_mouse))
    {
        std::cout << "EDITEUR" << std::endl;
        stop();
        ChangementFenetre::allerChoixNiveau(m_window,true);
    }
}

void AppliTransition::mouse_button_released()
{

}

void AppliTransition::mouse_moved()
{

}

void AppliTransition::key_pressed(const sf::Event::KeyEvent &event)
{

}
