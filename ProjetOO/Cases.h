#ifndef CASES_H
#define CASES_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Etats_Cases.h"

const float RAYON_HEXAGONE = 30;

class Case
{
public:
    Case(Etat, sf::Vector2i position);
    void draw_on(sf::RenderWindow *window);

    sf::Vector2i get_position() const;
    void set_position(sf::Vector2i position);

    void set_etat(Etat);
    Etat get_etat() const;
private :
    sf::CircleShape m_hexagone;
    sf::Vector2i m_position;
    Etat m_etat;

};

#endif // CASES_H
