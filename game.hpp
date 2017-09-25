#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"
#include "tile.hpp"
#include "gui.hpp"
#include "player.hpp"
#include "score.hpp"

class GameState;

class Game
{
	private:

	void loadTextures();
	void loadStylesheets();
	void loadFonts();
	static void loadPlayer();

	public:
    void loadTiles();
    score scoreObj;


	// Size of blocks
	int tileSize = 24;

	std::stack<GameState*> states;

	sf::RenderWindow window;
	TextureManager texmgr;
	sf::Sprite background;

	int currentLevel = 1;

	std::map<std::string, Tile> tileAtlas;
	std::map<std::string, Tile> tileAtlas2;
	std::map<std::string, Tile> tileAtlas3;

	std::map<std::string, GuiStyle> stylesheets;
	std::map<std::string, sf::Font> fonts;

	void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);

    GameState* peekState();

    void gameLoop();

    Game();
    ~Game();
};

#endif /* GAME_HPP */
