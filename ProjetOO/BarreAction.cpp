#include "BarreAction.h"

const sf::Vector2f Taille_Carre = {50,50};

BarreAction::BarreAction(sf::Vector2f position)
    : m_position {position}
{
    m_rect.setFillColor(sf::Color::Transparent);
    m_rect.setOutlineColor(sf::Color::White);
    m_rect.setOutlineThickness(2);
    m_rect.setSize({50,50});

    m_actions.push_back(new Actions(Tourner_Gauche));
    m_actions.push_back(new Actions(Allumer));
    m_actions.push_back(new Actions(Tourner_Droite));
    m_actions.push_back(new Actions(Avancer));
}


void BarreAction::dessinerBarre(sf::RenderWindow * window)
{
    int i = 0;
    for (auto n : m_actions)
    {
        m_rect.setPosition(position(i));
        window->draw(m_rect);

        if (n != nullptr)
        {
            n->position_sprite(i,0,m_position);
            n->afficher(window);
        }
 i++;


        //n->Image(window,m_position,i );
    }
}

int BarreAction::NombreActions()
{
    return m_actions.size();
}

sf::Vector2f BarreAction::position(int i)
{
    return {m_position.x+50*i+m_rect.getOutlineThickness(),m_position.y+m_rect.getOutlineThickness()};
}

sf::Vector2f BarreAction::Taille_barre()
{
    return {Taille_Carre.x*NombreActions(), Taille_Carre.y*NombreActions()};
}

sf::Vector2f BarreAction::position_barre()
{
    return m_position;
}

Actions & BarreAction::typeaction (int i)
{

    return * m_actions.at(i);

}

BarreAction::~BarreAction()
{
 for (auto n : m_actions)
     delete n;
}
