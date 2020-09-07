#include "AppliChoixEdite.h"

AppliChoixEdite::AppliChoixEdite(sf::RenderWindow &window)
    : Application(window)
{
    m_window.setTitle("Choix Niveau Edité");

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

AppliChoixEdite::~AppliChoixEdite()
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

void AppliChoixEdite::draw(sf::RenderWindow &window)
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

void AppliChoixEdite::loop()
{
    //clear window
    m_window.clear(sf::Color(154,124,0));

    //Affichage
    draw(m_window);
    m_window.display();
}

void AppliChoixEdite::mouse_button_pressed()
{
    std::cout << m_mouse.x << " " << m_mouse.y << std::endl;
    int i = 0 ;
    //si souris dans un niveau, on lance le niveau
    for(auto a : m_niveaux)
    {
        i++;
        if(a.second->contient(m_mouse))
        {
            std::cout << a.first << std::endl;
            ChangementFenetre::allerEditeur(m_window,i);
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

void AppliChoixEdite::mouse_button_released()
{

}

void AppliChoixEdite::mouse_moved()
{

}

void AppliChoixEdite::key_pressed(const sf::Event::KeyEvent &event)
{
    if(event.code == sf::Keyboard::Q)
    {
        stop();
    }
}
