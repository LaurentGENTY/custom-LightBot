#include "AppliTableau.h"
#include <unistd.h>

namespace {
constexpr float RAYON = 20.0;
constexpr int W = 1200, H = 1000;
constexpr float X_TEXTE = 400., Y_TEXTE = 350.;
}

// sert a calculer en fonction du rayon la position du prochain hecagone sur la ligne
void calculer_prochain_ligne(float & x)
{
    x=x+sqrt(3)*RAYON_CASES;
}

// sert a calculer en fonction du rayon la position du prochain hecagone sur la colonne
void calculer_prochain_colonne(float & x, float & y)
{
    x=x+sqrt(3)*RAYON_CASES-sqrt(3)*RAYON_CASES/2;
    y=y +sqrt(0.25*RAYON_CASES*RAYON_CASES)/2+RAYON_CASES/2;
}


AppliTableau::AppliTableau(sf::RenderWindow &window, int num,bool est_niveau_editeur)
    : Application(window)
    , numeroNiveau{num+1}
    ,est_fic_editeur{est_niveau_editeur}
{
    if(!est_fic_editeur)
        numeroNiveau+=5;
    m_window.setTitle("Niveau");

    //init sprites
    if(!P1_texture.loadFromFile("data/proc1.png"))
    {
        std::cout << "Pas trouve" << std::endl;
    }

    if(!P2_texture.loadFromFile("data/proc2.png"))
    {
        std::cout << "Pas trouve" << std::endl;
    }
    if(!MAIN_texture.loadFromFile("data/main.png"))
    {
        std::cout << "Pas trouve" << std::endl;
    }
    if(!FIN_TEXTURE.loadFromFile("data/finlevel.png"))
    {
        std::cout << "Pas trouve" << std::endl;
    }

    FIN_NIVEAU.setTexture(FIN_TEXTURE);
    FIN_NIVEAU.setPosition({0,0});
    FIN_NIVEAU.setScale({1,1});
    P1_Sprite.setTexture(P1_texture);
    P1_Sprite.setPosition({0,800});
    P1_Sprite.setScale({1,1});
    P2_Sprite.setTexture(P2_texture);
    P2_Sprite.setPosition({400,800});
    P2_Sprite.setScale({1,1});
    MAIN_Sprite.setTexture(MAIN_texture);
    MAIN_Sprite.setPosition({850,650});
    MAIN_Sprite.setScale({1,1});


    //init des conteneurs
    LISTE_ACTIONS = new Conteneur("liste",7,0,{0,650});
    MAIN = new Conteneur("main",16,0,{850,650});
    P1 = new Conteneur("p1",8,0,{0,800});
    P2 = new Conteneur("p2",8,0,{400,650});

    //init grille entière
    float x=10;
    float y=200;
    float m=0;

    Cases * c = new Cases({x,y},sf::Color(64,64,64));
    for(int i=0;i<10;i++)
    {

        m=x;
        for(int j=0 ; j<10;j++)
        {

            Cases * c = new Cases({x,y},sf::Color(64,64,64));
            calculer_prochain_ligne(m);
            c->modif_pos({m,y});

            m_grille[i][j]=c;
        }
        calculer_prochain_colonne(x,y);
        c->modif_pos({x,y});
    }
    delete c;

    //ouverture du niveau selon le numero du niveau
    std::string fichier = "SauvegardeNiveau"+std::to_string(numeroNiveau)+".txt";
    std::fstream f;
    f.open( fichier.c_str(), std::ios::in );
    if( f.fail() )
    {
        std::cerr << numeroNiveau << std::endl;
        std::cerr << "ouverture en lecture impossible" << std::endl;
        exit(EXIT_FAILURE);
    }
    f>>m_dir;
    //grille correspondante
    int l=0;
    int n = 0;
    int k=0;
    for( int i=0; i<10; i++ )
        for( int j=0; j<10; j++ )
        {
            f>>l;
            f>>n;
            f>>k;
            m_grille[l][n]->set_etage(k);
            f>>k;
            if(k==1)
                m_grille[l][n]->set_activer();
            f>>k;
            if(k==1)
                m_grille[l][n]->definir_debut();
            f>>k;
            if(k==1)
                m_grille[l][n]->definir_allumable();

        }

    f.close();

    m_robot = new Robot(m_grille,m_dir);

    //init boutons
    m_boutons["lancer"] = new Bouton(1100,25,50.,50.,"data/start.png");
    m_boutons["fin"] = new Bouton(1150,950,50.,50.,"data/fin.png");
    m_boutons["retour"] = new Bouton(1000,25,50.,50.,"data/retourchoix.png");
    m_boutons["suppMain"] = new Bouton(1050,600,50.,50.,"data/suppr.png");
    m_boutons["suppP1"] = new Bouton(200,750,50.,50.,"data/suppr.png");
    m_boutons["suppP2"] = new Bouton(600,750,50.,50.,"data/suppr.png");
    m_boutons["deleteP1"] = new Bouton(250,750,50.,50.,"data/delete.png");
    m_boutons["deleteP2"] = new Bouton(650,750,50.,50.,"data/delete.png");
    m_boutons["deleteMain"] = new Bouton(1100,600,64.,64.,"data/delete.png");

    //init des textes
    m_texts["p1"] = new Text("P1");
    m_texts["p1"]->setTextPosition({0,750});
    m_texts["p2"] = new Text("P2");
    m_texts["p2"]->setTextPosition({400,750});
    m_texts["main"] = new Text("MAIN");
    m_texts["main"]->setTextPosition({850,600});
}

