#include "Robot.h"
#include <iostream>

Robot::Robot( std::array<std::array<Cases*,10>,10> & grille , int dir)
    :m_grille(grille)
    ,m_dir{dir}
{
    m_dir_initiale=m_dir;
    if(!m_textureSE.loadFromFile("data/southeast.png"))
    {
        std::cout << "southeast Pas trouve" << std::endl;
    }
    if(!m_textureSW.loadFromFile("data/southwest.png"))
    {
        std::cout << "southwest Pas trouve" << std::endl;
    }
    if(!m_textureW.loadFromFile("data/west.png"))
    {
        std::cout << "west Pas trouve" << std::endl;
    }
    if(!m_textureNW.loadFromFile("data/northwest.png"))
    {
        std::cout << "northwest Pas trouve" << std::endl;
    }
    if(!m_textureNE.loadFromFile("data/northeast.png"))
    {
        std::cout << "northeast Pas trouve" << std::endl;
    }
    if(!m_textureE.loadFromFile("data/east.png"))
    {
        std::cout << "east Pas trouve" << std::endl;
    }

    m_textureSE.loadFromFile("data/southeast.png");
    m_textureSW.loadFromFile("data/southwest.png");
    m_textureW.loadFromFile("data/west.png");
    m_textureNW.loadFromFile("data/northwest.png");
    m_textureNE.loadFromFile("data/northeast.png");
    m_textureE.loadFromFile("data/east.png");


    for(int i=0;i<10;i++)
    {

        for(int j=0;j<10;j++)
        {

            if(m_grille[i][j]->est_debut())
            {



                pos_tableau={j,i};

            }
        }
    }
    m_position=m_grille[pos_tableau.y][pos_tableau.x]->get_pos();

    //selon sa direction le sprite change
    switch(m_dir)
    {
    case 0:
        m_sprite.setTexture(m_textureNE);
        break;
    case 1:
        m_sprite.setTexture(m_textureE);
        break;
    case 2:
        m_sprite.setTexture(m_textureSE);
        break;
    case 3:
        m_sprite.setTexture(m_textureSW);
        break;
    case 4:
        m_sprite.setTexture(m_textureW);
        break;
    case 5:
        m_sprite.setTexture(m_textureNW);
        break;
    }

    //on le place
    m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});
    m_sprite.setScale({1.,1.});
}

//Cases *Robot::getCase()
//{
//    //return m_case;

//}

Robot::~Robot()
{
    //delete toutes les cases
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            delete m_grille[i][j];
        }
}

void Robot::afficher(sf::RenderWindow &window)
{
    //affiche son sprite
    window.draw(m_sprite);
}

void Robot::setDirection(int dir)
{
    //affecte nouvelle direction
    m_dir=dir;

}

int Robot::getDirection()
{
    //retourn sa direction
    return m_dir;
}

