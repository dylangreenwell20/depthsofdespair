#pragma once

class Player {
public:
	void CreateCharacter(std::string playerName) { //function to take variables in and create a character
		name = playerName; //set name to player input

		//i do not need to set the race here as it is already set in the "CheckRace" function

		maxHealth = 100; //max health of the player
		experience = 0; //start at 0 experience
		experienceGain = 1; //1 means 100%, so normal experience gain
		damage = 10; //default damage value is 10
		defence = 2; //default defence level
		level = 1; //players start on level 1
		depth = 1; //starting depth value

		if (race == "Human") { //if race is human
			experienceGain = experienceGain * 1.5; //modify experience gain
		}
		if (race == "Orc") { //if race is orc
			damage = damage * 1.25; //modify damage
		}
		if (race == "Stoneborn") { //if race is stoneborn
			defence = defence * 1.25; //modify defence
		}
		if (race == "Monk") { //if race is monk
			maxHealth = maxHealth * 1.25; //modify max health
		}

		health = maxHealth;

		std::cout << "\nRace selected. Welcome " + name + " the " + race + "!"; //welcome the created character
	}
	int CheckRace(std::string playerRace) { //check inputted race to see if it is a valid input
		int arrayLength = (sizeof(availableRaces) / sizeof(*availableRaces)); //get length of availableRaces array
		//std::cout << arrayLength; //for testing length of array

		bool validRace = false; //bool to see if a valid race was inputted

		std::transform(playerRace.begin(), playerRace.end(), playerRace.begin(), [](unsigned char c) {return std::tolower(c); }); //transform user input into all lower case


		for (int i = 0; i < arrayLength; i++) { //this loop repeats for the length of availableRaces

			std::string currentArrayItem = availableRaces[i]; //create variable for current array item

			std::transform(currentArrayItem.begin(), currentArrayItem.end(), currentArrayItem.begin(), [](unsigned char c) {return std::tolower(c); }); //convert array item to all lower case

			if (playerRace == currentArrayItem) { //if user input is equal to an element of position 'i' in the availableRaces array
				race = availableRaces[i]; //set player race to current item in array
				validRace = true; //valid race was selected
			}
		}
		if (validRace) { //if valid race is selected
			return true;
		}
		else { //else if a valid race was not inputted
			return false;
		}
	}

	void PlayerHud() { //display character stats at the top of the screen - this is used in rooms and not in combat (a different Hud will be used in combat)
		system("cls"); //clear console
		std::string healthString = std::to_string(health); //convert health to string
		std::string maxHealthString = std::to_string(maxHealth); //convert max health to string
		std::string levelString = std::to_string(level); //convert level to string
		std::string experienceString = std::to_string(experience); //convert experience to string
		std::string damageString = std::to_string(damage); //convert damage to string
		std::string defenceString = std::to_string(defence); //convert defence to string

		std::cout << ("Name: " + name + "\nRace: " + race + "\nLevel: " + levelString + "\nExperience: " + experienceString + " / 100" 
			+ "\nHealth: " + healthString + " / " + maxHealthString + "\nDamage: " + damageString + "\nDefence: " + defenceString + "\n\n-----------------------------------------\n\n"); //this will display the player's stats
	}

	void RoomHud() {
		std::string depthString = std::to_string(depth); //convert depth to string

		std::cout << ("Current Depth: " + depthString + "\n\nPlease select an action (enter the corresponding number):\n1 - Enter the next room...\n2 - Rest\n"); //commands the user can pick from
		if (depth == 1) { //if in the first room
			std::cout << ("3 - Leave\n"); //add an option to leave straight away
		}
	}

	int GetDepth() { //function for passing on the 'depth' value
		return depth;
	}

	void UpdateDepth(int newDepth) { //function to update the value of depth when the player goes deeper into the dungeon
		depth = newDepth; //set depth to new depth
	}

	void Heal(); //heal before going deeper

	void Attack(); //attack an enemy

	void Escape(); //escape from an enemy

	void Block(); //block an attack with a chance to counter attack

	void GoDeeper(); //go deeper into the dungeon

	void TakeDamage(); //receive damage from enemy attacks

private:
	std::string name; //name of player's character
	std::string race; //race of player's character
	std::string availableRaces[4] = { "Human", "Orc", "Stoneborn", "Monk" }; //available races for player to pick from

	int health; //player health
	int maxHealth; //max health of the player
	int experience; //when a player reaches 100 experience they will level up
	int experienceGain; //the rate at which the player gains experience
	int damage; //damage is how much the player can hurt the enemy - however the actual damage inflicted can be changed by up to -20%/+20%
	int defence; //defence is 1-10, so every enemy and the player will roll 0-10 each hit, if that roll is higher than the opponents defence then they will hit
	int level; //player level - each level the player will gain some max health and damage
	int depth; //how far the player is in the dungeon - used to calculate when to show a chest room or boss
	int restsLeft; //how many times the player can rest - resting is used to regain hp when not in combat

	bool canRest; //if the player is able to rest to restore hp
};