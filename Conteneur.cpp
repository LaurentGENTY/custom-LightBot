#include "Conteneur.h"
#include <iostream>
#include<time.h>
#include <stdio.h>
#include <unistd.h>

Conteneur::Conteneur(std::string type, int nombreActionMAX, int nbAction, Position p)
    : m_action_max{nombreActionMAX}
    , m_nbAction{nbAction}
{

    //init du tab d'actions
    m_rect_actions.setPosition(p);
    m_rect_actions.setFillColor(sf::Color(186, 186, 186));
    m_rect_actions.setSize({700,150});

    //selon le type init soit le tab d'actions, soit les images des conteneurs adequats
    if(type == "liste")
    {
        for(int i = 0 ; i<7;i++)
            m_liste_actions[i]=nullptr;
        if(!m_texture.loadFromFile("data/listeaction.png"))
        {
            std::cout << "Pas trouve" << std::endl;
        }
        m_texture.loadFromFile("data/listeaction.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(p);
        m_sprite.setScale({1.,1.});

        m_liste_actions[0] = new Action(Etat::AVANCER, false);
        m_liste_actions[1] = new Action(Etat::INTERAGIR, false);
        m_liste_actions[2] = new Action(Etat::TOURNERDROITE, false);
        m_liste_actions[3] = new Action(Etat::TOURNERGAUCHE, false);
        m_liste_actions[4] = new Action(Etat::SAUTER, false);
        m_liste_actions[5] = new Action(Etat::P1, false);
        m_liste_actions[6] = new Action(Etat::P2, false);
    }


    if(type == "main")
    {
        if(!m_texture.loadFromFile("data/main.png"))
        {
            std::cout << "Pas trouve" << std::endl;
        }
        m_texture.loadFromFile("data/main.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(p);
        m_sprite.setScale({1.,1.});
    }
    if(type == "p1")
    {
        if(!m_texture.loadFromFile("data/proc1.png"))
        {
            std::cout << "Pas trouve" << std::endl;
        }
        m_texture.loadFromFile("data/proc1.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(p);
        m_sprite.setScale({1.,1.});
    }

    if(type == "p2")
    {
        if(!m_texture.loadFromFile("data/proc2.png"))
        {
            std::cout << "Pas trouve" << std::endl;
        }
        m_texture.loadFromFile("data/proc2.png");
        m_sprite.setTexture(m_texture);
        m_sprite.setPosition(p);
        m_sprite.setScale({1.,1.});
    }
}

Conteneur::~Conteneur()
{
    //delete du vecteur d(actions
    for(auto a : m_actions)
    {
        delete a;
    }
    //delete liste actions
    for(auto a : m_liste_actions)
    {
        delete a;
    }
}

const std::array<Action *, 7> &Conteneur::getTabActions()
{
    //get la liste d'actions
    return  m_liste_actions;
}


void Conteneur::afficher(sf::RenderWindow &window)
{
    //affiche les sprites
    window.draw(m_sprite);

    //affiche les actions
    for(auto a : m_liste_actions)
    {
        a->afficher(window);
    }
}


void Conteneur::deleteAction()
{
    //s'il y a plus de 0 actions dans le conteneur on peut enelver des actions
    if(m_nbAction>0)
    {
        m_actions.pop_back();
        m_nbAction--;
    }
}

void Conteneur::baisseRep()
{
    //pour eviter de trop faire de recursivité
    if(MaxRep>0)
    {
        MaxRep--;
    }
}

void Conteneur::maxRep()
{
    //max de repetitions faire en sorte d'eviter les boucles infinies
    MaxRep = 2;
}

int Conteneur::getNombre()
{
    //renvoie le nombre d'action dans le conteneur
    return m_nbAction;
}

int Conteneur::getMaxAction()
{
    //renvoie le nombre max d'actions du conteneur
    return m_action_max;
}

const std::vector<Action *> &Conteneur::getActions()
{
    //renvoie le vecteur d'actions
    return m_actions;
}

bool Conteneur::onASelect()
{
    //verifie si pour toutes la liste d'actions, on en a selectionné une
    bool select = false;
    for(int i = 0; i < 7; i++){
        if(m_liste_actions[i]->getSelect())
        {
            select = true;
        }
    }
    return select;
}


void Conteneur::placerSpriteDansProg(std::string type,int nombre)
{
    //selon le type de conteneur on va placer différemment
    if(type == "main")
    {
        //selon le nombre d'action, on place a une position particulière
        switch(nombre)
        {
        case 0:
            //affiche les actions
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            //positionne le sprite correspondant a l'action 0 a la position suivante
            m_actions.at(0)->positionSprite({870,670});
            break;
        case 1:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(1)->positionSprite({940,670});
            break;
        case 2:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(2)->positionSprite({1010,670});
            break;
        case 3:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(3)->positionSprite({1080,670});
            break;
        case 4:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(4)->positionSprite({870,740});
            break;
        case 5:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(5)->positionSprite({940,740});
            break;
        case 6:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(6)->positionSprite({1010,740});
            break;
        case 7:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(7)->positionSprite({1080,740});
            break;
        case 8:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(8)->positionSprite({870,810});
            break;
        case 9:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(9)->positionSprite({940,810});
            break;
        case 10:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(10)->positionSprite({1010,810});
            break;
        case 11:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(11)->positionSprite({1080,810});
            break;
        case 12:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(12)->positionSprite({870,880});
            break;
        case 13:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(13)->positionSprite({940,880});
            break;
        case 14:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(14)->positionSprite({1010,880});
            break;
        case 15:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(15)->positionSprite({1080,880});
            break;
        }
    }
    if(type == "p1")
    {
        switch(nombre)
        {
        case 0:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(0)->positionSprite({20,820});
            break;
        case 1:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(1)->positionSprite({90,820});
            break;
        case 2:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(2)->positionSprite({160,820});
            break;
        case 3:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(3)->positionSprite({230,820});
            break;
        case 4:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(4)->positionSprite({20,890});
            break;
        case 5:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(5)->positionSprite({90,890});
            break;
        case 6:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(6)->positionSprite({160,890});
            break;
        case 7:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(7)->positionSprite({230,890});
            break;
        }
    }
    if(type == "p2")
    {
        switch(nombre)
        {
        case 0:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(0)->positionSprite({420,820});
            break;
        case 1:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(1)->positionSprite({490,820});
            break;
        case 2:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(2)->positionSprite({560,820});
            break;
        case 3:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(3)->positionSprite({630,820});
            break;
        case 4:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(4)->positionSprite({420,890});
            break;
        case 5:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(5)->positionSprite({490,890});
            break;
        case 6:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(6)->positionSprite({560,890});
            break;
        case 7:
            for(auto a : m_actions)
            {
                std::cout << a->action() << std::endl;
            }
            m_actions.at(7)->positionSprite({630,890});
            break;
        }
    }
}

void Conteneur::clear()
{
    //nettoie le programme d'actions du conteneneur
    m_actions.clear();
    m_nbAction =0;
}

void Conteneur::ajouter_action(Conteneur *prog)
{
    //selon l'action selectionnée on l'ajoute dans le conteneur : dans le vecteur d'actions
    if(prog->m_liste_actions[0]->isSelect())
    {
        std::cout << "AVANCER" << std::endl;
        std::cout << "*******************" << std::endl;
        //on l'ajoute dans le vecteur
        m_actions.push_back(new Action(Etat::AVANCER,false));
    }
    else if(prog->m_liste_actions[1]->isSelect())
    {
        std::cout << "INTERAGIR" << std::endl;
        std::cout << "*******************" << std::endl;

        m_actions.push_back(new Action(Etat::INTERAGIR,false));
    }
    else if(prog->m_liste_actions[2]->isSelect())
    {
        std::cout << "TOURNERDROITE" << std::endl;
        std::cout << "*******************" << std::endl;

        m_actions.push_back(new Action(Etat::TOURNERDROITE,false));
    }
    else if(prog->m_liste_actions[3]->isSelect())
    {
        std::cout << "TOURNERGAUCHE" << std::endl;
        std::cout << "*******************" << std::endl;

        m_actions.push_back(new Action(Etat::TOURNERGAUCHE,false));
    }
    else if(prog->m_liste_actions[4]->isSelect())
    {
        std::cout << "SAUTER" << std::endl;
        std::cout << "*******************" << std::endl;

        m_actions.push_back(new Action(Etat::SAUTER,false));
    }
    else if(prog->m_liste_actions[5]->isSelect())
    {
        std::cout << "P1" << std::endl;
        std::cout << "*******************" << std::endl;

        m_actions.push_back(new Action(Etat::P1,false));
    }
    else if(prog->m_liste_actions[6]->isSelect())
    {
        std::cout << "P2" << std::endl;
        std::cout << "*******************" << std::endl;

        m_actions.push_back(new Action(Etat::P2,false));
    }
    else
    {
        std::cout << "Trop d'actions" << std::endl;
    }
}

void Conteneur::executer(Robot *r, Conteneur *main, Conteneur *p1, Conteneur *p2, int programmeLance, bool &fini, sf::RenderWindow &window)
{
    //selon le programme qu'on lance soit main p1 ou p2
    switch(programmeLance)
    {
    //si le main est lancé
    case 0:
        for(int i = 0; i < m_nbAction; i++)
        {
            //comportement différent selon l'action
            Etat temp;
            temp = main->getActions().at(i)->getEtatDeLaction();
            switch(temp)
            {
            case Etat::AVANCER:
                std::cout << "AVANCER" << std::endl;
                r->avancer();
                break;
            case Etat::SAUTER:
                std::cout << "SAUTER" << std::endl;
                r->sauter();
                break;
            case Etat::TOURNERDROITE:
                std::cout << "TOURNERDROITE" << std::endl;
                r->tourner_droite();
                r->changerSprite();
                break;
            case Etat::TOURNERGAUCHE:
                std::cout << "TOURNERGAUCHE" << std::endl;
                r->tourner_gauche();
                r->changerSprite();
                break;
            case Etat::INTERAGIR:
                std::cout << "INTERAGIR" << std::endl;
                r->allumer();
                break;
            case Etat::P1:
                std::cout << "P1" << std::endl;

                p1->executer(r,main,p1,p2,1,fini,window);

                break;
            case Etat::P2:
                std::cout << "P2" << std::endl;
                p2->executer(r,main,p1,p2,2,fini,window);

                break;
            }
            r->afficher(window);
            window.display();
            sleep(0.75);
        }
        break;
        //si le p1 est lancé
    case 1:
        for(int i = 0; i < m_nbAction; i++)
        {

            Etat temp;
            temp = p1->getActions().at(i)->getEtatDeLaction();
            switch(temp)
            {
            case Etat::AVANCER:
                std::cout << "AVANCER" << std::endl;
                r->avancer();
                break;
            case Etat::SAUTER:
                std::cout << "SAUTER" << std::endl;
                r->sauter();
                break;
            case Etat::TOURNERDROITE:
                std::cout << "TOURNERDROITE" << std::endl;
                r->tourner_droite();

                r->changerSprite();
                break;
            case Etat::TOURNERGAUCHE:
                std::cout << "TOURNERGAUCHE" << std::endl;
                r->tourner_gauche();

                r->changerSprite();
                break;
            case Etat::INTERAGIR:
                std::cout << "INTERAGIR" << std::endl;
                r->allumer();

                break;
            case Etat::P1:
                std::cout << "P1" << std::endl;
                baisseRep();
                if(MaxRep !=0)
                {
                    p1->executer(r,main,p1,p2,1,fini,window);
                }
                break;
            case Etat::P2:
                std::cout << "P2" << std::endl;
                baisseRep();
                if(MaxRep !=0)
                {
                    p2->executer(r,main,p1,p2,2,fini,window);
                }
                break;
            }
            r->afficher(window);
            window.display();
            sleep(0.75);
        }
        break;
        //si le p2 est lancé
    case 2:
        for(int i = 0; i < m_nbAction; i++)
        {
            Etat temp;
            temp = p2->getActions().at(i)->getEtatDeLaction();
            switch(temp)
            {
            case Etat::AVANCER:
                std::cout << "AVANCER" << std::endl;

                r->avancer();

                break;
            case Etat::SAUTER:
                std::cout << "SAUTER" << std::endl;
                r->sauter();
                break;
            case Etat::TOURNERDROITE:
                std::cout << "TOURNERDROITE" << std::endl;
                r->tourner_droite();

                r->changerSprite();
                break;
            case Etat::TOURNERGAUCHE:
                std::cout << "TOURNERGAUCHE" << std::endl;
                r->tourner_gauche();

                r->changerSprite();
                break;
            case Etat::INTERAGIR:
                std::cout << "INTERAGIR" << std::endl;
                r->allumer();

                break;
            case Etat::P1:
                std::cout << "P1" << std::endl;

                baisseRep();
                if(MaxRep !=0)
                {
                    p1->executer(r,main,p1,p2,1,fini,window);
                }
                break;
            case Etat::P2:
                std::cout << "P2" << std::endl;
                baisseRep();
                if(MaxRep !=0)
                {
                    p2->executer(r,main,p1,p2,2,fini,window);
                }
                break;
            }
            r->afficher(window);
            window.display();
            sleep(0.75);
        }
        break;
    }
}


void Conteneur::setAction(std::array<Action *, 7> tab, int indice)
{
    //si l'action sur laquelle on a cliqué n'est pas selectionnée
    if(!tab[indice]->isSelect())
    {
        //alors on l'a passe en select
        tab[indice]->setSelect(true);
        //on change son sprite
        tab[indice]->setSprite();
        //pour toutes les autres on les passe en non select et on change leur sprite en normal
        for(int i = 0; i < 7; i ++)
        {
            if(indice != i)
            {
                tab[i]->setSelect(false);
                tab[i]->setSprite();
            }
        }
    }
    //si elle a déjà été selectionnée, cela veut dire qu'on l'a deselectionne
    else
    {
        //on l'a repasse en non select et on change son sprite
        tab[indice]->setSelect(false);
        tab[indice]->setSprite();

    }


}

void Conteneur::setNombre(int nombre)
{
    //le nombre d'action du conteneur correspond au nombre qu'on a mis en paramètre (sert a incrémenter le nombre d'actions
    m_nbAction = nombre;
}

std::string Conteneur::action()
{
    //renvoie juste le message comme quoi c'est un conteneur
    return "Conteneur";
}

bool Conteneur::contient(Position p)
{
    //fonction permettant de savoir si la souris est dans le sprite du conteneur
    if(m_sprite.getGlobalBounds().contains(p))
    {
        return true;
    }
    else
    {
        return false;
    }
}
