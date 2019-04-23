/**
*	NHTV2018, Enviroment.cpp
*	Purpose: System to handle drawing and loading of objects, sprites and their collision
*
*	@author(s) Harley Lafeber, Alexander Nahapetyan
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 24/01/2018 18:00
*/

#include "stdafx.h"
#include "Environment.h"
#include "Player.h"
///<summary>
///Draws the background
///</summary>
void Environment::DrawBackground( RenderWindow &win)
{
    win.draw(BackgroundSprite);	  //create background sprite for current window
}

///<summary>
///Load trees from file
///</summary>
bool Environment::LoadTreeFiles(string filepath , RenderWindow &win , int x , int y , int w , int h)
{
	//if error, handle the error properly (rather than throwing an exception and crashing the entire program)
    if (!TreeTexture.loadFromFile(filepath, IntRect(x, y , w, h)))
    {
        cout << "Error while loading the Tree Texture in Envirement.cpp " << &err();
        return false;
    }
    Tree.setTexture(TreeTexture);	//Set tree texture using specified tilesheet
    return true;					//Sucsessfull loaded the base tree
}

///<summary>
///Load the background from fle
///</summary>
bool Environment::LoadBackgroundFile(string filepath, RenderWindow &win)
{
	//if error, handle the error properly (rather than throwing an exception and crashing the entire program)
    if (!BackgroundTexture.loadFromFile(  filepath))
    {
        cout << "Error While Loading the Image from the path " <<  &err() << endl;
        return false;
    }

    BackgroundTexture.setRepeated(true);				//Set texture to repeat (if screen window is too high, or texture is too small)

    BackgroundSprite.setTexture(BackgroundTexture);		//Sets texture fromt file

    BackgroundSprite.setScale(win.getSize().x / 600.f, win.getSize().y / 600.f);	//Set scale to match the original scale
    BackgroundSprite.setOrigin(0, 0);												//Set position of the texture to be top left (x=0,y=0)
    return true;
}

///Base Extension
Environment::Environment()
{

}

///<summary>
///Plases trees on screen using defined render window, and position
///</summary>
void Environment::DrawTrees(  RenderWindow &win, int x , int y)
{
    vector<int> CurrentClocation;
    CurrentClocation.push_back(x);
    CurrentClocation.push_back(y);
    TreeLocations.push_back(CurrentClocation);
    Tree.setPosition(x, y);
    win.draw(Tree);
}

///<summary>
///Redraws the trees on screen
///</summary>
void Environment::RefreshTrees(RenderWindow &win)
{
    for (unsigned int i = 0; i < TreeLocations.size() ; i++ )
    {
        Tree.setPosition(TreeLocations.at(i).at(0), TreeLocations.at(i).at(1));
        win.draw(Tree);
    }
}

///<summary>
///Checks if the player collides with the trees, and triggers proper collision parameters
///</summary>
int Environment::CheckforColisionwithTrees(Player &p)
{
    for (unsigned int i = 0; i < TreeLocations.size() ; i++ ) //TO DO Change to an iterators Loop
    {
        Tree.setPosition(TreeLocations.at(i).at(0), TreeLocations.at(i).at(1));
        //Boundaries
    	TreeBounds = Tree.getGlobalBounds();			//retrieve global boundaries of object
        TreeBounds.left += 18;			//Extend the boundaries by 18 to the left
        TreeBounds.top += 47;			//Extends the boundaries by 47 on top
        TreeBounds.width -= 28;			//Reduces the total width of the boundaries by 28
        TreeBounds.height -= 47;		//Reduces the total height by 47
        FloatRect CollisionArea;		//Create a rectangle collision area

		//Check if a object collides with the collision area
        if (TreeBounds.intersects(p.Bounds , CollisionArea))
        {
            if (CollisionArea.width > CollisionArea.height)
            {
                //Collision is ether form top or bottom
                if (CollisionArea.contains({CollisionArea.left , p.psprite.getPosition().y}))
                {
                    //Something is Coliding with the Bottom of the Tree
                    return 8;
                } else
                {
                    //Something is coliding with the Top of the Tree
                    return 4;
                }
            }
            if (CollisionArea.width < CollisionArea.height)
            {
                //Collision is either form left or Right
                if (CollisionArea.contains({p.psprite.getPosition().x + p.psprite.getGlobalBounds().width - 1.f, CollisionArea.top + 1.f}))
                {
                    //The Left Side of the Tree is hit
                    return 1;
                } else
                {
                    return 2;
                }
            }
        }
    }

    return 0;
}