void Robot::avancer()//gère la position du robot en fonction du nombre d'étages présents
{
    switch(m_dir)
    {
    case 0:

        if(pos_tableau.y-1>=0 && pos_tableau.x+1<10&&m_grille[pos_tableau.y-1][pos_tableau.x+1]->est_activee())
        {
            int diff = (m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()-m_grille[pos_tableau.y-1][pos_tableau.x+1]->get_nb_etage());
            if(diff==-1&&m_est_etat_saut)

            {
                std::cout<<"test3"<<diff<<"diff"<<pos_tableau.x<<"x"<<pos_tableau.y<<"y";
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES-sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y -sqrt(0.25*RAYON_CASES*RAYON_CASES)/2-RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y-1][pos_tableau.x+1]->get_nb_etage()});
                pos_tableau.y--;
                pos_tableau.x++;
            }
            else if(diff==1&&m_est_etat_saut)
            {
                std::cout<<"test2"<<diff<<"diff"<<pos_tableau.x<<"x"<<pos_tableau.y<<"y";
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES-sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y -sqrt(0.25*RAYON_CASES*RAYON_CASES)/2-RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35+15-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});

                pos_tableau.y--;
                pos_tableau.x++;
            }
            else if (diff==0)
            {
                std::cout<<"test1"<<diff<<"diff"<<pos_tableau.x<<"x"<<pos_tableau.y<<"y";
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES-sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y -sqrt(0.25*RAYON_CASES*RAYON_CASES)/2-RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});
                pos_tableau.y--;
                pos_tableau.x++;

            }

        }

        break;
    case 1:
        if(pos_tableau.x+1<10&&m_grille[pos_tableau.y][pos_tableau.x+1]->est_activee())
        {
            int diff = (m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()-m_grille[pos_tableau.y][pos_tableau.x+1]->get_nb_etage());
            if(diff==-1&&m_est_etat_saut)

            {
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x+1]->get_nb_etage()});

                pos_tableau.x++;
            }
            else if(diff==1&&m_est_etat_saut)
            {
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES;
                m_sprite.setPosition({m_position.x+7,m_position.y-35+15-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});


                pos_tableau.x++;
            }
            else if (diff==0)
            {
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES;
                m_sprite.setPosition({m_position.x+7,m_sprite.getPosition().y});

                pos_tableau.x++;

            }




        }

        break;
    case 2:
        if(pos_tableau.y+1<10&&m_grille[pos_tableau.y+1][pos_tableau.x]->est_activee())
        {
            int diff = (m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()-m_grille[pos_tableau.y+1][pos_tableau.x]->get_nb_etage());
            if(diff==-1&&m_est_etat_saut)

            {
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES-sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y +sqrt(0.25*RAYON_CASES*RAYON_CASES)/2+RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-15*m_grille[pos_tableau.y+1][pos_tableau.x]->get_nb_etage()-35});
                pos_tableau.y++;
            }
            else if(diff==1&&m_est_etat_saut)
            {
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES-sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y +sqrt(0.25*RAYON_CASES*RAYON_CASES)/2+RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_sprite.getPosition().y+35+15*m_grille[pos_tableau.y+1][pos_tableau.x]->get_nb_etage()});

                pos_tableau.y++;
            }
            else if (diff==0)
            {
                m_position.x=m_position.x+sqrt(3)*RAYON_CASES-sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y +sqrt(0.25*RAYON_CASES*RAYON_CASES)/2+RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});
                pos_tableau.y++;

            }


        }
        break;
    case 3:
        if(pos_tableau.y+1<10 && pos_tableau.x-1>=0&&m_grille[pos_tableau.y+1][pos_tableau.x-1]->est_activee())
        {
            int diff = (m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()-m_grille[pos_tableau.y+1][pos_tableau.x-1]->get_nb_etage());
            if(diff==-1&&m_est_etat_saut)

            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES+sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y +sqrt(0.25*RAYON_CASES*RAYON_CASES)/2+RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-15*m_grille[pos_tableau.y+1][pos_tableau.x-1]->get_nb_etage()-35});
                pos_tableau.y++;
                pos_tableau.x--;
            }
            else if(diff==1&&m_est_etat_saut)
            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES+sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y +sqrt(0.25*RAYON_CASES*RAYON_CASES)/2+RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_sprite.getPosition().y+35+15*m_grille[pos_tableau.y+1][pos_tableau.x-1]->get_nb_etage()});

                pos_tableau.y++;
                pos_tableau.x--;
            }
            else if (diff==0)
            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES+sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y +sqrt(0.25*RAYON_CASES*RAYON_CASES)/2+RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});
                pos_tableau.y++;
                pos_tableau.x--;

            }


        }
        break;
    case 4:
        if(pos_tableau.x-1>=0&&m_grille[pos_tableau.y][pos_tableau.x-1]->est_activee())
        {
            int diff = (m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()-m_grille[pos_tableau.y][pos_tableau.x-1]->get_nb_etage());
            if(diff==-1&&m_est_etat_saut)

            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x-1]->get_nb_etage()});

                pos_tableau.x--;
            }
            else if(diff==1&&m_est_etat_saut)
            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES;
                m_sprite.setPosition({m_position.x+7,m_position.y-35+15-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});


                pos_tableau.x--;
            }
            else if (diff==0)
            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES;
                m_sprite.setPosition({m_position.x+7,m_sprite.getPosition().y});

                pos_tableau.x--;

            }

        }

        break;
    case 5:

        if(pos_tableau.y-1>=0&&m_grille[pos_tableau.y-1][pos_tableau.x]->est_activee())
        {
            int diff = (m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()-m_grille[pos_tableau.y-1][pos_tableau.x]->get_nb_etage());
            if(diff==-1&&m_est_etat_saut)

            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES+sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y -sqrt(0.25*RAYON_CASES*RAYON_CASES)/2-RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y-1][pos_tableau.x]->get_nb_etage()});
                pos_tableau.y--;
            }
            else if(diff==1&&m_est_etat_saut)
            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES+sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y -sqrt(0.25*RAYON_CASES*RAYON_CASES)/2-RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35+15-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});

                pos_tableau.y--;
            }
            else if (diff==0)
            {
                m_position.x=m_position.x-sqrt(3)*RAYON_CASES+sqrt(3)*RAYON_CASES/2;
                m_position.y=m_position.y -sqrt(0.25*RAYON_CASES*RAYON_CASES)/2-RAYON_CASES/2;
                m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});
                pos_tableau.y--;
            }




        }

        break;
    }
    m_est_etat_saut=false;
}

void Robot::tourner_droite()
{
    //tourne a droite
    m_dir++;
    if(m_dir>5)
        m_dir=0;
}

void Robot::tourner_gauche()
{
    //tourne a gauche
    m_dir--;
    if(m_dir<0)
        m_dir=5;
}

void Robot::allumer()
{
    //allume la case sur laquelle se trouve le robot
    m_grille[pos_tableau.y][pos_tableau.x]->allumer();

}

void Robot::changerSprite()
{
    //selon la directio alors on change le sprite
    switch(m_dir)
    {
    case 0:
        m_sprite.setTexture(m_textureNE);
        break;
    case 1:
        m_sprite.setTexture(m_textureE);
        break;
    case 2:
        m_sprite.setTexture(m_textureSE);
        break;
    case 3:
        m_sprite.setTexture(m_textureSW);
        break;
    case 4:
        m_sprite.setTexture(m_textureW);
        break;
    case 5:
        m_sprite.setTexture(m_textureNW);
        break;
    }
}

void Robot::reinitialiser()
{
    pos_tableau={0,0};
    for(int i=0;i<10;i++)
    {

        for(int j=0;j<10;j++)
        {

            if(m_grille[i][j]->est_debut())
            {


                pos_tableau={j,i};

            }
        }
    }
    m_dir=m_dir_initiale;
    switch(m_dir)
    {
    case 0:
        m_sprite.setTexture(m_textureNE);
        break;
    case 1:
        m_sprite.setTexture(m_textureE);
        break;
    case 2:
        m_sprite.setTexture(m_textureSE);
        break;
    case 3:
        m_sprite.setTexture(m_textureSW);
        break;
    case 4:
        m_sprite.setTexture(m_textureW);
        break;
    case 5:
        m_sprite.setTexture(m_textureNW);
        break;
    }
    m_position=m_grille[pos_tableau.y][pos_tableau.x]->get_pos();
    m_sprite.setPosition({m_position.x+7,m_position.y-35-15*m_grille[pos_tableau.y][pos_tableau.x]->get_nb_etage()});

}


