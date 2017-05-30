#include "Proc.h"

namespace {
constexpr int W = 600, H = 400;
constexpr float RAYON = 20.0;
constexpr float X_TEXTE = 400., Y_TEXTE = 350.;
const std::string POLICE = "ComicSansMSRegular.ttf";
const Position
DIMS_RECTANGLE {50, 25},
COIN_RECTANGLE {W-DIMS_RECTANGLE.x,H-DIMS_RECTANGLE.y*2},
DIMS_COULEUR {50,40},
COIN_PANNEAU {W-DIMS_COULEUR.x,DIMS_COULEUR.y},
DIMS_CARRE_PROC {50,50},
COIN_CARRES = DIMS_CARRE_PROC;
}



Proc::Proc(sf::Vector2f position,int TAILLE_L,int TAILLE_C)
    : m_position{position},
      m_TAILLE_L{TAILLE_L},
      m_TAILLE_C{TAILLE_C}
{
    for (int i=0; i<m_TAILLE_C*m_TAILLE_L+1;i++)
        m_actions.push_back(nullptr);
}

Proc::~Proc()
{
    for (int i=0; i<m_TAILLE_C*m_TAILLE_L+1;i++)
        delete m_actions.at(i);
}


void Proc::dessiner(sf::RenderWindow *window )
{

    m_rect2.setOutlineColor(sf::Color::White);
    m_rect2.setOutlineThickness(2);
    m_rect2.setFillColor(sf::Color::Transparent);
    m_rect2.setSize(DIMS_CARRE_PROC);
    int k =0;

    for (int i=0 ; i<m_TAILLE_L;i++)
        for (int j = 0 ; j<m_TAILLE_C; j++)
        {
            m_rect2.setPosition(position2(i,j));
            window->draw(m_rect2);
            if (m_actions.at(k) != nullptr)
            {
                m_actions.at(k)->position_sprite(j,i,m_position);
                m_actions.at(k)->afficher(window);
            }
            k++;
        }

}


Position Proc::position2(int i,int j)
{

    Position pos = {m_position.x+j*DIMS_CARRE_PROC.x,m_position.y+DIMS_CARRE_PROC.y*i};
    return pos;
}

sf::Vector2f Proc::Taille_proc()
{
    return {m_rect2.getSize().x*(m_TAILLE_C),m_rect2.getSize().y*(m_TAILLE_L)};
}

sf::Vector2f Proc::Position_CH()
{
    return m_position;
}

void Proc::placement_action( Actions *type)
{
    bool trouve = false;
    bool depasse = false;
    int i = 0;
    while (!depasse && !trouve)
    {
        if (i<=(m_TAILLE_C*m_TAILLE_L))
        {
            if (m_actions.at(i)==nullptr)
            {
                m_actions.at(i)=type;
                trouve = true;
            }
        }
        else
        {
            m_actions.at(i-1)=m_actions.at(i-1);
            depasse=true;

        }
        i++;
    }

}

void Proc::echangeAction( sf::Vector2i pos1, sf::Vector2i pos2)
{


    if (pos1 != pos2 && m_actions.at(pos1.y*m_TAILLE_C+pos1.x)!=nullptr && m_actions.at(pos2.y*m_TAILLE_C+pos2.x)!=nullptr)
    {
        Actions * temp = m_actions.at(pos2.y*m_TAILLE_C+pos2.x);
        m_actions.at(pos2.y*m_TAILLE_C+pos2.x)=m_actions.at(pos1.y*m_TAILLE_C+pos1.x);
        m_actions.at(pos1.y*m_TAILLE_C+pos1.x)=temp;
    }
}

void Proc::supprimer_action(sf::Vector2i position)
{

    if (m_actions.at(position.y*m_TAILLE_C+position.x) != nullptr)
    {
        m_actions.at(position.y*m_TAILLE_C+position.x) =nullptr;
        for (int i = position.y*m_TAILLE_C+position.x;i<m_TAILLE_C*m_TAILLE_L-1;i++)
        {
            m_actions.at(i)=m_actions.at(i+1);
        }
    }
}

void Proc::vider_proc()
{
    for (int i=0; i<m_TAILLE_C*m_TAILLE_L+1;i++)
        m_actions.at(i)=nullptr;
}

Actions * Proc::action_de_la_case(sf::Vector2i pos)
{
    return m_actions.at(pos.y*m_TAILLE_C+pos.x);
}

void Proc::placer_action_echange(sf::Vector2i pos, Actions * action)
{
    m_actions.at(pos.y*m_TAILLE_C+pos.x)=action;
}
