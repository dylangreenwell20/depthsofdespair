#pragma once

class Enemy {
public:
	void GenerateName();
	void Attack();
	void Dodge();
	void TakeDamage();
private:

	/// <summary>
	/// MAY NEED TO MOVE ALL OF THESE TO PUBLIC TO DISPLAY THEM
	/// </summary>
	
	float health;
	float damage;
	float level;
	float experience;

	std::string enemyNames[6] = {"Goblin", "Spider", "Evil Wizard", "Demon", "Witch", "Giant Rat"};
	std::string currentEnemy;
};