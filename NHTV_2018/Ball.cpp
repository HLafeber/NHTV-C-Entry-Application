/**
 *	NHTV_2018, Ball.cpp
 *	Purpose: Ball Constructor/destructor
 *	
 *	@author(s) Harley Lafeber
 *	@version 0.1.001 (Game version, Code version, File version)
 *	@since $date$
 */

//Includes
#include "stdafx.h"
#include "Ball.h"

// This the constructor and it is called when we create an object
Ball::Ball(float startX, float startY)
{
	// Set the initial position of the ball
	position.x = startX;
	position.y = startY;

	ballShape.setSize(sf::Vector2f(10, 10));
	ballShape.setPosition(position);
}

// Return values to get boundaries of the ball
FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

// Return values to get the ball shape
RectangleShape Ball::getShape()
{
	return ballShape;
}

// Return horizontal velocity
float Ball::getXVelocity()
{
	return xVelocity;
}

// Bounce off the "wall"
void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

// Bounce of the top
void Ball::reboundBatOrTop()
{
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;

}

// reset ball if it hits the bottom
void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::update()
{
	// Update the ball position variables
	position.y += yVelocity;
	position.x += xVelocity;

	// Move the ball and the bat
	ballShape.setPosition(position);
}