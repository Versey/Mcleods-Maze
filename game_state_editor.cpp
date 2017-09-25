#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_editor.hpp"
#include "game_state_start.hpp"
#include "map.hpp"
#include "player.hpp"
#include <iostream>
#include <sstream>
#include <string>


void GameStateEditor::draw(const float dt)
{
    if (!music.openFromFile("media/Hit_Hurt.ogg")){
    }

    this->game->window.clear(sf::Color::Black);
    this->game->window.setView(this->guiView);
    this->game->window.draw(this->game->background);

    //sf::Vector2f pos = this->game->background.getPosition();
    //std::cout << "background pos x:" << pos.x << " pos y: " << pos.y << std::endl;

    this->game->window.setView(this->gameView);
    //sf::Vector2f pos2 = this->gameView.getCenter();
    //std::cout << "gameview center x:" << pos2.x << " center y " << pos2.y << std::endl;

    if (currentLevel == 1){
        this->map.draw(this->game->window, dt,1);
    }

    if (currentLevel == 2){
        this->map2.draw(this->game->window, dt,2);
    }

    if (currentLevel == 3){
        this->map3.draw(this->game->window, dt,3);
    }

    this->game->window.draw(map.thePlayer.getSprite()); //Draw Player Sprite
    this->game->window.draw(map.theAi.getSprite()); //Draw Player Sprite

    this->game->window.draw(map.aiFinish.getSprite()); //Draw Player Sprite
    this->game->window.draw(map.pFinish.getSprite()); //Draw Player Sprite

    this->game->window.draw(playerScoreTxt);
    this->game->window.draw(aiScoreTxt);

    //std::cout << "printing text" << std::endl;

    return;
}

void GameStateEditor::update(const float dt)
{

    if (counter % difficulty == 0){
        if(aiCounter < map.shortestRoute.length()){
                    	if (map.shortestRoute.length()>0)
                            {
                                int directionAsInt; char directionAsC;
                                directionAsC = map.shortestRoute.at(aiCounter);
                                directionAsInt = atoi(&directionAsC);
                                //cout << "Counter: " << aiCounter << endl;
                                //cout << "Direction : " << directionAsInt << endl;

                                switch(directionAsInt){
                                case 0:{
                                    map.theAi.moveDown();
                                    break;
                                }
                                case 1:{
                                     map.theAi.moveRight();
                                     break;
                                }
                                 case 2:{
                                     map.theAi.moveUp();
                                     break;
                                }
                                 case 3:{
                                     map.theAi.moveLeft();
                                     break;
                                }

                                }
                            }
                    }
        AIcheckIfFinished();
        this->aiCounter ++;
    }
    counter ++;
    return;
}

void GameStateEditor::checkIfFinished(){
    if (map.thePlayer._Sprite.getGlobalBounds().intersects(map.pFinish.getSprite().getGlobalBounds()))
    {
        //std::cout << "Reached End!" << std::endl;
        game->scoreObj.incPScore();
        std::cout << "Player: " << game->scoreObj.getPScore() << " AI: " <<  game->scoreObj.getAiScore() << std::endl;
        this->game->pushState(new GameStateEditor(this->game));
        return;
    }
}
void GameStateEditor::AIcheckIfFinished(){
    if (map.theAi._Sprite.getGlobalBounds().intersects(map.aiFinish.getSprite().getGlobalBounds()))
    {
        //std::cout << "Reached End!" << std::endl;
        game->scoreObj.incAiScore();
        std::cout << "Player: " << game->scoreObj.getPScore() << " AI: " <<  game->scoreObj.getAiScore() << std::endl;
        this->game->pushState(new GameStateEditor(this->game));
        return;
    }
}


