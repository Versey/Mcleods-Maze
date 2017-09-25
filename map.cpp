#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <SFML/Audio/Music.hpp>

#include "map.hpp"
#include "tile.hpp"
#include "maze.h"
#include "game.hpp"
#include "mcleod.hpp"


using namespace std;
void Map::clearTiles(){

Tile emptytile;
    for (int i = 0; i < tiles.size() ; i++){
        tiles[1,i] = emptytile;
    }
}

/* Load map from disk */
void Map::load(const std::string& filename, unsigned int width, unsigned int height,
    std::map<std::string, Tile>& tileAtlas, int level)
{
    std::ifstream inputFile;
    inputFile.open(filename, std::ios::in | std::ios::binary);

    //OBJECTS
    Player player(this->game->texmgr.getRef("player"), 782, 522); //Player 802 - 32, 590 - 32
    this->thePlayer = player;

    McLeod ai(this->game->texmgr.getRef("mcleod"), 1512, 522); //Player
    this->theAi = ai;

    //OBJECTS
    Player pFinish(this->game->texmgr.getRef("finish"), 1166, 907); // Finish
    this->pFinish = pFinish;

    //OBJECTS
    Player aiFinish(this->game->texmgr.getRef("finish"), 1897, 907); // Finish
    this->aiFinish = aiFinish;

    // Creates a maze
    Maze playerMaze(mazeSize, 1, 1);
    playerMaze.outputMaze();
    //playerMaze.printOutput();

    playerMaze.getShortestPathString();
    //playerMaze.printShortestPath();

    this->shortestRoute = playerMaze.getShortestPathString();
    //cout << this->shortestRoute << endl;

    //this->shortestRoute
    this->theMaze = playerMaze.outputMaze();
    this->width = width;
    this->height = height;

    // Level 1
if (level == 1){
    for(int pos = 0; pos < this->width * this->height; ++pos)
    {
        this->resources.push_back(255);

        TileType tileType;
        inputFile.read((char*)&tileType, sizeof(int));

        this->tiles.push_back(tileAtlas.at("wall"));

        Tile& tile = this->tiles.back();
    }

    inputFile.close();

    return;
}

    // Level 2
if (level == 2){
    for(int pos = 0; pos < this->width * this->height; ++pos)
    {
        this->resources.push_back(255);

        TileType tileType;
        inputFile.read((char*)&tileType, sizeof(int));

        this->tilesL2.push_back(tileAtlas.at("wall"));

        Tile& tile = this->tilesL2.back();
    }

    inputFile.close();

    return;
}

}

void Map::setMazeSize(int newSize){
    this->mazeSize = newSize;
}

void Map::createMaze(int theSize,int start, int end){
     // Creates a maze
    Maze playerMaze(theSize, start, end);
    playerMaze.outputMaze();
    playerMaze.printOutput();
    this->theMaze = playerMaze.outputMaze();

}

void Map::draw(sf::RenderWindow& window, float dt, int level)
{

if(tileSize == 24){
    for(int y= 0; y < mazeSize * 2 + 1 ; ++y) // Width -> 16
    {
        for(int x = 0; x < mazeSize * 2 + 1; ++x) // Height -> 16
        {

            if((theMaze[y][x]) != 1){
                sf::Vector2f pos;
                pos.x = x*tileSize + 10 + + 1450;
                pos.y = y*tileSize + 10 + 480;

                this->tiles[y*this->width+x].sprite.setPosition(pos);
                // Draw the tile //
                this->tiles[y*this->width+x].draw(window, dt);
            }

        }
    }
    // PlAYER LOOP

       for(int y= 0; y < mazeSize * 2 + 1 ; ++y) // Width -> 16
    {
        for(int x = 0; x < mazeSize * 2 + 1; ++x) // Height -> 16
        {
            if((theMaze[y][x]) != 1){
                sf::Vector2f pos;
                pos.x = x*tileSize + 10 + + 720;
                pos.y = y*tileSize + 10 + 480;

                this->tiles[y*this->width+x].sprite.setPosition(pos);
                // Draw the tile //
                this->tiles[y*this->width+x].draw(window, dt);
            }

            else{
            }

        }
    } // AI LOOP
//}// END LEVEL 1
}

// LEVEL 2
if(tileSize == 16){
    for(int y= 0; y < mazeSize * 2 + 1 ; ++y) // Width -> 16
    {
        for(int x = 0; x < mazeSize * 2 + 1; ++x) // Height -> 16
        {

            if((theMaze[y][x]) != 1){
                sf::Vector2f pos;
                pos.x = x*tileSize + 10 + + 1450;
                pos.y = y*tileSize + 10 + 480;

                this->tilesL2[y*this->width+x].sprite.setPosition(pos);
                // Draw the tile //
                this->tilesL2[y*this->width+x].draw(window, dt);
            }


        }
    }
    // PlAYER LOOP

       for(int y= 0; y < mazeSize * 2 + 1 ; ++y) // Width -> 16
    {
        for(int x = 0; x < mazeSize * 2 + 1; ++x) // Height -> 16
        {
            if((theMaze[y][x]) != 1){
                sf::Vector2f pos;
                pos.x = x*tileSize + 10 + + 720;
                pos.y = y*tileSize + 10 + 480;

                this->tilesL2[y*this->width+x].sprite.setPosition(pos);
                // Draw the tile //
                this->tilesL2[y*this->width+x].draw(window, dt);
            }

        }
    } // AI LOOP
//}// END LEVEL 2

// LEVEL 2
if(tileSize == 10){
    for(int y= 0; y < mazeSize * 2 + 1 ; ++y) // Width -> 16
    {
        for(int x = 0; x < mazeSize * 2 + 1; ++x) // Height -> 16
        {

            if((theMaze[y][x]) != 1){
                sf::Vector2f pos;
                pos.x = x*tileSize + 10 + + 1450;
                pos.y = y*tileSize + 10 + 480;

                this->tilesL2[y*this->width+x].sprite.setPosition(pos);
                // Draw the tile //
                this->tilesL2[y*this->width+x].draw(window, dt);
            }


        }
    }
    // PlAYER LOOP

       for(int y= 0; y < mazeSize * 2 + 1 ; ++y) // Width -> 16
    {
        for(int x = 0; x < mazeSize * 2 + 1; ++x) // Height -> 16
        {
            if((theMaze[y][x]) != 1){
                sf::Vector2f pos;
                pos.x = x*tileSize + 10 + + 720;
                pos.y = y*tileSize + 10 + 480;

                this->tilesL2[y*this->width+x].sprite.setPosition(pos);
                // Draw the tile //
                this->tilesL2[y*this->width+x].draw(window, dt);
            }
        }
    } // AI LOOP
//}// END LEVEL 2
}
}
}


