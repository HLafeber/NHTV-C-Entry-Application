/**
*	NHTV2018, GamePlay.cpp
*	Purpose: Initialize the game and create the assets on the window
*
*	@author(s) Harley Lafeber, Alexander Nahapetyan
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 24/01/2018 18:00
*/

#include "stdafx.h"
#include "GamePlay.h"
#include <fstream>
#include <cstdio>
using namespace  std;
using namespace  sf;

int amounOfTrees {100};


///<Summary>
///Create the window using SFML
///</Summary>
GamePlay::GamePlay(string name):
    system(600, 600, "NHTV_2018") //Create the window
{
    system.window.setFramerateLimit(30);	//Set game to 30FPS for startup
    running = true;							//While true = Keep game going
}


///<Summary>
///Initalize the gameplay
///</Summary>
bool GamePlay::GamePlayInit()
{

	//Player Initialization
    system.window.setFramerateLimit(60);						//Up framerate to 60
    player = Player("Images/Player_Male.png", 32 , 0, 0, 2);	//Load player, sprite sheet 32x32 pixels, position x=0,y=0, player speed 2. 
    if (!player.LoadFile("Images/Player_Male.png"))				//If sprite can't be loaded, throw in an error
    {
        cout << "Failed Loading Players SpriteSheet" << endl;
        running = false;
        return false;
    }
    
	//Background Initialization
    if (!env.LoadBackgroundFile("Images/BackgroundGrass.png" , system.window))
    {
        cout << "Failed to load the Background Image " << endl;
        running = false;
        return false;
    }
    if (!env.LoadTreeFiles(   "Images/EnvironmentTiles_Moosader.png", system.window, 0, 64, 64, 64))
    {
        cout << "Failed to load Tree Sprite Files " << endl;
        running = false;
        return false;
    }
    if (!UI.LoadSptireFiles("Images/DialogBox.png", system.window))
    {
        cout << "Failed to load the UI elements either the Xml file or the png" << endl;


        return false;
    }
	//Font used
    if (!font.loadFromFile(   "Font/sansation.ttf"))
    {
        cout << "Error While Loading the Fond File " << endl;
        return false;
    }

	//Drawing Trees
    env.DrawTrees(system.window, 312, 450);
    env.DrawTrees(system.window, 521, 450);
    env.DrawTrees(system.window, 412, 450);
    env.DrawTrees(system.window, 543, 450);
    env.DrawTrees(system.window, 231, 450);
    env.DrawTrees(system.window, 312, 450);

    oldTime = 0;								//Reset old time
    currentTime = 0;							//Reset current time
    system.window.setMouseCursorVisible(false);	//Hide cursor

    running = true;
    return true;
}

///<summary>
///Draw objects on the screen
///<summary>
void GamePlay::DrawStaticObjects()
{
    env.DrawBackground(system.window);	//Draws background
    system.window.draw(player.psprite);	//Draws the player
    env.RefreshTrees(system.window);	//Redraws the trees
}

///<summary>
///Event handler to handle events (e.g diolouge)
///</summary>
void GamePlay::GameEventHandler()
{

    if (env.CheckforColisionwithTrees(player) > 0)	//if player collides with (any) trees
    {
        if (event.key.code == Keyboard::Space )		//And presses space
        {
            UI.dialogLine = 1;						//Load diaolog line 1
            if (!UI.LoadTextFile("Dialogs/Trees/Normal.txt"))
            {
                cout << "Can't Open The Dialog File for Tree " << endl;
                return;
            }
			//draw ui elements
            UI.firstDraw = true;
            UI.Drawstringline1 = " ";
            UI.Drawstringline2 = "";
            UI.Drawstringline3 = "";
            
        	//create a new clock and timer
        	sf::Clock clock;
			Time newTime;
            
			//continue chat box when right shift is pressed, or closes it if no text exists.
        	while (event.key.code != Keyboard::RShift)
            {

                system.window.pollEvent(event);


                cout << "The Time is " << newTime.asMilliseconds() << endl;

                if (UI.firstDraw)
                { 
                    unsigned int i = 0;
                    unsigned int textStringLength = UI.TextString.length();
                    while (i < textStringLength )
                    {
                        if (newTime.asMilliseconds() > 25)
                        {

                            DrawStaticObjects();
                            UI.CreateADialogFromTextFile( 29, font, system.window, i);
                            i++;
                            newTime = clock.restart();
                            newTime = clock.restart();
                            
                        }
                        else
                        {
                    
                            newTime = clock.getElapsedTime();
                        }
                    }
                }
                else
                {
                    DrawStaticObjects();
                    UI.CreateADialogFromTextFile( 29, font, system.window, UI.TextString.length());
                }
                newTime = clock.restart();



            }
            UI.Drawstringline1 = " ";
            UI.Drawstringline2 = "";
            UI.Drawstringline3 = "";
        }
        UI.File.close();
    }






}






bool GamePlay::Start()
{


    while ( system.window.isOpen())
    {

        while(system.window.pollEvent(event)){

        if (event.type == Event::Closed)
        {
            cout << "Closing event detected" << endl;
            system.window.close();

        }
}
        currentTime =  clock.restart().asSeconds();


        //      float timepassed =  ( oldTime - currentTime);
        //        cout << "Time passed is " << timepassed << endl;

        if (oldTime >= .20)
        {
            player.Move(system.window, true, env.CheckforColisionwithTrees(player));

            oldTime = 0;

        }
        else
        {
            player.Move(system.window, false, env.CheckforColisionwithTrees(player));
        }


        GameEventHandler();

        if (Keyboard::isKeyPressed(Keyboard::Key::M))
        {
            if (BackgroundMusic.playing)
            {
                BackgroundMusic.mute();
                BackgroundMusic.playing = false;
            }
            else
            {
                BackgroundMusic.play();
                BackgroundMusic.playing = true;
            }
        }


        oldTime +=  currentTime ;
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
        {
            system.window.close();
            break;

        }
        DrawStaticObjects();
        system.window.display();
        system.window.clear();

    }
    BackgroundMusic.stop();
    running = false;
    return true;
}





