#include "game.hpp"
#include "game_state_start.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"

int main()
{
    sf::Music music;
    if (!music.openFromFile("media/song2.ogg")){
    }
    music.setLoop(true);
    music.setPitch(1.1);
    music.setVolume(50);
    music.play();

    sf::Font font;
    if (!font.loadFromFile("media/font.ttf"))
    {
        std::cout << "font error" << std::endl;
    }
    Game game;
    game.pushState(new GameStateStart(&game));
    game.gameLoop();

    return 0;
}

