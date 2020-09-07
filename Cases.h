#ifndef CASES_H
#define CASES_H
#include<vector>
#include<Application.h>
constexpr int RAYON_CASES=40;
class Cases
{
private:
    //elements graphiques
    sf::CircleShape m_case;
    sf::CircleShape m_dessous;

    //position
    Position m_position;

    //booléen permettant de connaitre les propriétés de de la case
    bool m_doit_etre_cachee = false;
    bool m_est_activee = false;
    bool m_est_debut = false;
    bool m_est_allumable=false;
    bool m_est_allumee=false;

    //nb etages
    int m_etages=0;

    //etat permettant de savoir l'état d'une case
    enum class Etat { NONDISPONIBLE, ALLUME, DISPONIBLE, ETEINT } m_state;

public:
    //constructeurs destructeurs
    Cases(Position pos, sf::Color col);

    //getters
    Position get_pos(){return m_position;}
    int get_nb_etage(){return m_etages;}
    bool est_debut(){return m_est_debut;}
    bool est_allumee(){return m_est_allumee;}
    bool est_allumable(){return m_est_allumable;}
    bool est_activee(){return m_est_activee;}

    //setters
    void doit_etre_cache(){m_doit_etre_cachee=true;}
    void set_etage(int etage);
    void set_activer();
    void ajouter_etage();
    void definir_debut();
    void definir_allumable();
    void modif_pos(Position p);

    //fonction d'affichage
    void afficher(sf::RenderWindow & window);
    void allumer();
    ~Cases();

};

#endif // CASES_H
