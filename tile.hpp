#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "animation_handler.hpp"

enum class TileType { VOID,PLAYER, MCLEOD, WALL };

std::string tileTypeToStr(TileType type);

class Tile
{
    public:

    AnimationHandler animHandler;
    sf::Sprite sprite;

    TileType tileType;

    /* Tile variant, allowing for different looking versions of the
     * same tile */
    int tileVariant;

    /* Region IDs of the tile, tiles in the same region are connected.
     * First is for transport */

    /* Constructor */
    Tile() { }

    ~Tile(){}
    Tile(const unsigned int tileSize, const unsigned int height, sf::Texture& texture,
        const std::vector<Animation>& animations)
    {
        this->tileVariant = 0;

        this->sprite.setOrigin(sf::Vector2f(4.0f, tileSize));
        this->sprite.setTexture(texture);
        this->animHandler.frameSize = sf::IntRect(0, 0, tileSize, tileSize);
        for(auto animation : animations)
        {
            this->animHandler.addAnim(animation);
        }
        this->animHandler.update(0.0f);
    }

    //Destructor

    void draw(sf::RenderWindow& window, float dt);
};

#endif /* TILE_HPP */
