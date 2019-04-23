/**
*	NHTV2018, Pong.cpp
*	Purpose: A simple pong game to try out SFML.
*
*	@author(s) Harley Lafeber
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 22/01/2018 12:00
*/

//Includes
#include "stdafx.h"
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML\Graphics.hpp>
#include <iostream>
#include "NHTV_2018.h"

//avoid having to put sf in front of all the SFML classes and functions
using namespace sf;
//Pong functions
//start game
int PONGmain()
{
	int windowWidth = 1024;
	int windowHeight = 768;
	// Make a window that is 1024 by 768 pixels
	// And has the title "Pong"
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

	int score = 0;
	int lives = 3;

	// create a bat
	Bat bat(windowWidth / 2, windowHeight - 20);

	// create a ball
	Ball ball(windowWidth / 2, 1);

	//create a "Text objecting called "hud".
	Text hud;

	//using font "Gravity Light"
	Font font;
	font.loadFromFile("Gravity-Light.otf");

	//set font on hud
	hud.setFont(font);

	//make font bigger
	hud.setCharacterSize(75);

	//set font color
	hud.setFillColor(sf::Color::Color(143, 66, 244));

	//while loop to keep playing while the window is open.

	/* Personal note:

	I could probably use a switch function here...

	*/
	while (window.isOpen())
	{
		/*
		Player input handler
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Window closed, end program
				window.close();

		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			// move bat left
			bat.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			// move bat right
			bat.moveRight();

		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			//quiting game.
			//Game end cause Escape was pressed.
			window.close();
			std::cin.clear();//clear any input
			main();			//return to main program

		}
		/*
		Update the frame
		*/

		// Handle ball hitting the bottom
		if (ball.getPosition().top > windowHeight)
		{
			// reverse the ball direction
			ball.hitBottom();

			// Remove a life
			lives--;

			// Check for zero lives
			if (lives < 1) {

				//Game Over
				std::stringstream ss;
				ss << "Game Over";
				hud.setString(ss.str());
				std::cout << "Game Over \n";
				window.close();
				main();

			}

		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();

			// Add a point to the players score
			score++;

		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			// Hit detected so reverse the ball and score a point
			ball.reboundBatOrTop();
		}
		ball.update();
		bat.update();

		// Update the HUD text
		std::stringstream ss;
		ss << "Score:" << score << "    Lives:" << lives;
		hud.setString(ss.str());

		/*
		Draw the frame
		*/

		// Clear everything from the last frame
		// Color is in RGBA format for background
		// this color variable controll's the background color
		window.clear(Color(0, 0, 0, 255));

		window.draw(bat.getShape());

		window.draw(ball.getShape());

		// Draw our score
		window.draw(hud);

		// Show everything we just drew
		window.display();
	}// This is the end of the "while" loop

	return 0;
};
