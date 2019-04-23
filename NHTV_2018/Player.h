#ifndef __Game1__Player__
#define __Game1__Player__

#include <iostream>

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <vector>
#include "System.h"



using namespace sf;
using namespace std;

class Player
{
public:

    int PlayerSpeed;
    Sprite psprite;
    Texture ptexture;
    int score;
    int sourceX;
    int sourceY;
    int sizePreSprite;
    FloatRect Bounds;
    Player(string filepath , int siplzePreSprite , int sourceX, int sourceY, int PlayerSpeed );
    Player();
    bool LoadFile(string filepath);
    void Move(RenderWindow &win , bool animate , int colliosionSide);
    void Move(RenderWindow &win , bool animate );
    void checkforcolision(RenderWindow &win);



};



#endif /* defined(__Game1__Player__) */
