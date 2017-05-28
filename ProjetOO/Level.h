#ifndef LEVEL_H
#define LEVEL_H

#include "TinyXML2/tinyxml2.h"
#include "Grille.h"
#include "Proc.h"
#include <sstream>

const std::string CHEMIN_NIVEAUX = "/home/nlesne/IUT/lightbotMieux/Niveaux/";

class Level
{
    Grille * m_grille;
    Proc * m_main;
    Proc * m_p1;
    Proc * m_p2;

    void ExecuterP2();
    void ExecuterP1();

public:
    Level();
    bool LoadLevel(std::string filename);
    void SaveLevel();
    void TraiterActions();
    void Dessiner(sf::RenderWindow * window);
};

#endif // LEVEL_H
