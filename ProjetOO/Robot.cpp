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
    window->draw(m_sprite);
}

void Robot::tourner(bool clockwise)
{
    if (clockwise)
        m_direction++;
    else
        m_direction--;
}

void Robot::avancer()
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
    }
}

sf::Vector2i Robot::get_position()
{
    return m_position;
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
        EXIT_FAILURE;
    }
    else
        feuille_chargee = true;
}
