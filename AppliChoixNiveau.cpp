#include "AppliChoixNiveau.h"
#include <iostream>
#include "Text.h"

namespace {
constexpr float RAYON = 20.0;
constexpr int W = 1200, H = 1000;
const std::string POLICE = "police.ttf";
}

AppliChoixNiveau::AppliChoixNiveau(sf::RenderWindow &window, bool edit)
    : Application(window)
    ,est_fic_edit{edit}
{
    m_window.setTitle("Choix Niveau");

    //init sprites
    if(!m_text_background.loadFromFile("data/background.png"))
    {
        std::cout << "Pas trouvé" << std::endl;
    }

    m_text_background.loadFromFile("data/background.png");
    m_background.setTexture(m_text_background);
    m_background.setPosition(0,0);
    m_background.setScale({1.,1.});

    if(!m_choix_texture.loadFromFile("data/choixLevel.png"))
    {
        std::cout << "Pas trouvé" << std::endl;
    }
    m_choix_texture.loadFromFile("data/choixLevel.png");
    m_choix_sprite.setTexture(m_choix_texture);
    m_choix_sprite.setPosition({475,200});
    m_choix_sprite.setScale({1.,1.});

    m_nb_niveaux = 5;

    unsigned int x = 150;
    unsigned int y = 400;

    //init de la liste des niveaux
    for(int i=0; i<m_nb_niveaux;i++)
    {
        m_niveaux[i] = new Bouton(x,y,100,100,"data/"+(std::to_string(i)+".png"));
        x+= 200;

        if(x > m_window.getSize().x - 100)
        {
            x = 300;
            y+= 200;
        }
    }

    //init boutons
    m_boutons["fin"] = new Bouton(1100,900,50.,50.,"data/fin.png");
    m_boutons["retour"] = new Bouton(1000,25,50.,50.,"data/retourchoix.png");


}

AppliChoixNiveau::~AppliChoixNiveau()
{
    //Delete niveaux
    for(auto a : m_niveaux)
    {
        delete a.second;
    }

    //delete des textes
    for(auto a : m_texts)
    {
        delete a.second;
    }

    //deletes des boutons
    for(auto a : m_boutons)
    {
        delete a.second;
    }
}


void AppliChoixNiveau::draw(sf::RenderWindow &window)
{
    //affichage des sprites
    window.draw(m_background);
    window.draw(m_choix_sprite);

    //affichages des niveaux
    for(auto a : m_niveaux)
    {
        m_window.draw(a.second->getSprite());
    }

    //affichages des boutons
    for(auto a : m_boutons)
    {
        a.second->afficher(window);
    }
}

void AppliChoixNiveau::loop()
{
    //clear window
    m_window.clear(sf::Color(154,124,0));

    //Affichage
    draw(m_window);
    m_window.display();
}

void AppliChoixNiveau::mouse_button_pressed()
{
    std::cout << m_mouse.x << " " << m_mouse.y << std::endl;

    //si souris dans un niveau, on lance le niveau
    for(auto a : m_niveaux)
    {
        if(a.second->contient(m_mouse))
        {
            std::cout << a.first << std::endl;
            ChangementFenetre::allerJeu(m_window,a.first,est_fic_edit);
        }
    }

    //si souris dans retour
    if(m_boutons.at("retour")->contient(m_mouse))
    {
        std::cout << "RETOUR MENU" << std::endl;
        stop();
        ChangementFenetre::allerTransition(m_window);
    }

    //si souris dans fin
    if(m_boutons.at("fin")->contient(m_mouse))
    {
        stop();
    }
}



void AppliChoixNiveau::mouse_button_released()
{

}

void AppliChoixNiveau::mouse_moved()
{

}

void AppliChoixNiveau::key_pressed(const sf::Event::KeyEvent &event)
{
    if(event.code == sf::Keyboard::Q)
    {
        stop();
    }
}
