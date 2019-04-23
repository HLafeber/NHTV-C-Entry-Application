#ifndef __NHTV2018__System__
#define __NHTV2018__System__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
using namespace sf;
using namespace std;
class System {
public:
    RenderWindow window;
    
    void DrawSprite(RenderWindow &win,sf::Sprite &objtodraw);
    System(int width , int heigh , string title);
    bool CreateSystem(int width , int heigh , string title , Uint32 flags, bool FullScreen);
    
    
};

#endif /* defined(__NHTV2018__System__) */
