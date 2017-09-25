#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player
{
    public:
         Player(); //Constructor
         Player(sf::Texture& texture, int x, int y); //Overload Constructor
         ~Player(); //Destructor

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
        int directionOffset; // Right -> 0, Left -> +4
        void setTextureForFrame();
};

#endif // PLAYER_HPP_INCLUDED
