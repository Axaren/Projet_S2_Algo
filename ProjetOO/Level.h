#ifndef LEVEL_H
#define LEVEL_H

#include "Grille.h"
#include "Proc.h"

class Level
{
    Grille * m_grille;
    Proc * m_main;
    Proc * m_p1;
    Proc * m_p2;
public:
    Level();
    void LoadLevel(std::string filename);
    void SaveLevel();
    void TraiterActions();
    void Dessiner(sf::RenderWindow * window);
    void ExecuterP2();
    void ExecuterP1();
};

#endif // LEVEL_H
