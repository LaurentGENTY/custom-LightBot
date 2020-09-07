#include "Text.h"

Text::Text(std::string texte)
{
    m_font.loadFromFile("data/police.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(35);
    m_text.setString(texte);
    m_text.setColor(sf::Color::Black);
}

sf::Text Text::text()
{
    //return le text
    return m_text;
}

void Text::setTextPosition(Position p)
{
    m_text.setPosition(p);
}

void Text::changer_texte(std::string Nouveau_texte)
{
    m_text.setString(Nouveau_texte);
}
