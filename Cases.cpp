#include "Cases.h"
#include<iostream>
//Cases::Cases(Position pos,sf::Color col)
//    :m_position{pos}
//{

////    m_case.setPosition(m_position);
////    m_case.setRadius(40);
////    m_case.setOutlineThickness(1.5);
////    m_case.setOutlineColor(sf::Color::White);
////    m_case.setPointCount(6);
////    m_case.rotate(-15);
////    m_case.setScale({1,0.5});
////    m_case.setFillColor(col);
////    m_dessous.setPosition({m_position.x+4,m_position.y+15});
////    m_dessous.setRadius(40);
////    m_dessous.setPointCount(6);
////    m_dessous.rotate(-15);
////    m_dessous.setScale({1,0.5});
////    m_dessous.setFillColor(sf::Color(160,160,160));

//    m_case.setPosition(m_position);
//    m_case.setRadius(40);
//    m_case.setOutlineThickness(1.5);
//    m_case.setOutlineColor(sf::Color::White);
//    m_case.setPointCount(6);
//    m_case.setFillColor(col);

//    m_dessous.setPosition({m_position.x,m_position.y+15});
//    m_dessous.setRadius(40);
//    m_dessous.setOutlineThickness(1.5);
//    m_dessous.setOutlineColor(sf::Color::White);
//    m_dessous.setPointCount(6);
//    m_dessous.setFillColor(sf::Color(160,160,160));



//}



//void Cases::afficher(sf::RenderWindow &window)
//{
//    window.draw(m_dessous);
//    window.draw(m_case);

//}

//void Cases::modif_pos(Position p)
//{
//    m_position=p;
//    m_case.setPosition(m_position);
//    m_dessous.setPosition({m_position.x+4,m_position.y+15});
//}

Cases::Cases(Position pos,sf::Color col)
    :m_position{pos}
{
    m_case.setPosition(m_position);
    m_case.setRadius(RAYON_CASES);
    m_case.setOutlineThickness(1.5);
    m_case.setOutlineColor(sf::Color::White);
    m_case.setPointCount(6);
    m_case.setScale({1,0.5});
    m_case.setFillColor(col);
    m_dessous.setPosition({m_position.x,m_position.y+15});
    m_dessous.setRadius(RAYON_CASES);
    m_dessous.setPointCount(6);
    m_dessous.setOutlineColor(sf::Color::White);
    m_dessous.setOutlineThickness(1.0);
    m_dessous.setScale({1,0.5});
    m_dessous.setFillColor(sf::Color(160,160,160));

}




void Cases::afficher(sf::RenderWindow &window)
{

    //affiche les hexa
    window.draw(m_dessous);
    window.draw(m_case);

    //affiche les etages
    for(int i =0;i<=m_etages;i++)
    {
        m_case.setPosition(m_position.x,m_position.y-(i*15));
        m_dessous.setPosition(m_position.x,m_position.y-(i-1)*15);
        window.draw(m_dessous);
        window.draw(m_case);
    }
    if(m_est_activee)
        m_case.setFillColor(sf::Color(0,51,102));

//    if(m_doit_etre_cachee==true)
//    {
//        m_case.setFillColor(sf::Color::Transparent);
//        m_dessous.setFillColor(sf::Color::Transparent);
//        m_case.setOutlineColor(sf::Color::Red);
//        m_dessous.setOutlineColor(sf::Color::Red);
//    }

    if(m_etages>0)
        m_case.setFillColor(sf::Color(0,51,102));
    if(m_est_allumable)
        m_case.setFillColor(sf::Color(204,204,0));
    if(m_est_allumee)
        m_case.setFillColor(sf::Color::Red);

//m_case.setFillColor(sf::Color(0,102,204));

}

void Cases::allumer()
{
    //si allumable alors on lallume
    if(m_est_allumable)
    {
        m_est_allumee=true;

    }

}

Cases::~Cases()
{

}

void Cases::modif_pos(Position p)
{
    //on affecte la nouvelle pos
    m_position=p;
    m_case.setPosition(m_position);
    m_dessous.setPosition({m_position.x,m_position.y+15});
}

void Cases::ajouter_etage()
{
    //augmente mes etages
    m_etages++;
}

void Cases::set_etage(int etage)
{
    //set mes etages
    m_etages=etage;
}

void Cases::definir_debut()
{
    //devient debut
    m_est_debut=true;
}

void Cases::set_activer()
{
    //devient activée
    m_est_activee=true;
}

void Cases::definir_allumable()
{
    //est allumable
    m_est_allumable=true;
}

