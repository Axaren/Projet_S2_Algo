#ifndef BARREACTION_H
#define BARREACTION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Actions.h"

class BarreAction
{
public:
    BarreAction(sf::Vector2f position);
    void dessinerBarre(sf::RenderWindow *window);
    sf::Vector2f position(int i);
    int NombreActions();
    sf::Vector2f position_barre();
    sf::Vector2f Taille_barre();
    Actions &typeaction(int i);
private :
    std::vector<Actions *> m_actions;
    sf::RectangleShape m_rect;
    sf::Vector2f m_position;
};


#endif // BARREACTION_H
