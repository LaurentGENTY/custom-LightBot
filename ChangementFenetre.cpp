#include "ChangementFenetre.h"

ChangementFenetre::ChangementFenetre()
{
}

void ChangementFenetre::allerJeu(sf::RenderWindow &window,int numeroDuNiveau,bool est_fic_edit)
{
    AppliTableau a(window,numeroDuNiveau,est_fic_edit);
    a.run();
    window.close();
}

void ChangementFenetre::allerMenu(sf::RenderWindow &window)
{
    AppliMenu a(window);
    a.run();
    window.close();
}

void ChangementFenetre::allerChoixNiveau(sf::RenderWindow &window,bool est_edit)
{
    AppliChoixNiveau a(window,est_edit);
    a.run();
    window.close();
}

void ChangementFenetre::allerEditeur(sf::RenderWindow &window,int i)
{
    AppliEditeur a(window,i);
    a.run();
    window.close();
}

void ChangementFenetre::allerTransition(sf::RenderWindow &window)
{
    AppliTransition a(window);
    a.run();
    window.close();
}

void ChangementFenetre::allerChoixEdit(sf::RenderWindow &window)
{
    AppliChoixEdite a(window);
    a.run();
    window.close();
}
