#include "AppliEditeur.h"
#include<iostream>
AppliEditeur::AppliEditeur(sf::RenderWindow &window, int numero_niveau)
    : Application(window)
    ,numero_de_niveau{numero_niveau}
{
    m_window.setTitle("Editeur");

    //init grile
    for(int i = 0 ; i<=9;i++)
    {
        m_x_temp=m_position_x;
        m_y_temp=m_position_y;
        if(i%2==0)
        {
            if(i!=0)
            {
                reinitialiser();
                avancer_y((3*i/2)*RAYON_CASES_EDITEUR);

            }
        }
        else
        {
            reinitialiser_impair();
            if(i!=1)
            {

                avancer_y(((i/2)*3)*RAYON_CASES_EDITEUR);


            }



        }
        for(int j = 0 ; j<=9 ; j++)
        {
            avancer_x(sqrt(3)*RAYON_CASES_EDITEUR);
            m_grille[i][j]=new CasesEditeur({m_x_temp,m_y_temp});

        }

    }

    //ouverture fichiers
    std::string fichier = "SauvegardeNiveau"+std::to_string(numero_de_niveau)+".txt";
    std::fstream f;
    f.open( fichier.c_str(), std::ios::in );
    if( f.fail() )
    {
        std::cerr << "ouverture en lecture impossible" << std::endl;
        exit(EXIT_FAILURE);
    }

    //affecte les valeurs du fichier a la grille
    f>>m_dir;
    int x=0;
    int y = 0;
    int k=0;

    for( int i=0; i<10; i++ )
        for( int j=0; j<10; j++ )
        {
            f>>x;
            f>>y;
            f>>k;
            m_grille[x][y]->set_etage(k);
            f>>k;
            if(k==1)
                m_grille[x][y]->set_activer();
            f>>k;
            if(k==1)
            {
                debut_choisi=true;
                m_grille[x][y]->definir_debut();
            }
            f>>k;
            if(k==1)
                m_grille[x][y]->definir_allumable();

        }

    f.close();

    //init boutons
    m_boutons["start"] = new Bouton(20,800,50.,50.,"data/lancer.png");
    m_boutons["aug"] = new Bouton(20,600,50.,50.,"data/monter.png");
    m_boutons["des"] = new Bouton(20,400,50.,50.,"data/descendre.png");
    m_boutons["allumer"] = new Bouton(20,200,50.,50.,"data/allumer.png");
    m_boutons["fin"] = new Bouton(1100,900,50.,50.,"data/fin.png");
    m_boutons["retour"] = new Bouton(1000,25,50.,50.,"data/retourchoix.png");
    m_boutons["save"] = new Bouton(20,900,50.,50.,"data/sauver.png");
    m_boutons["robo"] = new Bouton(20,100,50.,50.,"data/northeast.png");


}

AppliEditeur::~AppliEditeur()
{

    //delete de la grille
    for(int i=0;i<=9;i++)
    {
        for(int j =0 ;j<=9 ;j++)
        {
            delete m_grille[i][j];
        }

    }

    //Delete des boutons
    for(auto a  :m_boutons)
    {
        delete a.second;
    }
}

void AppliEditeur::draw()
{

    //affichage des boutons
    for(auto a : m_boutons)
    {
        a.second->afficher(m_window);
    }

    //affichage de la grille
    for(int i = 0 ; i<=9;i++)
    {


        for(int j = 0 ; j<=9 ; j++)
        {
            m_grille[i][j]->afficher(m_window);

        }

    }
}

void AppliEditeur::loop()
{
    //clear window
    m_window.clear(sf::Color(229,229,229));

    //affichage de la grille (qui est déjà dans draw, lol)
    for(int i=0;i<=9;i++)
    {
        for(int j =0 ;j<=9 ;j++)
        {
            m_grille[i][j]->afficher(m_window);

        }
    }

    //affichage
    draw();
    m_window.display();
}

