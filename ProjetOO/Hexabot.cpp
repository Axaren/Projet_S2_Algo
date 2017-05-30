#include "Hexabot.h"


const int HAUTEUR = 500;
const int LARGEUR= 850;

Hexabot::Hexabot()
    :Application(LARGEUR,HAUTEUR,L"Hexabot")
{
    m_grille = new Grille();
    m_proc = new Proc({LARGEUR-40*7,HAUTEUR-40*12},LIGNE_PROC1,COLONNE_PROC1);
    m_proc1 = new Proc({LARGEUR-40*7,HAUTEUR-40*7.9},2,5);
    m_proc2 = new Proc({LARGEUR-40*7,HAUTEUR-40*5},2,5);
    barre = new BarreAction({LARGEUR-50*12,HAUTEUR-50});
    play = new BoutonSimple({(LARGEUR/2)-200,HAUTEUR-110},PLAY);
    arret = new BoutonSimple({(LARGEUR/2)-60,HAUTEUR-113},ARRET);
    vider = new BoutonSimple({550,HAUTEUR-50},VIDER);
    play_menu  = new BoutonSimple({LARGEUR/2-60,HAUTEUR/2-40},PLAY_MENU);
    quitter_menu = new BoutonSimple({LARGEUR/2-60,HAUTEUR/2+40},QUITTER_MENU);
    quitter = new BoutonSimple({60,HAUTEUR-50},QUITTER_JEU);

}

Hexabot::~Hexabot()
{
    delete barre;
    delete m_proc;
    delete m_proc1;
    delete m_proc2;
    delete m_proc_temp;
    delete play;
    delete arret;
    delete vider;
    delete play_menu;
    delete quitter_menu;
    delete quitter;
    delete  m_grille;
            delete m_window;
}

void Hexabot::init()
{
    sf::Texture image_background;
    if (image_background.loadFromFile("Sprites/galaxy.png"))
    {
        background.setTexture(image_background);
    }
    else
        std::cerr << "Chemin image non valide !" << std::endl;
    //    if (!image.loadFromFile("Sprites/Button.png"))
    //    {
    //       std::cerr << "Chemin invalide vers bouttons" << std::endl;
    //       EXIT_SUCCESS;
    //    }
    m_image.chargerImage();
    jeu=MENU;
}


void Hexabot::loop()
{


    m_window->clear(); // On clear l'image
    if (jeu == JEU)
    {
        m_grille->dessiner(m_window); // On dessine la grille
        dessiner_bouton(); // On dessine les boutons
        DessinerProc(); // On dessine les procs
        if (etat==AJOUT) // Si état ajout on dessine l'action séléctionner
        {
            dessiner_type_memoire();
        }
    }
    else if (jeu == MENU)
    {
        dessiner_bouton_menu();

    }
    m_window->display();

}

void Hexabot::DessinerProc() // Dessine les proc et la barre de séléction des actions
{
    m_proc->dessiner(m_window);
    m_proc1->dessiner(m_window);
    m_proc2->dessiner(m_window);
    barre->dessinerBarre(m_window);
}

void Hexabot::dessiner_type_memoire() // Fonction qui affiche l'action sous la souris quand on ajoute une action depuis la barre de séléction
{
    type_memoire->position_Ajout(m_position);
    type_memoire->afficher(m_window);
}

Actions Hexabot::num_action(const Position & p) // Fonction qui renvoie la position de l'action dans la barre de séléction des actions
{
    auto d = p-barre->position_barre();
    return barre->typeaction(d.x/50);
}

sf::Vector2i Hexabot::position_grille_case(const Position & p, Proc * proc) // Fonction qui renvoie la position de l'action dans un proc
{
    auto d = p-proc->Position_CH();
    return {d.x/50,d.y/50};

}

//*********************************GESTION DES CLICS**************************************

