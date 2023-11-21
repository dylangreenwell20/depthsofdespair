#pragma once

class Player {
public:
	void CreateCharacter(std::string playerName) { //function to take variables in and create a character
		name = playerName; //set name to player input

		//i do not need to set the race here as it is already set in the "CheckRace" function

		maxHealth = 100; //max health of the player
		damage = 10; //default damage value is 10
		depth = 1; //starting depth value
		restsLeft = 3; //rests per level

		if (race == "Human") { //if race is human
			damage = damage * 1.1; //modify damage
			maxHealth = maxHealth * 1.1; //modify health
		}
		if (race == "Orc") { //if race is orc
			damage = damage * 1.25; //modify damage
		}
		if (race == "Monk") { //if race is monk
			maxHealth = maxHealth * 1.25; //modify max health
		}

		health = maxHealth; //set health value to max health amount

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
		std::string damageString = std::to_string(damage); //convert damage to string

		std::cout << ("Name: " + name + "\nRace: " + race + "\nHealth: " + healthString + " / " + maxHealthString + "\nDamage: " + damageString + "\n\n-----------------------------------------\n\n"); //this will display the player's stats
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

	int GetCurrentHealth() { //function for passing on the 'current health' value
		return health;
	}

	int GetMaxHealth() { //function for passing on the 'max health' value
		return maxHealth;
	}

	int GetDamage() { //function for passing on damage value
		return damage;
	}

	std::string Heal() {  //heal before going deeper
		bool canHeal = CheckHeal(); //check if the player can heal
		if (canHeal) { //if player can heal
			if (health == maxHealth) {
				return("You have no need to rest as you are full health.\n\n");
			}
			else {
				int healthToRegen = maxHealth * 0.2; //amount of health to regen is 20% of the players' max health
				health = health + healthToRegen; //add health regen to health
				if (health > maxHealth) { //if health is over max health
					health = maxHealth; //health is set back to max health value
					restsLeft = restsLeft - 1; //take away a rest
					return("\nSuccessfully healed back up to full health.\n\n"); //output that the player is not full health
				}
				else {
					std::string healthToRegenString = std::to_string(healthToRegen); //convert regen value to string
					restsLeft = restsLeft - 1; //take away a rest
					return ("\nSuccessfully healed for " + healthToRegenString + " health.\n\n"); //output how much the player healed for
				}
				
			}
			
		}
		else { //if the player cannot rest
			return ("\nNo more rests left - it is time to venture forth...\n\n");
		}
	}

	bool CheckHeal() { //check if the player can heal
		if (restsLeft > 0) { //if the number of rests left is greater than 0
			return true;
		}
		else { //if the player has no more rests left
			return false;
		}
	}

	void TakeDamage(int takenDamage) { //receive damage from enemy attacks
		health = health - takenDamage; //take away damage from health
	}

	bool IsDead() { //function for checking if the player is dead
		if (health <= 0) { //if health is less than or equal to 0
			return true;
		}
		else { //else if health is more than 0
			return false;
		}
	}

	void IncreaseStats(int statToIncrease) { //function to increase player stats
		if (statToIncrease == 0) { //if statToIncrease is 0
			damage = damage + 5; //increase damage
		}
		else if (statToIncrease == 1) { //if statToIncrease is 1
			maxHealth = maxHealth + 10; //increase health by 10
		}
	}

	void ResetRestAmount() { //used to reset number of rests back to 3 after a fight
		restsLeft = 3;
	}

private:
	std::string name; //name of player's character
	std::string race; //race of player's character
	std::string availableRaces[3] = { "Human", "Orc", "Monk" }; //available races for player to pick from

	int health; //player health
	int maxHealth; //max health of the player
	int damage; //damage is how much the player can hurt the enemy
	int depth; //how far the player is in the dungeon - used to calculate when to show a chest room or boss
	int restsLeft; //how many times the player can rest - resting is used to regain hp when not in combat
};