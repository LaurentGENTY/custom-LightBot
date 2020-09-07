#ifndef CONTENEUR_H
#define CONTENEUR_H
#include <SFML/Graphics.hpp>
#include "Action.h"
#include <array>
#include "Robot.h"

using Position = sf::Vector2f;

class Conteneur
{
private:
    //conteneurs : array , map, vector
    std::array<Action*,7> m_liste_actions;
    std::vector<Action*> m_actions;

    //elements graphiques
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::RectangleShape m_rect;

    //entier correspondant au nb max d'actions possible dans le conteneur et le nombre actuel
    int m_action_max;
    int m_nbAction;

    //entier donnant les rep max
    int MaxRep;
public:

    //constructeurs destructeurs
    Conteneur(std::string type, int nombreActionMAX, int nbAction, Position p);
    ~Conteneur();

    //getters
    const std::array<Action *, 7> &getTabActions();
    std::string action();
    sf::RectangleShape m_rect_actions;
    sf::RectangleShape getRect();
    int getNombre();
    int getMaxAction();
    const std::vector<Action *> &getActions();
    bool onASelect();
    bool contient(Position p);

    //setters
    void ajouter_action(Conteneur*prog);
    void setAction(std::array<Action*,7> tab, int indice);
    void setNombre(int nombre);
    void deleteAction();
    void baisseRep();
    void maxRep();
    void clear();

    //affichage
    void afficher(sf::RenderWindow &window);
    void placerSpriteDansProg(std::string type, int nombre);

    //execution
    void executer(Robot *r, Conteneur *main, Conteneur *p1, Conteneur *p2, int programmeLance, bool &fini,sf::RenderWindow &window);


};

#endif // CONTENEUR_H
