#include "Image.h"

Image::Image()
{

}

void Image::chargerImage()
{
    if (!image.loadFromFile("Sprites/Button.png"))
    {
        std::cerr << " erreur chemins sprites bouton, actions non valide ! " << std::endl;
        EXIT_FAILURE;

    }
}


sf::Texture Image::retournerImageActions()
{
    //return this;
}
