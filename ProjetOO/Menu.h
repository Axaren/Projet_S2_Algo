#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Application.h"


class Menu
{
public:
    Menu();

    bool souris_dans_rectangle(const Position &coin, const Position &dims) const;
    void bouton_menu();
private :
    sf::RectangleShape m_rect;
};

#endif // MENU_H
