#pragma once

class Enemy {
public:
	std::string GenerateName() {
		int arrayLength = (sizeof(enemyNames) / sizeof(*enemyNames)); //get length of enemyNames array

		//start with goblin and work up to giant rat - if reached giant rat number then set variable so next enemy is goblin

		if (currentEnemy == arrayLength) { //if current enemy pointer is equal to size of the array (which is 6, and if the pointer is at 6 then that is outside of the array as the count starts at 0 whereas the number in array length is just the amount of elements)
			currentEnemy = 0; //make pointer go back to the start of the array
		}

		currentEnemyName = enemyNames[currentEnemy]; //set currentEnemy variable to random name from the list
		//std::cout << currentEnemyName; //output current enemy - for testing

		currentEnemy++; //increment current enemy

		return currentEnemyName; //return current enemy name
	}

	void SetStats(int playerMaxHealth) {
		//calculate enemy health based off player health
		//calculate enemy damage based off player max health

		health = playerMaxHealth * 0.6; //60% of the player's health
		maxHealth = health; //set max health to current health value
		damage = playerMaxHealth * 0.1; //take 10 hits to kill the player
	}

	int GetHealth() { //pass through health value
		return health;
	}

	int GetMaxHealth() { //pass through max health value
		return maxHealth;
	}

	int GetDamage() { //pass through damage value
		return damage;
	}

	void TakeDamage(int takenDamage) { //function to damage health
		health = health - takenDamage; //take away damage from health
	}

	bool IsDead() { //function for checking if the enemy is dead
		if (health <= 0) { //if health is less than or equal to 0
			return true;
		}
		else { //else if health is more than 0
			return false;
		}
	}
private:
	int health; //enemy health
	int maxHealth; //enemy max health
	int damage; //enemy damage
	int currentEnemy; //int for tracking what name the current enemy will have

	std::string enemyNames[6] = {"Goblin", "Spider", "Evil Wizard", "Demon", "Witch", "Giant Rat"}; //array of different enemy names
	std::string currentEnemyName; //current enemy string
};