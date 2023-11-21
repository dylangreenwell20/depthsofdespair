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
		Sleep(50); //wait for 0.05 seconds 
	}
	system("pause"); //wait for user to press a button to continue
}

void StartMenu() { //start menu screen
	bool gameStarted, tutorialLoaded; //boolean variables for if the game has to be started and if the tutorial was selected
	gameStarted = false;
	tutorialLoaded = false;
	while (!gameStarted) { //while game hasnt started
		system("cls"); //clear console
		if (tutorialLoaded) { //if tutorial was selected to load
			std::cout << ("Welcome to Depths of Despair - a dungeon crawler text RPG game!");
			std::cout << ("\n\nTutorial Screen");
			std::cout << ("\n\nIn this game, the objective is to make it to the end of the dungeon - there are a total of 10 rooms.");
			std::cout << ("\n\nAs you progress, you will encounter enemies and have turn-based combat against them. If you manage to\n");
			std::cout << ("defeat the enemy, you will receive a stat increase.\n");
			std::cout << ("\nAfter combat, you can rest. Resting is important as it allows you to recover health\n");
			std::cout << ("between fights, and you only get 3 rests each floor so make sure to make the most out of them!");
			std::cout << ("\n\nBest of luck! (p.s. death means you have to restart, i pray the rng works out for you :) )\n\n");
			tutorialLoaded = false; //tutorial has been displayed so the main menu will be loaded on next loop
			system("pause"); //wait for user to press a button
		}
		else { //if tutorial wasnt selected to load
			std::cout << ("Welcome to Depths of Despair - a dungeon crawler text RPG game!");
			std::cout << ("\n\nPlease select an option from below (enter the number corresponding to the action): \n1 - Start Game\n2 - Tutorial Screen\n\n");
			std::string userInput; //create user input variable
			std::cout << ("Your action: ");
			std::cin >> userInput; //store user input
			if (userInput == "1") { //if user picked 'Start Game'
				gameStarted = true; //end while loop
				system("cls"); //clear the screen
				LoadingText(); //display loading text
			}
			else if (userInput == "2") { //if user picked 'Tutorial Screen'
				tutorialLoaded = true; //load the tutorial on next loop
			}
			else{ //else if the input was invalid
				system("cls"); //clear console
				std::cout << ("Invalid input. Please enter either 1 or 2.\n\n");
				system("pause"); //wait for user input
			}
		}
	}
}

//below are some intro text strings which are displayed for the endings of the game
std::string textBadEnding = ("Immediately regretting your life decisions, you swiftly turn around and leave the dungeon. Maybe it was for the best...\n\n");
std::string textGoodEnding1 = ("As you enter the next room, you are slowly enveloped by a golden glow. Could it be? The Primordial Stone?\n\n");
std::string textGoodEnding2 = ("Getting closer, you can start to make out the shape of the ancient artifact. After all your life, you are finally\nwithin arms reach of such a delicate but powerful relic of the past.\n\n");
std::string textGoodEnding3 = ("You put the stone into your backpack and slowly begin to ascend the dungeon - carefully stepping over the\ndismembered enemies who stood in your way.\n\n");
std::string textGoodEnding4 = ("At long last, you are greeted by the warmth of the sun. Your quest may be over, but your journey has only just begun...\n\n");

void EndingText(const std::string& endingText) { //function for intro text which displays one letter at a time with low time intervals between letters
	system("cls"); //clear console
	for (size_t i = 0; i != endingText.size(); i++) { //for the size of the string (in characters)
		std::cout << endingText[i]; //print out a letter of the current word
		Sleep(50); //wait for 0.05 seconds 
	}
	system("pause"); //wait for user to press a button to continue
}

