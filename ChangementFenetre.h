#ifndef CHANGEMENTFENETRE_H
#define CHANGEMENTFENETRE_H
#include <SFML/Graphics.hpp>
#include "AppliChoixNiveau.h"
#include "AppliMenu.h"
#include "AppliTableau.h"
#include "AppliEditeur.h"
#include "AppliTransition.h"
#include "AppliChoixEdite.h"
class ChangementFenetre
{
public:
    //constructeurs destructeurs
    ChangementFenetre();

    //fonction de changement d'écran
    static void allerJeu(sf::RenderWindow &window, int numeroDuNiveau,bool est_fic_jeu);
    static void allerMenu(sf::RenderWindow &window);
    static void allerChoixNiveau(sf::RenderWindow &window, bool est_edit);
    static void allerEditeur(sf::RenderWindow &window, int i);
    static void allerTransition(sf::RenderWindow &window);
    static void allerChoixEdit(sf::RenderWindow &window);
};

#endif // CHANGEMENTFENETRE_H
