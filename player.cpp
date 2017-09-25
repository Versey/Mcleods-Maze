#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"

Player::Player() //Constructor
{

}

Player::Player(sf::Texture& texture, int x, int y) //Overload Constructor
{
    //std::cout << "Player constructor" << std::endl;
    directionOffset = 0;
    frame = 0;
    //PLAYER SPRITE
    _Sprite.setTexture(texture); //Set Sprite Texture
    //Set Sprite Position (Centre)
    _Sprite.setPosition(x - 32, y - 32); //802 - 32, 590 - 32
    //_Sprite.setScale(1f, 1f); //Sprite Scale
    sf::Vector2i _Source(1, Down); //Default Sprite Sheet Crop
    //_Sprite.setTextureRect(sf::IntRect(_Source.x * 24, _Source.y * 24, 24, 24)); //Crop Sprite Sheet (Default Crop)
    //_Sprite.setTextureRect(sf::IntRect(0, 0, 24, 24)); //Crop Sprite Sheet (Default Crop)
    setTextureForFrame();
    //setTextureForFrame();
    //PLAYER / ANIMATION SPEED
    _AnimTime = sf::milliseconds(80); //Animation Speed
    _Speed =24; //Player Speed

}

Player::~Player() //Destructor
{
}

void Player::setTextureForFrame() {
    int wh = 24;
    int startX = (frame + directionOffset) * wh;
    int startY = 0;
    //std::cout << "direction offset:  " << directionOffset << std::endl;
    //std::cout << "frame:  " << frame << std::endl;
    //std::cout << "start x: " << startX << std::endl;
    //std::cout << "start y: " << startY << std::endl;
    _Sprite.setTextureRect(sf::IntRect(startX, startY, wh, wh)); //Crop Sprite Sheet (Default Crop)
}

//ACCESSOR FUNCTIONS
sf::Sprite Player::getSprite() const //Player Sprite
{
    return _Sprite;
}

void Player::nextFrame() {
    if(frame < 3)
        frame++;
    else
        frame = 0;
}

//PLAYER MOVEMENT
void Player::moveUp()
{
    nextFrame();
    setTextureForFrame();
    _Source.y = Up; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(0, -_Speed); //Move Player Sprite

    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        //_Sprite.setTextureRect(sf::IntRect(_Source.x * 24, _Source.y * 24, 24, 24)); //Crop Sprite Sheet

        //Animation
        _Source.x++;
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/8)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();

    }

}

void Player::moveDown()
{
    nextFrame();
    setTextureForFrame();
    _Source.y = Down; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(0, _Speed); //Move Player Sprite

    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        //_Sprite.setTextureRect(sf::IntRect(_Source.x * 24, _Source.y * 24, 24, 24)); //Crop Sprite Sheet

        //Animation
        _Source.x++;
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/8)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();

    }
}

void Player::moveRight()
{
    nextFrame();
    directionOffset = 0;
    setTextureForFrame();
    _Source.y = Right; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(_Speed, 0); //Move Player Sprite

    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        //_Sprite.setTextureRect(sf::IntRect(_Source.x * 24, _Source.y * 24, 24, 24)); //Crop Sprite Sheet

        //Animation
        _Source.x++;
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/8)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();
    }
}


void Player::moveLeft()
{
    nextFrame();
    directionOffset = 4;
    setTextureForFrame();
    _Source.y = Left; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(-_Speed, 0); //Move Player Sprite

    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        //_Sprite.setTextureRect(sf::IntRect(_Source.x * 24, _Source.y * 24, 24, 24)); //Crop Sprite Sheet

        //Animation
        _Source.x++;
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/8)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();
    }
}

void Player::setSpeed(float TEMP_Speed, sf::Time TEMP__AnimTime) //Sprint Speed
{
    _Speed = TEMP_Speed;
    _AnimTime = TEMP__AnimTime;
}
