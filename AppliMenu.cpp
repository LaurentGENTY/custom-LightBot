#include "AppliMenu.h"
#include "Bouton.h"
#include <iostream>
#include "ChangementFenetre.h"

namespace {
    constexpr float RAYON = 20.0;
    constexpr int W = 1200, H = 1000;
    const std::string POLICE = "police.ttf";
}

AppliMenu::AppliMenu(sf::RenderWindow &window)
    : Application(window)
{
    //init sprites
    if(!m_text_background.loadFromFile("data/background.png"))
    {
        std::cout << "Pas trouve" << std::endl;
    }
    m_text_background.loadFromFile("data/background.png");
    m_background.setTexture(m_text_background);
    m_background.setPosition(0,0);
    m_background.setScale({1.,1.});

    //init boutons
    m_boutons["jouer"] = new Bouton(100,700,400.,200.,"data/jouer.png");
    m_boutons["fin"] = new Bouton(1100,900,50.,50.,"data/fin.png");
    m_boutons["editeur"] = new Bouton(600,700,400.,200.,"data/editeur.png");
    m_boutons["titre"] = new Bouton(400,400,400.,200.,"data/lightbot.png");

}

AppliMenu::~AppliMenu()
{
    //Delete boutons
    for(auto a : m_boutons)
    {
        delete a.second;
    }
}

void AppliMenu::draw(sf::RenderWindow &window)
{
    //affichage des sprites
    window.clear(sf::Color(0,0,0));
    window.draw(m_background);

    //affichages des boutons
    for(auto a : m_boutons)
    {
        a.second->afficher(window);
    }

    //affichages des textes
    for(auto a : m_texts)
    {
        m_window.draw(a.second->text());
    }
}

void AppliMenu::loop()
{
    //clear window
    m_window.clear(sf::Color(154,124,0));

    //Affichage
    draw(m_window);
    m_window.display();

}

void AppliMenu::mouse_button_pressed()
{
    std::cout << m_mouse.x << " " << m_mouse.y << std::endl;

    //si souris dans jouer
    if(m_boutons.at("jouer")->contient(m_mouse))
    {
        std::cout << "Souris dans Jouer" << std::endl;
        ChangementFenetre::allerTransition(m_window);
    }

    //si souris dans fin
    else if(m_boutons.at("fin")->contient(m_mouse))
    {
        stop();
    }

    //si souris dans editeur
    else if(m_boutons.at("editeur")->contient(m_mouse))
    {
        std::cout << "EDITEUR" << std::endl;
        ChangementFenetre::allerChoixEdit(m_window);
    }
}



void AppliMenu::mouse_button_released()
{

}

void AppliMenu::mouse_moved()
{

}

void AppliMenu::key_pressed(const sf::Event::KeyEvent &event)
{
    if(event.code == sf::Keyboard::Q)
    {
        stop();
    }
}
