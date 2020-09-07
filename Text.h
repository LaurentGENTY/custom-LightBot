#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>

using Position = sf::Vector2f;
class Text
{
private:

    //elements graphiques
    sf::Font m_font;
    sf::Text m_text;

public:
    //constructeurs destructeurs
    Text(std::string texte);

    //getters
    sf::Text text();

    //setters
    void setTextPosition(Position p);
    void changer_texte(std::string Nouveau_texte);
};

#endif // TEXT_H