void GameStateEditor::handleInput()
{
    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {

            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape){
                        this->game->pushState(new GameStateEditor(this->game));
                        return;
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    this->difficulty--;

                }

                if (event.key.code == sf::Keyboard::E)
                {
                    this->difficulty++;


                }

               if (event.key.code == sf::Keyboard::T)
                {


                }

                   if (event.key.code == sf::Keyboard::Right)
                {

                        map.thePlayer.moveRight();
                        for (int x=0; x < 1500; x++){
                            if (map.thePlayer._Sprite.getGlobalBounds().intersects(map.tiles[1,x].sprite.getGlobalBounds())){

                                map.thePlayer.moveLeft();

                            }
                        }

                        checkIfFinished();

                }

                  if (event.key.code == sf::Keyboard::Left)
                {
                        map.thePlayer.moveLeft();
                        for (int x=0; x < 1500; x++){
                            if (map.thePlayer._Sprite.getGlobalBounds().intersects(map.tiles[1,x].sprite.getGlobalBounds()) ){
                                map.thePlayer.moveRight();

                            }
                        }
                        checkIfFinished();

                }
                    if (event.key.code == sf::Keyboard::Up)
                {
                        map.thePlayer.moveUp();
                        for (int x=0; x < 1500; x++){
                            if (map.thePlayer._Sprite.getGlobalBounds().intersects(map.tiles[1,x].sprite.getGlobalBounds())){
                                map.thePlayer.moveDown();

                            }
                        }
                        checkIfFinished();
                }

                  if (event.key.code == sf::Keyboard::Down)
                {
                        map.thePlayer.moveDown();
                        for (int x=0; x < 1500; x++){
                            if (map.thePlayer._Sprite.getGlobalBounds().intersects(map.tiles[1,x].sprite.getGlobalBounds())){
                                map.thePlayer.moveUp();

                            }
                        }
                        checkIfFinished();
                        }
            }

			case sf::Event::MouseButtonPressed:
			{

				if(event.mouseButton.button == sf::Mouse::Left)
				{
					/* Select map tile */
					if(this->actionState != ActionState::SELECTING)
					{
						this->actionState = ActionState::SELECTING;
						sf::Vector2f pos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->gameView);
						selectionStart.x = pos.y / (this->map.tileSize) + pos.x / (2*this->map.tileSize) - this->map.width * 0.5 - 0.5;
						selectionStart.y = pos.y / (this->map.tileSize) - pos.x / (2*this->map.tileSize) + this->map.width * 0.5 + 0.5;
					}
				}

				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				/* Stop panning */
				if(event.mouseButton.button == sf::Mouse::Middle)
				{
				}
				/* Stop selecting */
				else if(event.mouseButton.button == sf::Mouse::Left)
				{
				}
				break;
			}

            /* Close the window */
            case sf::Event::Closed:
            {
                this->game->window.close();
                break;
            }
            /* Resize the window */
            case sf::Event::Resized:
            {
                gameView.setSize(event.size.width, event.size.height);
                gameView.zoom(zoomLevel);
                guiView.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));

                sf::Vector2f pos = this->game->background.getPosition();
                std::cout << "editor background pos x:" << pos.x << " pos y: " << pos.y << std::endl;

                this->game->background.setScale(
                    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            default: break;
        }
    }

    return;
}

GameStateEditor::GameStateEditor(Game* game)
{
    //std::cout << "new game state" << std::endl;
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->guiView.setSize(pos);
    this->gameView.setSize(pos);
    // Center screen on load map
    pos *= 0.5f;
    this->guiView.setCenter(pos);
    this->gameView.setCenter(pos);

    if (currentLevel == 1){
    // Hardcoded to scale and align mazes
    map = Map("GameMap", 55, 55, game, 1, 24);

    }
    //map3 = Map("GameMap", 55, 55, game->tileAtlas3, 3);

    this->zoomLevel = 1.0f;

    /* Centre the camera on the map */
    sf::Vector2f centre(this->map.width, this->map.height*0.5);
    centre *= float(this->map.tileSize);
    gameView.setCenter(centre);

    this->font = this->game->fonts.at("main_font");
    playerScoreTxt.setFont(this->font);
    aiScoreTxt.setFont(this->font);

    playerScoreTxt.setFont(font);
    playerScoreTxt.setCharacterSize(20);
    playerScoreTxt.setStyle(sf::Text::Bold);
    playerScoreTxt.setColor(sf::Color::Red);
    playerScoreTxt.setPosition(centre.x/2 + 70,centre.y/2 + 100);
    std::stringstream sstm2;
    sstm2 << "Player: " << this->game->scoreObj.getPScore();;
    playerScoreTxt.setString(sstm2.str());

    aiScoreTxt.setFont(font);
    aiScoreTxt.setCharacterSize(20);
    aiScoreTxt.setStyle(sf::Text::Bold);
    aiScoreTxt.setColor(sf::Color::Red);
    aiScoreTxt.setPosition(centre.x/2 + 800,centre.y/2 + 100);
    std::stringstream sstm;
    sstm << "Lord McLeod: " << this->game->scoreObj.getAiScore();;
    aiScoreTxt.setString(sstm.str());
}
