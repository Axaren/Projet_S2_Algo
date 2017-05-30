#ifndef ROBOT_H
#define ROBOT_H
#include <SFML/Graphics.hpp>
#include <iostream>

const std::string CHEMIN_FEUILLE_DE_SPRITES_ROBOT = "Sprites/robot.png";
const sf::IntRect RECTANGLE_DIRECTION_0 = {/* A modifier */};
const sf::IntRect RECTANGLE_DIRECTION_1 = {/* A modifier */};
const sf::IntRect RECTANGLE_DIRECTION_2 = {/* A modifier */};
const sf::IntRect RECTANGLE_DIRECTION_3 = {/* A modifier */};
const sf::IntRect RECTANGLE_DIRECTION_4 = {/* A modifier */};
const sf::IntRect RECTANGLE_DIRECTION_5 = {/* A modifier */};

class Robot
{
private :
    sf::Sprite m_sprite;
    sf::Vector2i m_position;
    int m_direction;

    void loadSprite();
    static void loadSpritesheet();

    static sf::Texture spritesheet;
    static bool feuille_chargee;
public:
    Robot(sf::Vector2i position, int direction);
    void dessiner(sf::RenderWindow *window);
    sf::Vector2i avancer();
    void tourner(bool clockwise);

    sf::Vector2i get_position() const;
    void set_position(sf::Vector2i position);
};

#endif // ROBOT_H
