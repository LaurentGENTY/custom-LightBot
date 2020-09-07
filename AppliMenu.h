#ifndef APPLIMENU_H
#define APPLIMENU_H
#include "Application.h"
#include "Bouton.h"
#include "Text.h"

class AppliMenu : public Application
{
private:
    //map
    std::map<std::string, Bouton*> m_boutons;
    std::map<std::string, Text*> m_texts;

    //elements graphiques
    sf::Sprite m_background;
    sf::Texture m_text_background;

public:

    //constructeurs destructeurs
    AppliMenu(sf::RenderWindow &window);
    ~AppliMenu();

    //fonction d'affichage
    void draw(sf::RenderWindow &window);

    //boucle
    void loop() override;

    //evenements
    void mouse_button_pressed()                        override;
    void mouse_button_released()                       override;
    void mouse_moved()                                 override;
    void key_pressed(const sf::Event::KeyEvent &event) override;
};

#endif // APPLIMENU_H
