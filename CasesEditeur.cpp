#include "CasesEditeur.h"

CasesEditeur::CasesEditeur(Position pos)
    :m_pos_x{pos.x}
    ,m_pos_y{pos.y}
{
    m_case.setFillColor(sf::Color(128,128,128));
    m_case.setPosition(pos);
    m_case.setRadius(RAYON);
    m_case.setOutlineThickness(1.5);
    m_case.setOutlineColor(sf::Color(229,229,229));
    m_case.setPointCount(6);
    teexte.setTextPosition({pos.x+RAYON/1.5,pos.y+RAYON/4});
}

CasesEditeur::~CasesEditeur()
{
}

void CasesEditeur::afficher(sf::RenderWindow &window)
{
    //affichage de la case
    window.draw(m_case);
    window.draw(teexte.text());
}

void CasesEditeur::modif_couleur(sf::Color col)
{
    //set de la couleur
    m_case.setFillColor(col);
}

void CasesEditeur::ajouter_etage()
{
    //on augmente les etages
    if(m_etages<5)
        m_etages++;

    teexte.changer_texte(std::to_string(m_etages));
}

void CasesEditeur::enlever_etage()
{
    //descend les etages
    if(m_etages>0)
        m_etages--;
    teexte.changer_texte(std::to_string(m_etages));
}

void CasesEditeur::set_etage(int etage)
{
    //set les etages
    m_etages=etage;
    teexte.changer_texte(std::to_string(m_etages));

}

float CasesEditeur::contains(Position p)
{
    //si case contient p renvoie true
    return sqrt(((p.x-(m_case.getPosition().x+RAYON))*(p.x-(m_case.getPosition().x+30)))+((p.y-(m_case.getPosition().y+30))*(p.y-(m_case.getPosition().y+RAYON))));
}

void CasesEditeur::set_activer(){
    //case devient activée
    m_est_activee=true;
    m_case.setFillColor(sf::Color::White);
}

void CasesEditeur::activer(bool &debut){
    //si activée on invers
    if(m_est_activee == true)
    {
        m_est_activee=false;
        m_case.setFillColor(sf::Color(128,128,128));
        m_est_debut=false;
        debut=false;
        m_etages=0;
        teexte.changer_texte(std::to_string(m_etages));
        m_est_allumable=false;

    }
    else
    {
        m_est_activee = true;
        m_case.setFillColor(sf::Color::White);
    }
}

void CasesEditeur::definir_debut(){
    //definition dune case initiale
    if(est_debut() == true)
    {
        m_est_debut=false;
        m_case.setFillColor(sf::Color::White);

    }
    else
    {
        if(m_est_activee==true)
        {
            m_est_debut = true;
            m_case.setFillColor(sf::Color::Green);
        }

    }

}

void CasesEditeur::definir_allumable(){
    //on inverse la case speciale
    m_est_allumable=!m_est_allumable;
    if(m_est_allumable)
    {
        m_case.setFillColor(sf::Color::Yellow);
    }
    else
    {
        m_case.setFillColor(sf::Color::White);
    }
}

std::string CasesEditeur::to_string()
{
    //renvoie les attributs des cases
    return std::to_string(m_etages)+" "+std::to_string(m_est_activee)+" "+std::to_string(m_est_debut)+" "+std::to_string(m_est_allumable)+"\n";
}
