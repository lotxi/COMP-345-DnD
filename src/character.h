#pragma once

#include <string>

#include "LivingEntity.h"
#include "dice.h"
#include <fstream>
#include <iostream>

/**
 * Character class that extends LivingEntity. Should only be used to the playable character
 */
class Character:public LivingEntity
{


private:


public:
	/**
	 * Level constructor
	 * Assigns random ability scores
	 */
	Character(int level);
	/**
	 * Ability Score Constructor
	 * Assigns ability scores to character
	 * 
	 * As per the game rules, each ability is generated in the [3-18] range
	 */
	Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl);


	Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl, std::string cname);
	/**
	 * Get modifer from ability score.
	 * 
	 * The modifier is calculated as per game rules using (score-10)/2
	 */
	int getModifier(int);



	/**
	 * Make sure character has abilities within the acceptable range
	 * 
	 * The character is validated if the ability scores are all within the range of [3-18]s
	 */
	//Temporarily commented out to not implement this now
	 /**
	bool validateNewCharacter();
	**/
	/**
	* Output string to ostream using <<
	*/

	static Character* Character::loadCharacter(std::string name);

	static bool saveCharacter(std::string name, Character * character);



};

