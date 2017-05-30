#include "Level.h"

Level::Level()
    :
      m_grille{nullptr},
      m_main{nullptr},
      m_p1{nullptr},
      m_p2{nullptr}
{
}

void Level::Dessiner(sf::RenderWindow *window)
{
    m_grille->dessiner(window);
    m_main->dessiner(window);
    m_p1->dessiner(window);
    m_p2->dessiner(window);
}

void Level::TraiterActions()
{
    for (Actions* a : m_main->get_actions())
    {
        switch (a->get_etat()) {
        case P1:
            ExecuterP1();
            break;
        case P2:
            ExecuterP2();
            break;
        case Avancer:
        case Tourner_Droite:
        case Tourner_Gauche:
        case Allumer:
            m_grille->TraiterAction(a);
            break;
        default:
            break;
        }
    }
}

void Level::ExecuterP1()
{
    for (Actions* a : m_p1->get_actions())
    {
        switch (a->get_etat()) {
        case P1:
            ExecuterP1();
            break;
        case P2:
            ExecuterP2();
            break;
        case Avancer:
        case Tourner_Droite:
        case Tourner_Gauche:
        case Allumer:
            m_grille->TraiterAction(a);
            break;
        default:
            break;
        }
    }
}

void Level::ExecuterP2()
{
    for (Actions* a : m_p1->get_actions())
    {
        switch (a->get_etat()) {
        case P1:
            ExecuterP1();
            break;
        case P2:
            ExecuterP2();
            break;
        case Avancer:
        case Tourner_Droite:
        case Tourner_Gauche:
        case Allumer:
            m_grille->TraiterAction(a);
            break;
        default:
            break;
        }
    }
}

