#ifndef APPLITABLEAU_H
#define APPLITABLEAU_H
#include "Application.h"
#include<Cases.h>
#include <array>
#include <vector>
#include <iostream>
#include "Conteneur.h"
#include "ChangementFenetre.h"
#include "Action.h"
#include "Niveau.h"

class AppliTableau : public Application
{
private:
    //map
    std::map<std::string, Text*> m_texts;
    std::map<std::string, Bouton*> m_boutons;

    //tableau de cases
    std::array<std::array<Cases*,10>,10> m_grille;

    //sprites
    sf::Texture P1_texture;
    sf::Sprite P1_Sprite;
    sf::Texture P2_texture;
    sf::Sprite P2_Sprite;
    sf::Texture MAIN_texture;
    sf::Sprite MAIN_Sprite;
    sf::Sprite FIN_NIVEAU;
    sf::Texture FIN_TEXTURE;

    //conteneurs
    Conteneur *LISTE_ACTIONS;
    Conteneur *MAIN;
    Conteneur *P1;
    Conteneur *P2;
    int m_dir;
    //robot
    Robot *m_robot;

    //pointeur niveau
    Niveau *m_niveau;

    //niveau actuel
    int numeroNiveau;
    //savoir si c'est un niveau editeur(ca changera le numero du fichier a appeler)
    bool est_fic_editeur;
    //booléen permettant de savoir si c'est fini
    bool fini = false;

    //fonction permettant d'exécuter le jeu
    void lancerMain(Conteneur * main);

    //boucle
    void loop()  override;

    //fonction d'affichage
    void draw(sf::RenderWindow &window);

    //evenements
    void mouse_button_pressed()                        override;
    void mouse_button_released()                       override;
    void mouse_moved()                                 override;
    void key_pressed(const sf::Event::KeyEvent & event)override;
public:

    //constructeurs destructeurs
    AppliTableau(sf::RenderWindow &window, int num, bool est_niveau_editeur);
    void est_fini();
    ~AppliTableau();

};

#endif // APPLITABLEAU_H
