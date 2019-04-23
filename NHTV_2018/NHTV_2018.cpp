/**
*	NHTV2018, NHTV_2018.cpp
*	Purpose: Defines the entry point for the console application.
*
*	@author(s) Harley Lafeber
*	@version 0.1.002 (Game version, Code version, File version)
*	@since 18/01/2018 18:00
*/

//TODO. Figure out how to CLS on linux based systems.
//TODO. Figure out how to use system("PAUSE") on linux based systems.
//TODO. Figure out how to add colour to the console output on linux based systems.

//Includes
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "game_lobby.h"
#include "Blackjack.h"
#include "simple_boss.h"
#include "Pong.h"
#include "RPGMain.h"
using namespace std;

//Global declaration because C++ can be retarded sometimes...
void main();

//User Menu loop
void menu()
{
	//Variable to allow character input
	int userInput = 0;

	//User Selection
	cin.clear(); //clear cinput to be sure no remenant info remains
	cout << "[1] RPG Boss Generator, [2] Blackjack, [3] Game Lobby [4] (SFML) Pong [5] (SDL) W.I.P RPG (unfinished) [6] Exit \n";
	cin >> userInput;

	switch (userInput)
	{
	case 1: cout << "user pressed 1";
		system("CLS");	//clear screen !Note, CLS only works on WINDOWS systems
		SBmain();		//Run Simple Boss Loop
		cin.clear();	//clear input
		break;
	case 2: cout << "user pressed 2";
		system("CLS");	//clear the screen
		BJmain();		//Run BlackJack Main loop
		cin.clear();
		break;
	case 3: cout << "user pressed 3";
		system("CLS");	//clear the screen
		glmain();		//run Game Lobby Main loop
		cin.clear();
		break;
	case 4: cout << "user pressed 4";
		system("CLS");	//Clear the screen
		PONGmain();		//start up pong
		cin.clear();
	case 5: cout << "user pressed 5";
		system("CLS");	//Clear screen
		RPGmain();		//Start up SleepWalker
		cin.clear();
		menu();
	case 6: cout << "bye bye \n";
		system("PAUSE");// Wait for user input before shutting down the application !Note, PAUSE only works on WINDOWS systems
		break;
	default: cout << "Incorrect input, please try again\n";
		cin.clear();				//Clear console input to prevent infinite looping code
		cin.ignore(INT_MAX, '\n');	//Set the input to ignore the maximum int cap (can occasionally cause issues)
		menu();						//Go back to the start of this input selection, to prevent spamming the console with the same text over and over again.
		break;
	}
}

void InitDiscord();
//main application loop
void main()
{

	//Console text explaining this program / Funky ascii art
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "::::    ::: :::    ::: ::::::::::: :::     :::       ::::::::   :::::::    :::   ::::::::  \n";
	cout << ":+:+:   :+: :+:    :+:     :+:     :+:     :+:      :+:    :+: :+:   :+: :+:+:  :+:    :+: \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 );
	cout << ":+:+:+  +:+ +:+    +:+     +:+     +:+     +:+            +:+  +:+  :+:+   +:+  +:+    +:+ \n";
	cout << "+#+ +:+ +#+ +#++:++#++     +#+     +#+     +:+          +#+    +#+ + +:+   +#+   +#++:++# \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "+#+  +#+#+# +#+    +#+     +#+      +#+   +#+         +#+      +#+#  +#+   +#+  +#+    +#+ \n";
	cout << "#+#   #+#+# #+#    #+#     #+#       #+#+#+#         #+#       #+#   #+#   #+#  #+#    #+# \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "###    #### ###    ###     ###         ###          ##########  #######  ####### ########  \n";
	cout << "========================================================================================== \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "###    #### ###    ###     ###         ###          ##########  #######  ####### ########  \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "  :+:   :+:+: :+:    :+:     :+:       :+:+:+:         :+:       :+:   :+:   :+:  :+:    :+: \n";
	cout << "+#+  +#+#+# +#+    +#+     +#+      +#+   +#+         +#+      +#+#  +#+   +#+  +#+    +#+ \n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\n";
	cout << "Heya! Allow me to introduce myself. \n";
	cout << "I'm Harley Lafeber, and this is one of my programs for NHTV's Intake test in 2018. \n";
	cout << "As you can see, this program/code is rather basic. But hey, basic things have their charm~ \n";
	cout << "This program is mainly made by me, following 'Michael Dawson's' \n";
	cout << "'Beginning C++ Through Game Programming (fourth edition) Book. \n";
	cout << "The programs contained in here are mostly modified versions of the ones tought in that book. \n";
	cout << " \n";
	cout << "That all said, I did have a lot of fun making this programm, and I hope I'll get accepted this year. \n";
	cout << "So I can learn even more about the wonderfull world of making games \n";
	cout << "\n";
	cout << "============================================================================================================ \n";
	
	menu();
	InitDiscord();
}




