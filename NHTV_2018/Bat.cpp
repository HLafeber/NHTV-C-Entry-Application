/**
*	NHTV_2018, Bat.cpp
*	Purpose: Bat Constructor/Controller
*
*	@author(s) Harley Lafeber
*	@version 0.1.001 (Game version, Code version, File version)
*	@since $date$
*/

//Includes
#include "stdafx.h"
#include "Bat.h"

//Constructor to create object
Bat::Bat(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	batShape.setSize(sf::Vector2f(50, 5));
	batShape.setPosition(position);

}

// Return boundaries for the bat
FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();

}

// Get the shape of the bat
RectangleShape Bat::getShape()
{
	return batShape;

}

// Move left function
void Bat::moveLeft()
{
	position.x -= batSpeed;
}
// Move right function
void Bat::moveRight()
{
	position.x += batSpeed;
}
// Update position on screen
void Bat::update()
{
	batShape.setPosition(position);
}