void AppliEditeur::mouse_button_pressed()
{
    //permet de savoir dans quelle case on est
    int x = 0;
    int y = 0;
    int plus_petite_distance=2000;
    Position p = {511,511};
    for(int i=0;i<=9;i++)
    {
        for(int j =0 ;j<=9 ;j++)
        {
            if(m_grille[i][j]->contains({m_mouse})<plus_petite_distance)
            {
                plus_petite_distance=m_grille[i][j]->contains({m_mouse});
                x=i;
                y=j;
            }
        }

    }
    //si souris dans changer direc
    if(m_boutons.at("robo")->contient(m_mouse))
    {
        m_dir++;
        if(m_dir>5)
            m_dir=0;
        switch(m_dir)
        {
        case 0:
            m_boutons.at("robo")->changer_sprite("data/northeast.png");
            break;
        case 1:
            m_boutons.at("robo")->changer_sprite("data/east.png");
            break;
        case 2:
            m_boutons.at("robo")->changer_sprite("data/southeast.png");
            break;
        case 3:
            m_boutons.at("robo")->changer_sprite("data/southwest.png");
            break;
        case 4:
            m_boutons.at("robo")->changer_sprite("data/west.png");
            break;
        case 5:
            m_boutons.at("robo")->changer_sprite("data/northwest.png");
            break;
        }

    }
    //si souris dans start
    if(m_boutons.at("start")->contient(m_mouse))
    {
        if(col==SELEC_DEBUT)
            col=INITIAL;
        else
        {
            col=SELEC_DEBUT;
        }
    }

    //si souris dans augmenter niveau
    if(m_boutons.at("aug")->contient(m_mouse))
    {
        if(col==SELECT_ETAGE)
            col=INITIAL;
        else
        {
            col=SELECT_ETAGE;
        }
    }

    //si souris dans descendre niveau
    if(m_boutons.at("des")->contient(m_mouse))
    {
        if(col==SELECT_ETAGE_MOINS)
            col=INITIAL;
        else
        {
            col=SELECT_ETAGE_MOINS;
        }
    }

    //si souris dans allumer case
    if(m_boutons.at("allumer")->contient(m_mouse))
    {
        if(col==SELEC_CASES_ALLU)
            col=INITIAL;
        else
        {
            col=SELEC_CASES_ALLU;
        }
    }

    //si souris dans fin
    if(m_boutons.at("fin")->contient(m_mouse))
    {
        stop();
    }

    //si souris dans retour
    if(m_boutons.at("retour")->contient(m_mouse))
    {
        std::cout << "RETOUR MENU" << std::endl;
        stop();
        ChangementFenetre::allerTransition(m_window);
    }

    //si souris dans save
    if(m_boutons.at("save")->contient(m_mouse))
    {
        sauvegarde("SauvegardeNiveau"+std::to_string(numero_de_niveau)+".txt");
    }

    //selon col on agit : activer une case, mettre une case init, allumer case etc...
    switch (col)
    {
    case INITIAL:
        if(plus_petite_distance<=30)
        {

         m_grille[x][y]->activer(debut_choisi);
        }

        break;
    case SELEC_DEBUT:
        if(plus_petite_distance<=30)
        {
            if(debut_choisi==true)
            {
                if(m_grille[x][y]->est_debut()==true && m_grille[x][y]->est_active()==true )
                {
                    m_grille[x][y]->definir_debut();
                    debut_choisi=false;
                }
            }
            else if(m_grille[x][y]->est_active()==true)
            {
                m_grille[x][y]->definir_debut();
                debut_choisi=true;

            }

        }
        break;
    case SELECT_ETAGE:
        if(plus_petite_distance<=30 && m_grille[x][y]->est_active())
            m_grille[x][y]->ajouter_etage();
        break;
    case SELECT_ETAGE_MOINS:
        if(plus_petite_distance<=30 && m_grille[x][y]->est_active())
            m_grille[x][y]->enlever_etage();
            break;
    case SELEC_CASES_ALLU:
        if(plus_petite_distance<=30 && m_grille[x][y]->est_active())
        {
            m_grille[x][y]->definir_allumable();
        }


    }






}

void AppliEditeur::mouse_button_released()
{

}

void AppliEditeur::mouse_moved()
{

}

void AppliEditeur::key_pressed(const sf::Event::KeyEvent &event)
{

}
int AppliEditeur::avancer_x(int xplus)
{
    m_x_temp+=xplus;
}

int AppliEditeur::avancer_y(int yplus)
{

    m_y_temp+=yplus;
}

void AppliEditeur::reinitialiser()
{
    m_x_temp=m_position_x;
    m_y_temp=m_position_y;

}

void AppliEditeur::reinitialiser_impair()
{
    m_x_temp=m_position_x;
    m_y_temp=m_position_y;
    m_y_temp+=RAYON_CASES_EDITEUR + 0.5*RAYON_CASES_EDITEUR;
    m_x_temp+=sqrt(3)*RAYON_CASES_EDITEUR/2;
//    avancer_y(RAYON_CASES_EDITEUR + 0.5*RAYON_CASES_EDITEUR);
//    avancer_x(sqrt(3)*RAYON_CASES_EDITEUR/2);

}

void AppliEditeur::sauvegarde(std::string fichier)
{
    std::fstream f;
    f.open(fichier.c_str(), std::ios::out);
    if( f.fail() )
    {
        std::cerr << "ouverture en ecriture impossible" << std::endl;
        exit(EXIT_FAILURE);
    }

    f<<std::to_string(m_dir)+"\n";
    for(int i=0;i<=9;i++)
    {
        for(int j =0 ;j<=9 ;j++)
        {

            f << std::to_string(i) +" " +std::to_string(j)+" "+ m_grille[i][j]->to_string();

        }

    }
    f.close();
}
