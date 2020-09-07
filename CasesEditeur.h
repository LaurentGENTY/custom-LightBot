#ifndef CASESEDITEUR_H
#define CASESEDITEUR_H
#include<SFML/Graphics.hpp>
#include<Application.h>
#include<Text.h>
class CasesEditeur
{
private:
    //elements graphiques
    sf::CircleShape m_case;

    //attributs caractérisants une case
    int RAYON= 30;
    int m_etages=0;
    int m_pos_x;
    int m_pos_y;

    //booléen permettant de connaitre les propriétés de de la case
    bool m_est_activee = false;
    bool m_est_debut = false;
    bool m_est_allumable=false;

    Text teexte{"0"};

public:

    //constructeurs destructeurs
    CasesEditeur(Position pos);
    ~CasesEditeur();

    //getters
    bool est_debut(){return m_est_debut;}
    bool est_active(){return m_est_activee;}
    float contains(Position p);
    std::string to_string();

    //setters
    void ajouter_etage();
    void enlever_etage();
    void set_etage(int etage);
    void set_activer();
    void activer(bool &debut);
    void definir_debut();
    void definir_allumable();

    //fonction d'affichage
    void afficher(sf::RenderWindow & window);
    void modif_couleur(sf::Color col); 

};

#endif // CASESEDITEUR_H
