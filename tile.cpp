#include <SFML/Graphics.hpp>

#include "animation_handler.hpp"
#include "tile.hpp"
#include "map.hpp"

void Tile::draw(sf::RenderWindow& window, float dt)
{
    /* Change the sprite to reflect the tile variant */
    this->animHandler.changeAnim(this->tileVariant);

    /* Update the animation */
    this->animHandler.update(dt);

    /* Update the sprite */
    this->sprite.setTextureRect(this->animHandler.bounds);

    /* Draw the tile */
    window.draw(this->sprite);

    return;
}
