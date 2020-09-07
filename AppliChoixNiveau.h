#ifndef APPLICHOIXNIVEAU_H
#define APPLICHOIXNIVEAU_H
#include "Application.h"
#include "Bouton.h"
#include "Text.h"
#include <map>
#include "ChangementFenetre.h"
class AppliChoixNiveau : public Application
{
private:
    //map
    std::map<int, Bouton*> m_niveaux;
    std::map<std::string, Text*> m_texts;
    std::map<std::string, Bouton*> m_boutons;

    //elements graphiques
    sf::Sprite m_background;
    sf::Texture m_text_background;
    sf::Texture m_choix_texture;
    sf::Sprite m_choix_sprite;

    //int permettant de définir le nombre de niveaux
    int m_nb_niveaux;

    //booléen permettant de savoir si un fichier est edit
    bool est_fic_edit;

public:

    //constructeurs destructeurs
    AppliChoixNiveau(sf::RenderWindow &window,bool edit);
    ~AppliChoixNiveau();

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

#endif // APPLICHOIXNIVEAU_H
