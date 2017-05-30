#include <SFML/Graphics.hpp>

namespace Conversions_Coordonnees
{
    static sf::Vector2i cube_to_oddr(sf::Vector3i cube)
    {
        sf::Vector2i oddr;
        oddr.x = cube.x + (cube.z - (cube.z&1)) / 2;
        oddr.y = cube.z;
        return oddr;
    }

    static sf::Vector3i oddr_to_cube(sf::Vector2i oddr)
    {
        sf::Vector3i cube;
        cube.x = oddr.x - (oddr.y - (oddr.y&1)) / 2;
        cube.z = oddr.y;
        cube.y = -cube.x-cube.z;
        return cube;
    }
}
