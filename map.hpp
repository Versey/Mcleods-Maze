#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

#include <string>
#include <map>
#include <vector>

#include "tile.hpp"
#include "Maze.h"
#include "player.hpp"
#include "Game.hpp"
#include "mcleod.hpp"

class Map
{

    public:

    Player thePlayer;
    McLeod theAi;
    Player pFinish;
    Player aiFinish;

    bool** theMaze;
    int mazeSize = 9;
    unsigned int width;
    unsigned int height;
    Game* game;

    std::vector<Tile> tiles;
    std::vector<Tile> tilesL2;
    std::vector<Tile> tilesL3;

    /* Resource map */
    std::vector<int> resources;

    string shortestRoute;

    unsigned int tileSize;

    void increaseSize();

    void clearTiles();
    unsigned int numRegions[1];

    //string shortestRoute;
    void setMazeSize(int);

    /* Load map from disk */
    void load(const std::string& filename, unsigned int width, unsigned int height,
        std::map<std::string, Tile>& tileAtlas,int level);

    /* Save map to disk */
    void save(const std::string& filename);

    /* Draw the map */
    void draw(sf::RenderWindow& window, float dt,int level);

    void createMaze(int,int,int);

	/* Blank map constructor */
	Map()
	{
	    if (mazeSize == 12){
            this->tileSize = 24;

	    }

		this->width = 0;
		this->height = 0;
		this->numRegions[0] = 1;
	}
	/* Load map from file constructor */
	Map(const std::string& filename,unsigned int width, unsigned int height,
		Game* game, int level, int tileSize)
	{
		this->tileSize = 24;
		this->game = game;
		load(filename, width, height, game->tileAtlas, level);
	}
};

#endif /* MAP_HPP */