void AppliTableau::est_fini()
{
    int compteur=0;
    int compteur2=0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(m_grille[i][j]->est_allumable())
                compteur++;
            if(m_grille[i][j]->est_allumee())
                compteur2++;
        }
    }

    if(compteur==compteur2)
    {

        fini=true;
    }
    else
        fini=false;
}
AppliTableau::~AppliTableau()
{
    //delete des boutons
    for(auto a : m_boutons)
    {
        delete a.second;
    }
    //delete des textes
    for(auto a : m_texts)
    {
        delete a.second;
    }
    //delete des conteneurs
    delete LISTE_ACTIONS;
    delete MAIN;
    delete P1;
    delete P2;

    //delete de la grlle
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            delete m_grille[i][j];
        }
    }

    //delete du robot
    delete m_robot;

    //delete du niveau
    delete m_niveau;
}

void AppliTableau::loop()
{
    //clear window
    m_window.clear(sf::Color(229,229,229));

    //affichage des cases (peut etre deplacée dans la fonction draw
    for(int i=0;i<10;i++)
    {
        for(int j =0 ;j<10 ;j++)
        {
            m_grille[i][j]->afficher(m_window);
        }
    }
    //affichage
    draw(m_window);
    m_window.display();
}

void AppliTableau::draw(sf::RenderWindow &window)
{
    //affichage des sprites
    window.draw(MAIN_Sprite);
    window.draw(P1_Sprite);
    window.draw(P2_Sprite);

    //afficher la liste des actions
    LISTE_ACTIONS->afficher(m_window);

    //Affichage robot
    m_robot->afficher(window);

    //affichages des textes
    for(auto a : m_texts)
    {
        window.draw(a.second->text());
    }

    //affichages des boutons
    for(auto a : m_boutons)
    {
        a.second->afficher(window);
    }


    //affichage des actions dans les programmes
    if(MAIN->getNombre() > 0)
    {
        for(int i = 0; i < MAIN->getNombre(); i++)
        {
            window.draw(MAIN->getActions().at(i)->getSprite());

        }
    }
    if(P1->getNombre() > 0)
    {
        for(int i = 0; i < P1->getNombre(); i++)
        {
            window.draw(P1->getActions().at(i)->getSprite());

        }
    }
    if(P2->getNombre() > 0)
    {
        for(int i = 0; i < P2->getNombre(); i++)
        {
            window.draw(P2->getActions().at(i)->getSprite());

        }
    }


    //si fini, on affiche l'écran de fin
    if(fini)
    {
        window.draw(FIN_NIVEAU);
    }
}

