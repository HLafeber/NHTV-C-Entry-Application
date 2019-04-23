/**
*	NHTV2018, Player.cpp
*	Purpose: Base Player controller
*
*	@author(s) Harley Lafeber, Alexander Nahapetyan
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 24/01/2018 18:00
*/

#include "stdafx.h"
#include "Player.h"

using namespace sf;
using namespace std;

Player::Player(string filepath , int sizePreSprite , int sourceX, int sourceY  , int PlayerSpeed)
{
    filepath = filepath;
    Player::sizePreSprite = sizePreSprite;
    Player::sourceX = sourceX;
    Player::sourceY = sourceY;
    LoadFile(filepath);
    Player::PlayerSpeed = PlayerSpeed;


}
bool Player::LoadFile(string filepath)
{

    if (!ptexture.loadFromFile(  filepath))
    {
        cout << "Error While Loading the Image from the path " <<  &err() << endl;
        return false;
    }
    psprite.setTexture(ptexture);

    Player::Bounds = psprite.getGlobalBounds();
	psprite.setPosition(0, 500); //Set player in the proper default position
    return true;
}

void Player::Move(RenderWindow &win , bool animate , int colliosionSide)
{
    enum PositionToCrop {DOWN, LEFT , RIGHT , UP};
    int times;



    if (Keyboard::isKeyPressed(Keyboard::Key::LShift))
    {
        times = 2;
    }
    else
    {
        times = 0;
    }
    psprite.setTextureRect(IntRect(sourceX * 32 , sourceY * 32 , 32 , 32));



    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        sourceY = LEFT;

        if (psprite.getPosition().x >= 0 && colliosionSide != 2)
        {
            psprite.move(-PlayerSpeed - times, 0);
        }
        if (animate)
        {
            sourceX++;
            if (sourceX > 2)
            {
                sourceX = 0;
            }
        }
    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        sourceY = RIGHT;

        if (psprite.getPosition().x <= win.getSize().x - sizePreSprite && colliosionSide != 1)
        {
            psprite.move(PlayerSpeed + times, 0);
        }
        if (animate)
        {
            sourceX++;
            if (sourceX > 2)
            {
                sourceX = 0;
            }
        }
    }


    else if (Keyboard::isKeyPressed(Keyboard::Key::Up) )
    {
        sourceY = UP;

        if (psprite.getPosition().y >= 0 && colliosionSide != 8)
        {
            psprite.move(0, -PlayerSpeed - times);
        }
        if (animate)
        {
            sourceX++;
            if (sourceX > 2)
            {
                sourceX = 0;
            }
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Down))
    {
        sourceY = DOWN;

        if (psprite.getPosition().y <= win.getSize().y - sizePreSprite && colliosionSide != 4)
        {
            psprite.move(0, PlayerSpeed + times);
        }
        if (animate)
        {
            sourceX++;
            if (sourceX > 2)
            {
                sourceX = 0;
            }
        }
    }

    // DO NOT DELETE AND DO NOT UNCOMMENT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
    {
        win.setFramerateLimit(0);
    }
    //Press L to activate speed Limit Braker
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U))
    {
        win.setFramerateLimit(60);
    }
    //BELIVE ME YOU DON"T WNAT TO SEE WHAT WILL HAPPEN
    Bounds = psprite.getGlobalBounds();
}

void Player::Move(RenderWindow &win , bool animate )
{


}
Player::Player()
{

}














