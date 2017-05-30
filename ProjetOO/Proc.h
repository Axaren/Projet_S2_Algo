
#ifndef PROC_H
#define PROC_H
#include "Actions.h"
#include "array"
#include "iostream"
#include "SFML/Graphics.hpp"
#include "Programme.h"


using Position = sf::Vector2f;

static const int LIGNES_P = 3;
static const int COLONNES_P = 5;

class Proc
{
public:

    Proc(sf::Vector2f position, int TAILLE_L, int TAILLE_C);
    void dessiner(sf::RenderWindow *window);
    Position position2(int i, int j);
    sf::Vector2f Taille_proc();
    sf::Vector2f Position_CH();
    void placement_action(Actions *type);
    void echangeAction(sf::Vector2i pos1, sf::Vector2i pos2);
    void supprimer_action(sf::Vector2i position);
    void vider_proc();

    Actions *action_de_la_case(sf::Vector2i pos);
    void placer_action_echange(sf::Vector2i pos, Actions *action);
private:

    sf::RectangleShape m_rect, m_rect2;
    Position m_position;
    std::vector<Actions*> m_actions;
    int m_TAILLE_L, m_TAILLE_C;



};

#endif // PROC_H