void Hexabot::mouse_button_pressed()
{
    if (jeu==JEU)

    {

        if (souris_dans_BarreAction(barre) && !souris_dans_Proc(m_proc))
        {
            etat = AJOUT;
            type_memoire = new Actions(num_action(m_mouse));

        }
        else if (etat ==AJOUT && (souris_dans_Proc(m_proc)|| souris_dans_Proc(m_proc1)|| souris_dans_Proc(m_proc2)))
        {
            etat = AJOUT;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && souris_dans_Proc(m_proc))
        {
            etat=DEPLACEMENT;
            appuie=position_grille_case(m_mouse,m_proc);
            type_memoire2 = m_proc->action_de_la_case(appuie);
            m_proc_temp = m_proc;
            std::cout << "proc" << appuie.x << ";" << appuie.y << std::endl;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && souris_dans_Proc(m_proc1))
        {
            etat=DEPLACEMENT;
            appuie=position_grille_case(m_mouse,m_proc1);
            type_memoire2 = m_proc1->action_de_la_case(appuie);
            m_proc_temp = m_proc1;
            std::cout << "proc1" << appuie.x << ";" << appuie.y << std::endl;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && souris_dans_Proc(m_proc2))
        {
            etat=DEPLACEMENT;
            appuie=position_grille_case(m_mouse,m_proc2);
            type_memoire2 = m_proc2->action_de_la_case(appuie);
            m_proc_temp = m_proc2;
            std::cout << "proc2" << appuie.x << ";" << appuie.y << std::endl;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && souris_dans_Proc(m_proc) && etat != AJOUT)
        {
            appuie = position_grille_case(m_mouse,m_proc);
            m_proc->supprimer_action(appuie);
            std::cout << appuie.x << " "<<appuie.y << std::endl;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && souris_dans_Proc(m_proc1))
        {
            appuie = position_grille_case(m_mouse,m_proc1);
            m_proc1->supprimer_action(appuie);
            std::cout << appuie.x << " "<<appuie.y << std::endl;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && souris_dans_Proc(m_proc2))
        {
            appuie = position_grille_case(m_mouse,m_proc2);
            m_proc2->supprimer_action(appuie);
            std::cout << appuie.x << " "<<appuie.y << std::endl;
        }

        //***************************GESTION DES BOUTONS************************************

        else if (souris_dans_bouton(arret))
        {
            std::cout << "arret" << std::endl;
        }
        else if (souris_dans_bouton(vider))
        {
            std::cout << "vider" << std::endl;
            m_proc->vider_proc();
            m_proc1->vider_proc();
            m_proc2->vider_proc();
            m_window->display();
        }
        else if (souris_dans_bouton(play))
        {
            std::cout << "play" << std::endl;
        }
        else if (souris_dans_bouton(quitter))
        {
            jeu=MENU;
        }
        else
        {
            etat=INITIAL;
            std::cout << "rien" << std::endl;
        }
    }
    else if (jeu==MENU)
    {
        if (souris_dans_bouton(play_menu))
        {
            std::cout << "coucou" << std::endl;
            jeu=JEU;
        }
        else if (souris_dans_bouton(quitter_menu))
        {
            m_window->close();
        }
    }

}

bool Hexabot::souris_dans_Proc(Proc * proc) const // Fonction qui vérifie si la souris est dans un proc
{
    auto d = m_mouse - proc->Position_CH();
    return 0 <= d.x and d.x <= proc->Taille_proc().x and 0 <= d.y and d.y <= proc->Taille_proc().y;
}

bool Hexabot::souris_dans_BarreAction(BarreAction * barre) const // Fonction qui vérifie si la souris est dans la Barre de séléction des actions
{
    auto d = m_mouse - barre->position_barre();
    return 0 <= d.x and d.x <= barre->Taille_barre().x and 0 <= d.y and d.y <= barre->Taille_barre().y;
}

bool Hexabot::souris_dans_bouton(BoutonSimple * bouton)   // Fonction qui vérifie si la souris est dans un bouton
{
    auto d = m_mouse - bouton->position();
    return 0 <= d.x && d.x <= bouton->taille().x && 0 <= d.y && d.y <= bouton->taille().y;

}


// Bouton souris relacher


