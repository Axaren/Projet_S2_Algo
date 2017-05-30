#ifndef GRILLE_H
#define GRILLE_H
#include "Cases.h"
#include <iostream>
#include <array>
#include "Robot.h"
#include <fstream>
#include "Etats_Cases.h"
#include "Actions.h"

static const int COLONNES = 10;
static const int LIGNES = 8;

class Grille
{
private:
    std::vector<Case*> m_cases;
    Robot * m_robot;

public:
    Grille();
    Case* get_case(sf::Vector2i position);
    void dessiner(sf::RenderWindow *window);
    void SauvegarderGrille(std::string nomFic);
    void TraiterAction(Actions * next_action);
     ~Grille();
};


#endif // GRILLE_H
