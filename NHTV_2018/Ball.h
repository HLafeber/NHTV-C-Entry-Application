#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f position;

	// A RectangleShape object called ref
	RectangleShape ballShape;

	float xVelocity = .2f;
	float yVelocity = .2f;

public:
	// public functions to call in the header
	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();

	void hitBottom();

	void update();

};