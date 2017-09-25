#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "map.hpp"
#include "tile.hpp"
#include "SFML/Audio.hpp"

enum class ActionState { NONE, PANNING, SELECTING };

class GameStateEditor : public GameState
{
    public:
    int aiCounter = 0;
    sf::Music music;
    sf::Font font;
    sf::Text playerScoreTxt;
    sf::Text aiScoreTxt;

    private:

    void AIcheckIfFinished();
    ActionState actionState;

    sf::View gameView;
    sf::View guiView;

    Map map;
    Map map2;
    Map map3;

    int counter = 0;
    int difficulty = 12; // Default difficulty
    int currentLevel = 1; // Set to 1 by default

    Player player;

    sf::Vector2i panningAnchor;
    float zoomLevel;

    sf::Vector2i selectionStart;
    sf::Vector2i selectionEnd;

    Tile* currentTile;

    public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateEditor(Game* game);
    void checkIfFinished();
};

#endif /* GAME_STATE_EDITOR_HPP */
