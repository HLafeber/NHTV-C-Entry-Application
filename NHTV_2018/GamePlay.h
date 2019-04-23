#ifndef __NHTV2018__GamePlay__
#define __NHTV2018__GamePlay__
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <vector>
#include "System.h"

#include "Player.h"
#include <math.h>
#include "Environment.h"
#include "GameMusic.h"
#include <ctime>
#include "UserInterface.h"
#include <cstdlib>
using namespace sf;
using namespace std;

class GamePlay
{
public:
    GamePlay(string name);
    float PlayerSpeed {3.f};
    Environment env;
    System system;
    Player player;
    Event event;
    Font font;
    GameMusic BackgroundMusic;
    Clock clock;
    float oldTime;
    float currentTime;
    bool GamePlayInit();
    bool Start();
    bool running;
    void GameEventHandler();
    UserInterface UI;
private:
    void DrawStaticObjects();


};
#endif /* defined(__Game1__GamePlay__) */
