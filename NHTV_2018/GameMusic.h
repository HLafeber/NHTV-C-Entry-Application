#ifndef __NHTV2018__GameMusic__
#define __NHTV2018__GameMusic__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/OpenGL.hpp>
using namespace std;
using namespace sf;


class GameMusic
{
public:
    bool playing;
    bool Steamfromfile(string path);
    void setLoop(bool state);
    void stop();
    void play();
    void mute();


private:
    sf::Music BackgroundMusic;




};




#endif /* defined(__Game1__GameMusic__) */
