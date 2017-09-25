#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
#include "texture_manager.hpp"
#include "animation_handler.hpp"
#include "tile.hpp"
#include "player.hpp"
#include "score.hpp"

void Game::loadTiles()
{
    Animation staticAnim(0, 0, 1.0f);

    if (currentLevel == 1){
    // Load tiles into a map
        this->tileAtlas["wall"] =
            Tile(this->tileSize, 1, texmgr.getRef("wall"),
                { staticAnim });

        return;
    }

    if (currentLevel == 2){
    // Load tiles into a map
        this->tileAtlas2["wall"] =
            Tile(this->tileSize, 1, texmgr.getRef("wall"),
                { staticAnim });

        return;
    }

    if (currentLevel == 3){
    // Load tiles into a map
        this->tileAtlas3["wall"] =
            Tile(this->tileSize, 1, texmgr.getRef("wall"),
                { staticAnim });

        return;
    }

}

void Game::loadTextures()
{
    texmgr.loadTexture("wall",         "media/wall.png");
    texmgr.loadTexture("player",        "media/pengSheet_24px.png");
    texmgr.loadTexture("mcleod",         "media/McleodSheet_24px.png");
    texmgr.loadTexture("background",    "media/background.png");
    texmgr.loadTexture("finish",        "media/finish.png");
}

void Game::loadFonts()
{
    sf::Font font;
    font.loadFromFile("media/font.ttf");
    this->fonts["main_font"] = font;

    return;
}

void Game::loadStylesheets()
{
    this->stylesheets["button"] = GuiStyle(&this->fonts.at("main_font"), 1,
        sf::Color(0xc6,0xc6,0xc6), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00),
        sf::Color(0x61,0x61,0x61), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00));
    this->stylesheets["text"] = GuiStyle(&this->fonts.at("main_font"), 0,
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0xff,0xff),
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0x00,0x00));

    return;
}

void Game::pushState(GameState* state)
{
    state->game->background.setPosition(0,0);
    this->states.push(state);

    return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while(this->window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if(peekState() == nullptr) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game()
{
    this->loadTextures();
    this->loadTiles();
	this->loadFonts();
	this->loadStylesheets();
	scoreObj = score();

    this->window.create(sf::VideoMode(1280,720), "Mcleod's MadHouse");
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->texmgr.getRef("background"));
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}
