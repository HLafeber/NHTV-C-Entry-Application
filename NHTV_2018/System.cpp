/**
*	NHTV2018, System.cpp
*	Purpose: SFML base initlialization
*
*	@author(s) Harley Lafeber
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 24/01/2018 18:00
*/

//Includes
#include "stdafx.h"
#include "System.h"

///<summary>
///Creates the window
///</summary>
System::System(int width , int heigh , string title)
{
    window.create(VideoMode(width, heigh), title);
}

///<summary>
///Draws the sprite on the window
///</summary>
void DrawSprite(RenderWindow &win, sf::Sprite &objtodraw)
{
    win.draw(objtodraw);
}

///<summary>
///Create a (new) window using the variables
///</summary>
bool System::CreateSystem(int width , int heigh , string title , Uint32 flags, bool FullScreen)
{

    window.create(VideoMode(width, heigh), title, flags);

    return true;
}
