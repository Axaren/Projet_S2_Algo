#include "Robot.h"

bool Robot::feuille_chargee = false;
sf::Texture Robot::spritesheet;

Robot::Robot(sf::Vector2i position, int direction)
    :
      m_position {position},
      m_direction {direction}
{
}

void Robot::dessiner(sf::RenderWindow *window)
{
    if (m_position.y %2 == 1)
        m_sprite.setPosition(m_position.x*RAYON_CASES*1.75+RAYON_CASES-4,m_position.y*RAYON_CASES*1.5);
    else
        m_sprite.setPosition(m_position.x*RAYON_CASES*1.75,m_position.y*RAYON_CASES*1.5);

    window->draw(m_sprite);
}

void Robot::tourner(bool clockwise)
{
    if (clockwise)
        m_direction++;
    else
        m_direction--;
}

sf::Vector2i Robot::avancer()
{
    if (m_position.x %2 == 1)
    {
        switch (m_direction%6)
        {
        case 0:
            m_position.x--;
            break;
        case 1:
            m_position.y--;
            break;
        case 2:
            m_position.x++;
            m_position.y--;
            break;
        case 3:
            m_position.x++;
            break;
        case 4:
            m_position.x++;
            m_position.y++;
            break;
        case 5:
            m_position.y++;
            break;
        }
    }
    else
    {
        switch (m_direction%6)
        {
        case 0:
            m_position.x--;
            break;
        case 1:
            m_position.x--;
            m_position.y--;
            break;
        case 2:
            m_position.y--;
            break;
        case 3:
            m_position.x++;
            break;
        case 4:
            m_position.y++;
            break;
        case 5:
            m_position.x--;
            m_position.y++;
            break;
        }
        return m_position;
    }
}

sf::Vector2i Robot::get_position() const
{
    return m_position;
}

void Robot::set_position(sf::Vector2i position)
{
    m_position = position;
}

void Robot::loadSprite()
{
    if (!feuille_chargee)
    {
        loadSpritesheet();
    }

    m_sprite.setTexture(spritesheet);

    switch(m_direction)
    {
    case 0:
        m_sprite.setTextureRect(RECTANGLE_DIRECTION_0);
        break;
    case 1:
        m_sprite.setTextureRect(RECTANGLE_DIRECTION_1);
        break;
    case 2:
        m_sprite.setTextureRect(RECTANGLE_DIRECTION_2);
        break;
    case 3:
        m_sprite.setTextureRect(RECTANGLE_DIRECTION_3);
        break;
    case 4:
        m_sprite.setTextureRect(RECTANGLE_DIRECTION_4);
        break;
    case 5:
        m_sprite.setTextureRect(RECTANGLE_DIRECTION_5);
        break;
    }
}

void Robot::loadSpritesheet()
{
    if (!spritesheet.loadFromFile(CHEMIN_FEUILLE_DE_SPRITES_ROBOT))
    {
        std::cerr << "Erreur lors du chargement de la feuille de sprites" << std::endl;
    }
    else
        feuille_chargee = true;
}
