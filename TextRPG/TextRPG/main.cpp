#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include <string>
#include "player.h";
#include "enemy.h";

void LoadingText() { //simple decorative function to display loading text
	std::cout << "Loading game."; //display message
	Sleep(500); //wait for 0.5 seconds
	system("cls"); //clear console
	std::cout << "Loading game..";
	Sleep(500);
	system("cls");
	std::cout << "Loading game...";
	Sleep(500);
	system("cls");
	std::cout << "Loading game.";
	Sleep(500);
	system("cls");
	std::cout << "Loading game..";
	Sleep(500);
	system("cls");
	std::cout << "Loading game...";
	Sleep(500);
	system("cls");
}

//below are some intro text strings which are displayed after character creation
std::string textIntro1 = ("The day has come. You have reached the Dungeon of Despair in hopes to find a lost artifact - The Primordial Stone.\nWho knows what will be guarding this ancient artifact, but you won't let anything stop you.\n\n");
std::string textIntro2 = ("Pushing open the doors, you are immediately greeted with a stench unlike any other. Cobwebs cover every corner of the \nsmall entry room. No one has been down here for a very long time.\n\n");
std::string textIntro3 = ("Gritting your teeth, you grasp your trusty blade, alight your torch and set forth into the darkness...\n\n");

void IntroText(const std::string& introText) { //function for intro text which displays one letter at a time with low time intervals between letters
	system("cls"); //clear console
	for (size_t i = 0; i != introText.size(); i++) { //for the size of the string (in characters)
		std::cout << introText[i]; //print out a letter of the current word
		Sleep(10); //wait for 0.01 seconds 




		/*
		ALTER THE SLEEP VALUE FOR FINAL RELEASE ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^wdaiojwjiodajiowdiojawijdijawd jwadj iwajid wad powapod wad aw
		*/
	}
	system("pause"); //wait for user to press a button to continue
}


int main() {
	std::string tempName, tempRace; //temporary variables for storing player inputs
	bool validRace = false; //create boolean variable and set to false
	
	Player* player = new Player(); //instantiate new player class

	std::cout << "Enter character name: "; //ask player for name
	std::cin >> tempName; //store input to temporary name variable

	system("cls"); //clear console

	while (!validRace) { //while 'validRace' is set to false
		std::cout << "Please choose a race from the following: \nHuman (+50% experience gain)\nOrc (+25% damage)\nStoneborn (+25% defence)\nMonk (+25% health)\n\nYour race: "; //different races the player can pick from
		std::cin >> tempRace; //store input to temporary race variable
		validRace = player->CheckRace(tempRace); //bool value of validRace is set to the returned value of the function "CheckRace" in the "Player" class
		if (!validRace) { //if 'validRace' is still set to false
			system("cls"); //clear console
			std::cout << "Invalid input - please enter one of the available race names.\n\n";
		}
		else { //if a valid race was selected
			player->CreateCharacter(tempName); //create a character with the user's inputs
		}
	}

	Sleep(3000); //wait for 3 seconds
	system("cls"); //clear console

	LoadingText(); //display loading text

	IntroText(textIntro1); //play first text intro
	IntroText(textIntro2); //play second text intro
	IntroText(textIntro3); //play third text intro

	int depth = player->GetDepth(); //run function in Player class to get the depth
	bool invalidInput = false; //bool to check if the user has made an invalid input

	while (depth < 10) { //while depth is less than 10
		if (invalidInput) { //if user made an invalid input
			std::cout << ("Invalid action. Please enter a number of the action you want to choose."); //inform user the input was invalid
			system("pause"); //wait until the user presses a button to continue
		}

		system("cls"); //clear console

		player->PlayerHud(); //create player hud

		player->RoomHud(); //create room hud

		std::string userAction; //temp variable used to store the user's action
		bool actionValidation = false; //bool to check if the player entered a valid input
		std::cout << ("\nYour action: "); //text before the user's decision
		std::cin >> userAction; //store user's input to userAction variable

		depth++; //for testing - just increments the depth
		player->UpdateDepth(depth); //run function from Player class to update the depth value
	}

	

	
}

