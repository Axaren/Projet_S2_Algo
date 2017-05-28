#ifndef GRILLE_H
#define GRILLE_H
#include "Cases.h"
#include <iostream>
#include <array>
#include "Robot.h"
#include <fstream>
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
    void set_robot(Robot* r);
    void set_robot(sf::Vector2i position, int direction);
    ~Grille();
    void set_case(sf::Vector2i position, Etat e);
};


#endif // GRILLE_H
