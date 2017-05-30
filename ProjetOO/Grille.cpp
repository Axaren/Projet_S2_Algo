#include "Grille.h"

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

}

Case* Grille::get_case(sf::Vector2i position)
{
    bool found = false;
    int i = 0;
    while (!found && i < m_cases.size() - 1 )
    {
        if (m_cases.at(i)->get_position() == position)
        {
            found = true;
        }
        else
            i++;
    }
    return m_cases.at(i);
}

void Grille::TraiterAction(Actions *next_action)
{
    switch (next_action->get_etat())
    {
    case Avancer:
        m_robot->avancer();
        break;
    case Tourner_Droite:
        m_robot->tourner(true);
        break;
    case Tourner_Gauche:
        m_robot->tourner(false);
        break;
    case Allumer:
        break;
    }
}
