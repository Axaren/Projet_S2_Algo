#ifndef Hexabot_H
#define Hexabot_H
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "vector"
#include "Application.h"
#include "BarreAction.h"
#include "BoutonSimple.h"
#include "Level.h"

enum TypeJeu {MENU, JEU, QUITTER, VICTOIRE};
enum EtatSouris {DEPLACEMENT, INITIAL, FINAL, AJOUT};

const int NOMBRE_NIVEAUX = 2;

class Hexabot : public Application
{

public:

    Hexabot();          // à personnaliser éventuellement
    ~Hexabot();
    void init() override;
    void ChargerNiveaux();
    void loop() override;
    bool souris_dans_Proc(Proc * proc) const;
    bool souris_dans_BarreAction(BarreAction *barre) const;
    Actions  num_action(const Position &p);
    sf::Vector2i position_grille_case(const Position &p, Proc *proc);
    void dessiner_type_memoire();
    void dessiner_bouton();
    bool souris_dans_bouton(BoutonSimple *bouton);
    void dessiner_bouton_menu();
private:

    std::vector<Level*> m_niveaux;

    BoutonSimple * play,*arret,*vider, *play_menu,* quitter , *quitter_menu;
    // les fonctions et variables utilisables
    void stop();
    float mouseX, mouseY;
    int LIGNE_PROC1 = 3 ;
    int COLONNE_PROC1 = 5;
    int button;
    Proc * m_proc_temp;

    Actions* type_memoire;

    sf::Sprite background;

    TypeJeu jeu; // Etat du jeu

    sf::Event event;

    sf::Vector2i m_appui,m_relache;

    BarreAction * barre;

    Position m_position;

    EtatSouris etat;

        // les fonctions à fournir
     void mouse_button_pressed() override ;
     void mouse_button_released() override ;
     void mouse_moved() override ;
     void mouse_Dragged() override ;

    };

#endif // Hexabot_H