void AppliTableau::mouse_button_pressed()
{
    std::cout << m_mouse.x << " " << m_mouse.y << std::endl;

    //AVANCER
    if(m_mouse.x>=10 && m_mouse.x <= 60 && m_mouse.y >=675 && m_mouse.y<=725)
    {
        std::cout << "AVANCER" << std::endl;

        LISTE_ACTIONS->setAction(LISTE_ACTIONS->getTabActions(),0);
    }
    //INTERAGIR

    if(m_mouse.x >= 70 && m_mouse.x <= 120 && m_mouse.y >=675 && m_mouse.y<=725)
    {
        std::cout << "INTERAGIR" << std::endl;

        LISTE_ACTIONS->setAction(LISTE_ACTIONS->getTabActions(),1);
    }
    //TOURNERDROITE

    if(m_mouse.x >= 130 && m_mouse.x <= 180 && m_mouse.y >=675 && m_mouse.y<=725)
    {
        std::cout << "TOURNERDROITE" << std::endl;

        LISTE_ACTIONS->setAction(LISTE_ACTIONS->getTabActions(),2);
    }
    //TOURNDERGAUCHE

    if(m_mouse.x >= 190 && m_mouse.x <= 240 && m_mouse.y >=675 && m_mouse.y<=725)
    {
        std::cout << "TOURNDERGAUCHE" << std::endl;

        LISTE_ACTIONS->setAction(LISTE_ACTIONS->getTabActions(),3);
    }
    //SAUTER

    if(m_mouse.x >= 250 && m_mouse.x <= 300 && m_mouse.y >=675 && m_mouse.y<=725)
    {
        std::cout << "SAUTER" << std::endl;

        LISTE_ACTIONS->setAction(LISTE_ACTIONS->getTabActions(),4);
    }
    //P1

    if(m_mouse.x >= 310 && m_mouse.x <= 360 && m_mouse.y >=675 && m_mouse.y<=725)
    {
        std::cout << "P1" << std::endl;
        LISTE_ACTIONS->setAction(LISTE_ACTIONS->getTabActions(),5);
    }
    //P2

    if(m_mouse.x >= 370 && m_mouse.x <= 420 && m_mouse.y >=675 && m_mouse.y<=725)
    {
        std::cout << "P2" << std::endl;

        LISTE_ACTIONS->setAction(LISTE_ACTIONS->getTabActions(),6);
    }


    //DANS MAIN
    if(m_mouse.x >= 850 && m_mouse.x <= 1150 && m_mouse.y >= 650 && m_mouse.y <= 950)
    {
        std::cout << "main" << std::endl;
        //si le nombre dactions < nombre max
        if(MAIN->getNombre() < MAIN->getMaxAction() && LISTE_ACTIONS->onASelect())
        {
            std::cout << "ajout dans main : action numero " << MAIN->getNombre() << std::endl;
            MAIN->ajouter_action(LISTE_ACTIONS);
            MAIN->placerSpriteDansProg("main",MAIN->getNombre());
            MAIN->setNombre(MAIN->getNombre()+1);
        }
        if(MAIN->getNombre() >= MAIN->getMaxAction())
        {
            std::cout << "trop d'actions dans le main" << std::endl;
        }
        if(!LISTE_ACTIONS->onASelect())
        {
            std::cout << "Aucune action selectionnée" << std::endl;
        }
    }
    //DANS P1
    if(m_mouse.x >= 0 && m_mouse.x <= 300 && m_mouse.y >= 800 && m_mouse.y <= 950)
    {
        std::cout << "P1" << std::endl;
        //si le nombre dactions < nombre max
        if(P1->getNombre() < P1->getMaxAction() && LISTE_ACTIONS->onASelect())
        {
            std::cout << "ajout dans main : action numero " << P1->getNombre() << std::endl;
            P1->ajouter_action(LISTE_ACTIONS);
            P1->placerSpriteDansProg("p1",P1->getNombre());
            P1->setNombre(P1->getNombre()+1);
        }
        if(P1->getNombre() >= P1->getMaxAction())
        {
            std::cout << "trop d'actions dans le P1" << std::endl;
        }
        if(!LISTE_ACTIONS->onASelect())
        {
            std::cout << "Aucune action selectionnée" << std::endl;
        }
    }
    //DANS P2
    if(m_mouse.x >= 400 && m_mouse.x <= 700 && m_mouse.y >= 800 && m_mouse.y <= 950)
    {
        std::cout << "main" << std::endl;
        //si le nombre dactions < nombre max
        if(P2->getNombre() < P2->getMaxAction() && LISTE_ACTIONS->onASelect())
        {
            std::cout << "ajout dans main : action numero " << P2->getNombre() << std::endl;
            P2->ajouter_action(LISTE_ACTIONS);
            P2->placerSpriteDansProg("p2",P2->getNombre());
            P2->setNombre(P2->getNombre()+1);
        }
        if(P2->getNombre() >= P2->getMaxAction())
        {
            std::cout << "trop d'actions dans le P2" << std::endl;
        }
        if(!LISTE_ACTIONS->onASelect())
        {
            std::cout << "Aucune action selectionnée" << std::endl;
        }
    }

    //si souris dans fin
    if(m_boutons.at("fin")->contient(m_mouse))
    {
        stop();
    }

    //si souris dans lancer
    if(m_boutons.at("lancer")->contient(m_mouse))
    {

        std::cout << "LANCER PROGRAMME" << std::endl;
            if(MAIN->getNombre()>0)
            {
                //on set les rep
                P1->maxRep();
                P2->maxRep();

                //on execute le main
                MAIN->executer(m_robot, MAIN, P1, P2, 0, fini,m_window);

                //le niveau est-il fini ?
                est_fini();
                if(fini)
                {
                    //affichage du sprite de fin
                    m_window.draw(FIN_NIVEAU);
                    m_window.display();

                    //pause
                    sleep(2);

                    //passe a non fini
                    fini = false;

                    //clear des programmes
                    MAIN->clear();
                    P1->clear();
                    P2->clear();


                    std::cout << "NUMERO DE FICHIER" <<numeroNiveau<< std::endl;

                    if(est_fic_editeur && numeroNiveau<5)
                    {

                        ChangementFenetre::allerJeu(m_window,numeroNiveau,est_fic_editeur);
                        numeroNiveau++;

                    }
                    else if(!est_fic_editeur && numeroNiveau<10)
                    {

                        ChangementFenetre::allerJeu(m_window,numeroNiveau-5,est_fic_editeur);
                        numeroNiveau++;

                    }
                    else if(!est_fic_editeur && numeroNiveau==10)
                    {

                        ChangementFenetre::allerChoixNiveau(m_window,false);
                        numeroNiveau++;

                    }


                }
                else
                {
                    m_robot->reinitialiser();
                }
            }
    }

    //si souris dans retour
    if(m_boutons.at("retour")->contient(m_mouse))
    {
        std::cout << "RETOUR CHOIX NIVEAU" << std::endl;
        ChangementFenetre::allerChoixNiveau(m_window,est_fic_editeur);
    }

    //si souris dans delete main alors on nettoie le main
    if(m_boutons.at("deleteMain")->contient(m_mouse))
    {
        std::cout << "CLEAR DU MAIN" << std::endl;
        MAIN->clear();
    }

    //si souris dans delete p1 alors on nettoie le p1
    if(m_boutons.at("deleteP1")->contient(m_mouse))
    {
        std::cout << "CLEAR DU P1" << std::endl;
        P1->clear();
    }

    //si souris dans delete p2 alors on nettoie le p2
    if(m_boutons.at("deleteP2")->contient(m_mouse))
    {
        std::cout << "CLEAR DU P2" << std::endl;
        P2->clear();
    }
    //si souris dans supp P1 alors on delete la derniere action de p1
    if(m_boutons.at("suppP1")->contient(m_mouse))
    {
        std::cout << "DELETE DERNIERE ACTION P1" << std::endl;
        P1->deleteAction();
    }

    //si souris dans supp P2 alors on delete la derniere action de p2
    if(m_boutons.at("suppP2")->contient(m_mouse))
    {
        std::cout << "DELETE DERNIERE ACTION P2" << std::endl;
        P2->deleteAction();
    }

    //si souris dans supp main alors on delete la derniere action de main
    if(m_boutons.at("suppMain")->contient(m_mouse))
    {
        std::cout << "DELETE DERNIERE ACTION MAIN" << std::endl;
        MAIN->deleteAction();
    }
}


void AppliTableau::mouse_button_released(){
}

void AppliTableau::mouse_moved()
{

}

void AppliTableau::key_pressed(const sf::Event::KeyEvent &event)
{
    if(event.code == sf::Keyboard::Q)
    {
        stop();
    }
}