void Hexabot::mouse_button_released()
{

    //*****************AJOUT D'UNE ACTION DANS UN PROC DEPUIS LA BARRE D'ACTION*****************************


    if (etat==AJOUT && souris_dans_Proc(m_proc)) // Si etat ajout et que souris dans m_proc alors on place l'action.
    {
        m_proc->placement_action(type_memoire); // On place l'action enregistre dans type memoire a la bonne place
        // etat = INITIAL;// On repasse à l'état initial
    }
    else if (etat==AJOUT && souris_dans_Proc(m_proc1)) // Pareil qu'au dessus avec m_proc1
    {
        m_proc1->placement_action(type_memoire);
        //etat=INITIAL;
        std::cout << "marche ou pas" << std::endl;
    }
    else if (etat==AJOUT && souris_dans_Proc(m_proc2)) // Pareil qu'au dessus avec m_proc2
    {
        m_proc2->placement_action(type_memoire);
        //etat=INITIAL;
        std::cout << "marche ou pas" << std::endl;
    }

    //*************************DEPLACEMENT D'ACTION ENTRE LES PROCS****************************************


    else if (etat ==DEPLACEMENT && souris_dans_Proc(m_proc)) // Si etat est deplacement et que souris dans m_proc
    {
        if (m_proc_temp == m_proc) // si le proc on l'on a cliquer avec la souris est m_proc
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc); // On enregistre la position dans relache
            std::cout << relache.x << ";" << relache.y << std::endl;
            m_proc->echangeAction(appuie,relache); // On echange les actions présente dans la grille au position de appyuie et relache
            etat=INITIAL; // On repasse à l'état initial
        }
        else if (m_proc_temp  == m_proc1) // Si le proc on l'on a cliquer avec la souris est m_proc1
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc); // On enregistre la position dans relache
            Actions * prog_temp = m_proc->action_de_la_case(relache);  // On enregistre l'action ou l'on a relaché la souris
            m_proc->placer_action_echange(relache,type_memoire2); // On place l'action ou l'on a cliquer a la position relache
            m_proc1->placer_action_echange(appuie,prog_temp); // On place l'action ou l'on a relacher la souris a la position appuie dans le m_proc1
        }
        else if (m_proc_temp  == m_proc2) // Pareil pour m_proc2
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc);
            Actions * prog_temp = m_proc->action_de_la_case(relache);
            m_proc->placer_action_echange(relache,type_memoire2);
            m_proc2->placer_action_echange(appuie,prog_temp);
        }
    }
    else if (etat ==DEPLACEMENT && souris_dans_Proc(m_proc1)) // Pareil avec m_proc1
    {
        if (m_proc_temp == m_proc1)
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc1);
            std::cout << relache.x << ";" << relache.y << std::endl;
            m_proc1->echangeAction(appuie,relache);
            etat=INITIAL;
        }
        else if (m_proc_temp == m_proc)
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc1);
            Actions * prog_temp = m_proc1->action_de_la_case(relache);
            m_proc1->placer_action_echange(relache,type_memoire2);
            m_proc->placer_action_echange(appuie,prog_temp);
        }
        else if (m_proc_temp == m_proc2)
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc1);
            Actions * prog_temp = m_proc1->action_de_la_case(relache);
            m_proc1->placer_action_echange(relache,type_memoire2);
            m_proc2->placer_action_echange(appuie,prog_temp);
        }
    }
    else if (etat ==DEPLACEMENT && souris_dans_Proc(m_proc2)) // Pareil avec m_proc2
    {
        if (m_proc_temp == m_proc2)
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc2);
            std::cout << relache.x << ";" << relache.y << std::endl;
            m_proc2->echangeAction(appuie,relache);
            etat=INITIAL;
        }
        else if (m_proc_temp == m_proc)
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc2);
            Actions * prog_temp = m_proc2->action_de_la_case(relache);
            m_proc2->placer_action_echange(relache,type_memoire2);
            m_proc->placer_action_echange(appuie,prog_temp);
        }
        else if (m_proc_temp == m_proc1)
        {
            sf::Vector2i relache = position_grille_case(m_mouse,m_proc2);
            Actions * prog_temp = m_proc2->action_de_la_case(relache);
            m_proc2->placer_action_echange(relache,type_memoire2);
            m_proc1->placer_action_echange(appuie,prog_temp);
        }
    }
    else
    {
        std::cout << "rien" << std::endl;
    }
}

void Hexabot::mouse_moved()
{
    if (etat==DEPLACEMENT)
    {
        m_position = m_mouse;
    }
    if (etat==AJOUT)
    {
        m_position = m_mouse;

    }
}

void Hexabot::mouse_Dragged()
{
    if (etat == AJOUT)
    {
        m_position = m_mouse;
    }
}

void Hexabot::dessiner_bouton() // Fonction qui dessine tous les boutons à l'écran
{
    arret->dessiner_bouton(m_window);
    vider->dessiner_bouton(m_window);
    play->dessiner_bouton(m_window);
    quitter->dessiner_bouton(m_window);

}

void Hexabot::dessiner_bouton_menu()
{
    play_menu->dessiner_bouton(m_window);
    quitter_menu->dessiner_bouton(m_window);
}
