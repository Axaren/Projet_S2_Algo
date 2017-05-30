#ifndef Hexabot_H
#define Hexabot_H
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "vector"
#include "Robot.h"
#include "Cases.h"
#include "Grille.h"
#include "Proc.h"
#include "Application.h"
#include "BarreAction.h"
#include "Image.h"
#include "BoutonSimple.h"

enum TypeJeu {MENU, JEU, QUITTER, VICTOIRE};
enum EtatSouris {DEPLACEMENT, INITIAL, FINAL, AJOUT};


class Hexabot : public Application
{

public:

    Hexabot();          // à personnaliser éventuellement
    ~Hexabot();
    void init() override;

    void loop() override;
    void DessinerProc();
    bool souris_dans_Proc(Proc * proc) const;
    bool souris_dans_BarreAction(BarreAction *barre) const;
    Actions  num_action(const Position &p);
    sf::Vector2i position_grille_case(const Position &p, Proc *proc);
    void dessiner_type_memoire();
    void dessiner_bouton();
    bool souris_dans_bouton(BoutonSimple *bouton);
    void dessiner_bouton_menu();
private:

    BoutonSimple * play,*arret,*vider, *play_menu,* quitter , *quitter_menu;
    // les fonctions et variables utilisables
    void stop();
    float mouseX, mouseY;
    int LIGNE_PROC1 = 3 ;
    int COLONNE_PROC1 = 5;
    int button;
    Proc * m_proc_temp;
    Image m_image;

    Actions* type_memoire,* type_memoire2;
    sf::Sprite background;

    //sf::Texture image;

    TypeJeu jeu; // Etat du jeu

    float m_x , m_y;

    Proc * m_proc,* m_proc1, *m_proc2;
    sf::Event event;

    Grille * m_grille;
    sf::Vector2i appuie;

    BarreAction * barre;

    Position m_position;
    EtatSouris etat;

    sf::RectangleShape m_rectangle;


        // les fonctions à fournir
     void mouse_button_pressed() override ;
     void mouse_button_released() override ;
     void mouse_moved() override ;
     void mouse_Dragged() override ;

    };

#endif // Hexabot_H

