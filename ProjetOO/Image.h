#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Image
{
public:
    Image();
    sf::Texture image;
    void chargerImage();
    sf::Texture retournerImageActions();
};

#endif // IMAGE_H