int main() {
	StartMenu(); //load start menu

	std::string tempName, tempRace; //temporary variables for storing player inputs
	bool validRace = false; //create boolean variable and set to false

	Player* player = new Player(); //instantiate new player class
	Enemy* enemy = new Enemy(); //instantiate new enemy class

	std::cout << "Enter character name: "; //ask player for name
	std::cin >> tempName; //store input to temporary name variable

	system("cls"); //clear console

	while (!validRace) { //while 'validRace' is set to false
		std::cout << "Please choose a race from the following: \nHuman (+10% health and damage)\nOrc (+25% damage)\nMonk (+25% health)\n\nYour race: "; //different races the player can pick from
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

	bool choosingToSkip = true;

	while (choosingToSkip) {
		system("cls"); //clear the screen
		std::cout << ("Would you like to skip the intro text? (please answer with the corresponding number to the action)\n1 - Yes\n2 - No\n\nYour action: "); //ask if player wants to skip intro
		std::string introSkip; //create string variable
		std::cin >> introSkip; //store user input to variable

		if (introSkip == "1") {//intro skipped
			choosingToSkip = false; //loop can end
		}
		else if (introSkip == "2") { //if player chose to not skip the intro
			choosingToSkip = false; //loop can end
			IntroText(textIntro1); //play first text intro
			IntroText(textIntro2); //play second text intro
			IntroText(textIntro3); //play third text intro
		}
		else {
			system("cls"); //clear the screen
			std::cout << ("Invalid input - please enter either 1 or 2.\n\n");
			system("pause"); //wait for user input
		}
	}

	int depth = player->GetDepth(); //run function in Player class to get the depth
	std::string depthString = std::to_string(depth); //convert integer to string
	bool invalidInput = false; //bool to check if the user has made an invalid input

	while (depth < 11) { //while depth is less than 11 (10 total rooms)
		if (invalidInput) { //if user made an invalid input
			std::cout << ("Invalid action. Please enter a number of the action you want to choose."); //inform user the input was invalid
			system("pause"); //wait until the user presses a button to continue
		}

		system("cls"); //clear console

		player->PlayerHud(); //create player hud

		player->RoomHud(); //create room hud

		player->ResetRestAmount(); //reset amount of rests/heals the user has - sets it back to 3

		std::string userAction; //temp variable used to store the user's action
		std::cout << ("\nYour action: "); //text before the user's decision
		std::cin >> userAction; //store user's input to userAction variable

		if (userAction == "1") { //if player has chosen to enter the next room
			int playerDamage = player->GetDamage(); //get player damage
			int tempPlayerMaxHealth = player->GetMaxHealth(); //get max health to calculate enemy max health

			std::string playerDamageString = std::to_string(playerDamage); //convert player damage integer to a string

			std::string currentEnemyName = enemy->GenerateName(); //generate a name for the current enemy
			enemy->SetStats(tempPlayerMaxHealth); //set enemy stats to scale with the player

			int enemyDamage = enemy->GetDamage(); //get enemy damage

			std::string enemyDamageString = std::to_string(enemyDamage); //convert enemy damage integer to string

			bool combatActive = true; //currently in combat phase
			bool isPlayerTurn = true; //player always goes first
			bool playerWon; //check if the player won in combat

			while (combatActive) { //while in combat
				system("cls"); //clear console

				int playerCurrentHealth = player->GetCurrentHealth(); //get player current health
				int playerMaxHealth = player->GetMaxHealth(); //get player max health

				std::string playerCurrentHealthString = std::to_string(playerCurrentHealth); //convert current health to string
				std::string playerMaxHealthString = std::to_string(playerMaxHealth); //convert max health to string

				int enemyHealth = enemy->GetHealth(); //get enemy health
				int enemyMaxHealth = enemy->GetMaxHealth(); //get enemy max health

				std::string enemyHealthString = std::to_string(enemyHealth); //convert integer to string
				std::string enemyMaxHealthString = std::to_string(enemyMaxHealth); //convert integer to string

				//below creates a simple hud for the fight
				std::cout << ("YOUR CHARACTER\n\nName: " + tempName + "\nHealth: " + playerCurrentHealthString + " / " + playerMaxHealthString);
				std::cout << ("\n---------------");
				std::cout << ("\nTHE ENEMY\n\nName: " + currentEnemyName + "\nHealth: " + enemyHealthString + " / " + enemyMaxHealthString);
				std::cout << ("\n---------------");
				std::cout << ("\nCOMBAT LOG\n\n");

				bool isPlayerDead, isEnemyDead; //bools for checking if someone has died in combat

				if (isPlayerTurn) { //if it is player's turn to attack
					std::cout << ("You hit the enemy for " + playerDamageString + "!"); //display combat message
					enemy->TakeDamage(playerDamage); //take away damage
					isEnemyDead = enemy->IsDead(); //check if enemy is dead
					isPlayerTurn = false; //now it is the enemy's turn
					Sleep(2000); //wait for 2 seconds
					if (isEnemyDead) { //if enemy has died
						combatActive = false; //end combat phase
						std::cout << ("\n\nYou are victorious!");
						playerWon = true; //player has won
						Sleep(2000); //wait for 2 seconds
					}
				}
				else { //enemy's turn to attack
					std::cout << (currentEnemyName + " hit you for " + enemyDamageString + "!"); //display combat message
					player->TakeDamage(enemyDamage); //take away damage
					isPlayerDead = player->IsDead(); //check if player is dead
					isPlayerTurn = true; //now it is the player's turn
					Sleep(2000); //wait for 2 seconds
					if (isPlayerDead) { //if player has died
						combatActive = false; //end combat phase
						std::cout << ("\n\nYou died!");
						playerWon = false; //player died and lost
						Sleep(2000); //wait for 2 seconds
					}
				}
			}
			
			if (playerWon) { //if player won the fight
				system("cls"); //clear screen

				bool choosingUpgrade = true; //bool to run while loop while player is choosing upgrade

				while (choosingUpgrade) {
					system("cls"); //clear screen
					std::cout << ("Congratulations! You can upgrade a stat! Would you like:\n1 - +5 damage\n2 - +10 health\n\n");
					std::string userAnswer; //create variable to store user input
					std::cout << ("Your choice: ");
					std::cin >> userAnswer; //store user input

					if (userAnswer == "1") { //if user picked to ugprade damage
						int increasedStat = 0; //set increasedStat to 0 which is the 'damage' stat
						system("cls"); //clear screen
						std::cout << ("Congratulations! You have gained +5 damage!\n\n");
						player->IncreaseStats(increasedStat); //run IncreaseStats function using increasedStat variable of '0' to increase damage
						choosingUpgrade = false; //player no longer choosing an upgrade
						system("pause"); //wait for user input
					}
					else if (userAnswer == "2") {
						int increasedStat = 1; //set increasedStat to 1 which is the 'health' stat
						system("cls"); //clear screen
						std::cout << ("Congratulations! You have gained +10 health!\n\n");
						player->IncreaseStats(increasedStat); //run IncreaseStats function using increasedStat variable of '1' to increase health
						choosingUpgrade = false; //player no longer choosing an upgrade
						system("pause"); //wait for user input
					}
					else {
						system("cls"); //clear screen
						std::cout << ("Invalid input. Please enter either 1 or 2.\n\n");
						system("pause"); //wait for user input
					}
				}

				depth++; //increase depth
				depthString = std::to_string(depth); //update string of depth so the program can output the string if the player dies
				player->UpdateDepth(depth); //update depth in Player class
			}
			else { //else if the player lost the fight
				system("cls"); //clear screen
				std::cout << ("You perished to a " + currentEnemyName + " at a depth of " + depthString + ".\n\n"); //display death message
				system("pause\n\n"); //wait for user input
				exit(0); //exit the game
			}
		}
		else if (userAction == "2") { //else if player has chosen to rest/heal
			std::string healOutput = player->Heal(); //create string variable and assign it the output of the Player :: Heal() function
			std::cout << (healOutput); //output whether the player healed or not
			system("pause"); //wait for user input
		}
		else if (depth == 1) { //if player is in the first room
			if (userAction == "3") { //if player has chose to leave
				EndingText(textBadEnding); //display bad ending text
				exit(0); //exit the game
			}
		}
	}

	//GOOD ENDING REACHED - GAME BEATEN

	system("cls"); //clear screen
	EndingText(textGoodEnding1); //display good ending text
	EndingText(textGoodEnding2);
	EndingText(textGoodEnding3);
	EndingText(textGoodEnding4);
	exit(0); //exit the game
}

