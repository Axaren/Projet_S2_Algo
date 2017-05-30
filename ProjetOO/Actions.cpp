#include "Actions.h"
#include <SFML/Graphics/Drawable.hpp>

const sf::Vector2f DIMS_SPRITE = {110,110};


Actions::Actions(TypeAction action)
    : m_etat {action}
{
    if (!image.loadFromFile("Sprites/Button.png"))
    {
        std::cerr << "Chemin vers Sprite d'actions invalide !" << std::endl;
        EXIT_FAILURE;
    }
    else
    {

        //m_sprite = new sf::Sprite();

        switch (m_etat)
        {
        case Tourner_Droite:
                m_sprite.setTextureRect(sf::IntRect(636,2305,DIMS_SPRITE.x,DIMS_SPRITE.y));
                m_sprite.setScale({0.40,0.40});
                m_sprite.setTexture(image);

            break;

        case Tourner_Gauche :
            m_sprite.setTextureRect(sf::IntRect(636,2305,DIMS_SPRITE.x,DIMS_SPRITE.y));
            m_sprite.setScale({0.40,-0.40});
            m_sprite.setRotation(180);
            m_sprite.setTexture(image);

            break;

        case Avancer:
            m_sprite.setTextureRect(sf::IntRect(80,1645,DIMS_SPRITE.x,DIMS_SPRITE.y));
            m_sprite.setScale({0.40,0.40});
            m_sprite.setTexture(image);
            break;

        case Allumer :
            m_sprite.setTextureRect(sf::IntRect(486,310,DIMS_SPRITE.x,DIMS_SPRITE.y));
            m_sprite.setScale({0.40,0.40});
            m_sprite.setTexture(image);

            break;


        }
    }
}


void Actions::afficher(sf::RenderWindow * window)
{
    window->draw(m_sprite);
}

void Actions::position_sprite(int i, int j, sf::Vector2f pos_init)
{
    switch (m_etat)
    {
    case Tourner_Droite:

        m_sprite.setPosition({(pos_init.x+6)+50*i,(pos_init.y+3)+50*j});

        break;

    case Tourner_Gauche :

        m_sprite.setPosition({pos_init.x+48+50*i,pos_init.y+3+50*j});

        break;

    case Allumer :

        m_sprite.setPosition({pos_init.x+5+50*i,pos_init.y+3+50*j});
        break;

    case Avancer:
        m_sprite.setPosition({pos_init.x+5+50*i,pos_init.y+3+50*j});
        break;

    default :
        break;

    }
}

void Actions::position_Ajout(sf::Vector2f position)
{
    switch (m_etat)
    {
    case Tourner_Droite:

        m_sprite.setPosition({position});

        break;

    case Tourner_Gauche :

        m_sprite.setPosition({position});

        break;

    case Allumer :
        m_sprite.setPosition({position});
        break;

    default :
        m_sprite.setPosition({position});
        break;

    }
}

Actions::~Actions()
{

}

TypeAction Actions::get_etat()
{
    return m_etat;
}
