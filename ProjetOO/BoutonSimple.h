#ifndef BOUTONSIMPLE_H
#define BOUTONSIMPLE_H
#include <SFML/Graphics.hpp>
#include "Bouton.h"
#include <iostream>
enum TypeBouton {PLAY,VIDER,ARRET,QUITTER_JEU, PLAY_MENU,QUITTER_MENU};

class BoutonSimple : public Bouton
{
public:
    BoutonSimple(sf::Vector2f position, TypeBouton type);
    void dessiner_bouton(sf::RenderWindow *window);
    sf::Vector2f position();
    sf::Vector2f taille();

private :
    sf::RectangleShape bouton;
    sf::Vector2f m_position;
    sf::Texture image;
    sf::Sprite * sprite;
    TypeBouton m_type;
    std::vector<BoutonSimple * > m_boutons;

    int m_largeur =800;
    int m_hauteur = 500;
};

#endif // BOUTONSIMPLE_H
