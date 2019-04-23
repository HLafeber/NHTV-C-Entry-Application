/**
*	NHTV2018, RPGMain.cpp
*	Purpose: Entry point of the rpg
*
*	@author(s) Harley Lafeber
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 24/01/2018 18:00
*/

#include "stdafx.h"
#include "GamePlay.h"
using namespace sf;
using namespace std;




int RPGmain()
{
	float PlayerSpeed{ 3.f };
	GamePlay game("Game");


	if (!game.GamePlayInit())
	{
		cout << "Error While Initilizing the gameplay" << endl;
		return 1;
	}

	while (game.running) {
		cout << "Starting the game..." << endl;
		game.Start();
	}




	return 0;
}
