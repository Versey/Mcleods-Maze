#ifndef MCLEOD_HPP_INCLUDED
#define MCLEOD_HPP_INCLUDED

class McLeod
{
    public:
         McLeod(); //Constructor
         McLeod(sf::Texture& texture, int x, int y); //Overload Constructor
         ~McLeod(); //Destructor

        //PLAYER MOVEMENT FUNCTIONS
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
        void setSpeed(float, sf::Time);
        void draw(sf::RenderWindow& window, float dt);

        //ACCESSOR FUNCTIONS
        sf::Sprite getSprite() const;
        sf::Sprite _Sprite; //Declare Player Sprite

    private:
        sf::Vector2i _Source; //Declare Source (Sprite Sheet Crop)
        enum _Direction{ Down, Left, Right, Up }; //Declare Direction Enumeration

        //ANIMATION DATA
        float _Speed; //Player Speed
        sf::Clock _AnimClock; //Player Animation Clock
        sf::Time _AnimTime; //Player Animation Time
        void nextFrame();
        int frame;
        void setTextureForFrame();
};

#endif // PLAYER_HPP_INCLUDED
