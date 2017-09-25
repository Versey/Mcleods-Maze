#include <SFML/Graphics.hpp>
#include <iostream>
#include "McLeod.hpp"

McLeod::McLeod() //Constructor
{

}

McLeod::McLeod(sf::Texture& texture, int x, int y) //Overload Constructor
{
    //std::cout << "McLeod constructor" << std::endl;
    frame = 0;
    //PLAYER SPRITE
    _Sprite.setTexture(texture); //Set Sprite Texture
    //Set Sprite Position (Centre)
    _Sprite.setPosition(x - 32, y - 32); //802 - 32, 590 - 32
    sf::Vector2i _Source(1, Down); //Default Sprite Sheet Crop
    setTextureForFrame();
    //_Sprite.scale(0.5f, 0.5f); //Sprite Scale
    _AnimTime = sf::milliseconds(80); //Animation Speed
    _Speed =24; //Player Speed

}

McLeod::~McLeod() //Destructor
{
}

void McLeod::setTextureForFrame() {
    int wh = 24;
    int startX = (frame) * wh;
    int startY = 0;
    //std::cout << "frame:  " << frame << std::endl;
    //std::cout << "start x: " << startX << std::endl;
    //std::cout << "start y: " << startY << std::endl;
    _Sprite.setTextureRect(sf::IntRect(startX, startY, wh, wh)); //Crop Sprite Sheet (Default Crop)
}

//ACCESSOR FUNCTIONS
sf::Sprite McLeod::getSprite() const //Player Sprite
{
    return _Sprite;
}

void McLeod::nextFrame() {
    if(frame < 3)
        frame++;
    else
        frame = 0;
}

//PLAYER MOVEMENT
void McLeod::moveUp()
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
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/4)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();

    }

}

void McLeod::moveDown()
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
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/4)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();

    }
}

void McLeod::moveRight()
{
    nextFrame();
    setTextureForFrame();
    _Source.y = Right; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(_Speed, 0); //Move Player Sprite

    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        //_Sprite.setTextureRect(sf::IntRect(_Source.x * 24, _Source.y * 24, 24, 24)); //Crop Sprite Sheet

        //Animation
        _Source.x++;
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/4)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();
    }
}


void McLeod::moveLeft()
{
    nextFrame();
    setTextureForFrame();
    _Source.y = Left; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
    _Sprite.move(-_Speed, 0); //Move Player Sprite

    if(_AnimClock.getElapsedTime() > _AnimTime)
    {
        //_Sprite.setTextureRect(sf::IntRect(_Source.x * 24, _Source.y * 24, 24, 24)); //Crop Sprite Sheet

        //Animation
        _Source.x++;
        if(_Source.x * 24 >= _Sprite.getTexture()->getSize().x/4)
        {
            _Source.x = 0;
        }
        _AnimClock.restart();
    }
}

void McLeod::setSpeed(float TEMP_Speed, sf::Time TEMP__AnimTime) //Sprint Speed
{
    _Speed = TEMP_Speed;
    _AnimTime = TEMP__AnimTime;
}
