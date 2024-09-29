#pragma once
#include "ItemLogic.h"
#include <iostream>

class Weapon;
class Armor;

class Character
{
public:
	std::string name;
	int food_consumption;
	int weight_addition;
	Weapon* weapon_ptr;
	Armor* armor_ptr;

	int health_points;
	int atack_points;

	std::vector<std::string> moves;

	Character(std::string name);
	~Character();

	void print() const;
};