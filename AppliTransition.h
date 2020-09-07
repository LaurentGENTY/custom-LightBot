#ifndef APPLITRANSITION_H
#define APPLITRANSITION_H
#include "Application.h"
#include "Bouton.h"

class AppliTransition : public Application
{
private:
    //map
    std::map<std::string, Bouton*> m_boutons;

    //elements graphiques
    sf::Sprite m_background;
    sf::Texture m_text_background;
    sf::Texture m_choix_texture;
    sf::Sprite m_choix_sprite;

    //int permettant de définir le nombre de niveaux
    int nb_niveaux;
public:

    //constructeurs destructeurs
    AppliTransition(sf::RenderWindow &window);
    ~AppliTransition();

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

#endif // APPLITRANSITION_H
