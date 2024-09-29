#include "ItemList.h"
#include <iostream>

// Debug state
#include "ApplicationState.h"
extern ApplicationState applicationstate;


ItemList::ItemList() {}

ItemList::~ItemList() {}

void ItemList::set_attributes(Weapon* item)
{
	const char* id = (item->id).c_str();

	if (applicationstate) std::cout << "Creating Weapon class instance with list id \"" << item->id << "\"" << std::endl;

	switch (str_hash(id))
	{


		// <---=========================
	case str_hash("Template ranged weapon"):
		item->weight = 10;
		item->durability = 200;

		item->base_damage = 20;
		item->alternative_damage = 30;
		item->attack_count = 3;
		item->max_load_size = 36;
		item->current_load_size = item->max_load_size;
		item->is_ranged = true;
		item->moves.push_back("Single shot");
		item->moves.push_back("Simple melee");
		break;
		// <---=========================

		// <---=========================
	case str_hash("Template melee weapon"):
		item->weight = 10;
		item->durability = 200;

		item->base_damage = 40;
		item->alternative_damage = 0;
		item->attack_count = 1;
		item->max_load_size = 0;
		item->current_load_size = item->max_load_size;
		item->is_ranged = false;
		item->moves.push_back("Simple melee");
		break;
		// <---=========================

	default:
		throw std::invalid_argument("There is no Weapon with this id: " + item->id);
		break;
	}
}

void ItemList::set_attributes(Consumable* item)
{
	const char* id = (item->id).c_str();

	if (applicationstate) std::cout << "Creating Consumable class instance with list id \"" << item->id << "\"" << std::endl;

	switch (str_hash(id))
	{


		// <---=========================
	case str_hash("Template consumable"):
		item->weight = 1;
		item->durability = 1;
		break;
		// <---=========================


	default:
		throw std::invalid_argument("There is no Consumable with this id: " + item->id);
		break;
	}
}

void ItemList::set_attributes(Armor* item)
{
	const char* id = (item->id).c_str();

	if (applicationstate) std::cout << "Creating Armor class instance with list id \"" << item->id << "\"" << std::endl;

	switch (str_hash(id))
	{


		// <---=========================
	case str_hash("Template armor"):
		item->weight = 19;
		item->shield_value = 150;
		item->durability = 200;
		break;
		// <---=========================

	default:
		throw std::invalid_argument("There is no Armor with this id: " + item->id);
		break;
	}
}