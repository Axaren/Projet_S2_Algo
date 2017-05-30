#include "BoutonSimple.h"

BoutonSimple::BoutonSimple(sf::Vector2f position, TypeBouton type)
    : m_position{position},
      m_type {type}
{
    bouton.setPosition({position});
    bouton.setSize({50,50});

    if (!image.loadFromFile("Sprites/boutonMenu.png"))
    {
        std::cerr << "ahah" << std::endl ;
    }
    else
    {

        sprite = new sf::Sprite();
        sprite->setPosition({m_position});


        switch (type) {
        case PLAY:
            bouton.setFillColor(sf::Color::Green);

            break;
        case ARRET:
            bouton.setFillColor(sf::Color::Blue);

            break;
        case VIDER:
            bouton.setFillColor(sf::Color::Red);
            break;
        case QUITTER_JEU:
            bouton.setFillColor(sf::Color::Yellow);
            break;
        case PLAY_MENU:
            bouton.setFillColor(sf::Color::Cyan);
            bouton.setSize({70,40});
            sprite->setTexture(image);
            sprite->setTextureRect(sf::IntRect(775,50,125,45));
            break;
        case QUITTER_MENU:
            bouton.setFillColor(sf::Color::Transparent);
            bouton.setSize({125,45});
            sprite->setTexture(image);
            sprite->setTextureRect(sf::IntRect(775,50,125,45));
        default:
            break;
        }

    }
}


void BoutonSimple::dessiner_bouton(sf::RenderWindow * window)
{
    window->draw(bouton);
    window->draw( * sprite);
}

sf::Vector2f BoutonSimple::position()
{
    return m_position;
}

sf::Vector2f BoutonSimple::taille()
{
    return bouton.getSize();
}

//void BoutonSimple::loadSpritesheet()
//{
//    if (!image.loadFromFile(CHEMIN_FEUILLE_DE_SPRITES_BOUTON))
//    {
//        std::cerr << "Erreur lors du chargement de la feuille de sprites" << std::endl;
//        EXIT_FAILURE;
//    }
//    else
//        feuille_chargee = true;
//}

//void BoutonSimple::loadSprite(sf::RenderWindow *window)
//{
//    if (!feuille_chargee)
//    {
//        loadSpritesheet();
//    }

//    m_sprite.setTexture(image);

//    switch(m_type)
//    {
//    case PLAY:
//        sprite.setTexture(sf::IntRect(775,50,120,45));
//        window->draw(sprite);
//        break;
////    case ARRET:
////        bouton.setFillColor(sf::Color::Blue);

////        break;
////    case VIDER:
////        bouton.setFillColor(sf::Color::Red);
////        break;
////    case QUITTER_JEU:
////        bouton.setFillColor(sf::Color::Yellow);
////        break;
////    case PLAY_MENU:
////        bouton.setFillColor(sf::Color::Cyan);
////        bouton.setSize({70,40});
////        break;
////    case QUITTER_MENU:
////        bouton.setFillColor(sf::Color::Magenta);
////        bouton.setSize({70,40});
////    default:
//////        break;
//       // break;
//    }
//}
