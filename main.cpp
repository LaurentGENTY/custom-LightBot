#include <iostream>

#include "AppliTableau.h"
#include "AppliMenu.h"
#include "AppliChoixNiveau.h"

using namespace std;

int main()
{
    cout << "Lancement Jeu" << endl;

    sf::RenderWindow window(sf::VideoMode(1200,1000),"LightBot",sf::Style::Close);
    AppliMenu a(window);
    a.run();
}

