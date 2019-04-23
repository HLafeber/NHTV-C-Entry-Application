/**
*	NHTV2018, GameMusic.cpp
*	Purpose: Global Music system to start and stop music
*
*	@author(s) Harley Lafeber, Alexander Nahapetyan
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 24/01/2018 18:00
*/


#include "stdafx.h"
#include "GameMusic.h"
///<summmary>
///Stops the music
///</summary>
void GameMusic::stop()
{
    BackgroundMusic.stop();
}
///<summary>
///Pauses the music
///</summary>
void GameMusic::mute()
{
    BackgroundMusic.pause();
}
///<summary>
///Plays currently loaded song (initalize with Streamfromfile)
///</summary>
void GameMusic::play()
{
    BackgroundMusic.play();
}
///<summary>
///Stream the song from file
///</summary>
bool GameMusic::Steamfromfile(string path)
{
    if (!BackgroundMusic.openFromFile(path))
    {
        return false;
    }
    return true;
}
///<summary>
///Set the music to loop
///</summary>
void GameMusic::setLoop(bool state)
{
    BackgroundMusic.setLoop(state);
}