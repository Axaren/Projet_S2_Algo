#ifndef ACTIONS_H
#define ACTIONS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bouton.h"
#include "TypeAction.h"

class Hexabot;
const std::string CHEMIN_ACTIONS = "Sprites/fleches.png";

class Actions
{
public:
    Actions(TypeAction action);
    void afficher(sf::RenderWindow *window) ;
    void position_sprite(int i, int j, sf::Vector2f pos_init);
    void position_Ajout(sf::Vector2f position)  ;
    ~Actions();
    TypeAction get_etat();

private:
    TypeAction m_etat;
    sf::Texture image;
    sf::Sprite m_sprite;




};

#endif // ACTIONS_H
