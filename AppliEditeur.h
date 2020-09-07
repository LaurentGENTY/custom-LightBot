#ifndef APPLIEDITEUR_H
#define APPLIEDITEUR_H
#include "Application.h"
#include<CasesEditeur.h>
#include<Bouton.h>
#include<ChangementFenetre.h>
#include<iostream>
#include<fstream>
class AppliEditeur : public Application
{
private:
    //tableau de cases
    std::array<std::array<CasesEditeur*,10>,10> m_grille;

    //map
    std::map<std::string, Bouton*> m_boutons;

    //entiers niveau actuel
    int numero_de_niveau;

    //etat pour savoir dans quel etat on est
    enum etat {INITIAL,SELEC_DEBUT,SELEC_CASES_ALLU,SELECT_ETAGE,SELECT_ETAGE_MOINS};
    etat col = INITIAL;

    //elements graphiques
    int RAYON_CASES_EDITEUR=30;
    sf::CircleShape m_case;

    //positions
    int m_position_x=320;
    int m_position_y=250;
    int m_x_temp=0;
    int m_y_temp=0;
    Position souris ={0,0};
    int m_dir = 0;
    //booléens
    bool cherche_case=false;
    bool debut_choisi = false;
public:

    //constructeurs destructeurs
    AppliEditeur(sf::RenderWindow &window,int numero_niveau);
    ~AppliEditeur();

    //fonction d'affichage
    void draw();

    //boucle
    void loop() override;

    //evenements
    void mouse_button_pressed()                        override;
    void mouse_button_released()                       override;
    void mouse_moved()                                 override;
    void key_pressed(const sf::Event::KeyEvent &event) override;

    //setters
    int avancer_x(int xplus);
    int avancer_y(int yplus);
    void reinitialiser();
    void reinitialiser_impair();

    //sauvegarde
    void sauvegarde(std::string fichier);
};

#endif // APPLIEDITEUR_H
