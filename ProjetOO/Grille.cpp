#include "Grille.h"

Grille::~Grille()
{
    for (auto n : m_cases)
        delete n;
}

Grille::Grille()
    :
      m_robot{nullptr}
{
    for (int i = 0; i < LIGNES;i++)
    {
        for(int j = 0; j < COLONNES; j++)
        {
            Case* c = new Case(Etat::Vide,sf::Vector2i(j,i));
            m_cases.push_back(c);
        }
    }
}

void Grille::dessiner (sf::RenderWindow *window) // Pour chaque case du tableau on dessine une case
{


    for (Case * c : m_cases)
    {
        c->draw_on(window);
    }

    m_robot->dessiner(window);

}

Case* Grille::get_case(sf::Vector2i position)
{
    bool found = false;
    unsigned int i = 0;
    while (!found && i < m_cases.size() - 1 )
    {
        if (m_cases.at(i)->get_position() == position)
        {
            found = true;
        }
        else
            i++;
    }
    if (found)
    return m_cases.at(i);
    else
        return nullptr;
}

void Grille::TraiterAction(Actions *next_action)
{
            sf::Vector2i position_initiale = m_robot->get_position();
    switch (next_action->get_etat())
    {
    case Avancer:
        m_robot->avancer();

        if (get_case(m_robot->get_position())->get_etat() == Etat::Vide || get_case(m_robot->get_position()))
            m_robot->set_position(position_initiale);

        break;
    case Tourner_Droite:
        m_robot->tourner(true);
        break;
    case Tourner_Gauche:
        m_robot->tourner(false);
        break;
    case Allumer:
        if (get_case(m_robot->get_position())->get_etat() == Allumee)
            get_case(m_robot->get_position())->set_etat(Eteinte);
        else
            get_case(m_robot->get_position())->set_etat(Allumee);
        break;
    }
}
