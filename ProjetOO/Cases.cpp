#include "Cases.h"

Case::Case(Etat etat, sf::Vector2i position)
    :
      m_position {position},
      m_etat {etat}
{

    m_hexagone.setOutlineThickness(1.);
    m_hexagone.setFillColor(sf::Color::Transparent);
    m_hexagone.setRadius(RAYON_HEXAGONE);

    if (position.y %2 == 1)
        m_hexagone.setPosition(m_position.x*RAYON_HEXAGONE*1.75+RAYON_HEXAGONE-4,m_position.y*RAYON_HEXAGONE*1.5);
    else
        m_hexagone.setPosition(m_position.x*RAYON_HEXAGONE*1.75,m_position.y*RAYON_HEXAGONE*1.5);

    m_hexagone.setPointCount(6);

    switch(m_etat) // La case a une couleur différente en fonction du tableau passé en paramétre

    {
    case Allumee:
        m_hexagone.setFillColor(sf::Color::Green);
        break;
    case Eteinte:
        m_hexagone.setFillColor(sf::Color::Red);
        break;
    case Vide:
        m_hexagone.setFillColor(sf::Color::Transparent);
        break;
    case Normale:
        m_hexagone.setFillColor(sf::Color::Blue);
        break;
    default:
        break;

    }
}

void Case::draw_on(sf::RenderWindow *window)
{
    window->draw(m_hexagone);
}

sf::Vector2i Case::get_position() const
{
    return m_position;
}

void Case::set_position(sf::Vector2i position)
{
    m_position = position;
}

Etat Case::get_etat() const
{
    return m_etat;
}

void Case::set_etat(Etat e)
{
    m_etat = e;
    if (m_etat == Etat::Vide)
        m_hexagone.setFillColor(sf::Color::Blue);
    else if (m_etat == Etat::Allumee)
        m_hexagone.setFillColor(sf::Color::Green);
    else if(m_etat == Etat::Eteinte)
        m_hexagone.setFillColor(sf::Color::Red);
    else
        m_hexagone.setFillColor(sf::Color::Transparent);
}

