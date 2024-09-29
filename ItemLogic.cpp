#include "ItemLogic.h"
#include <iostream>
#include "ItemList.h"
#include <vector>
//#include <stdexcept>

// Debug state
#include "ApplicationState.h"
extern ApplicationState applicationstate;


// Item abstract class
Item::Item() {}

Item::~Item() {}

void Item::use() {}

void Item::print_attributes()
{
	return;
}


// Item inventory class
ItemInventory::ItemInventory()
{
	max_weight = 1000;
	current_weight = 0;


	Armor* armor_item_ptr = new Armor("Template armor");
	ItemInventory::add(armor_item_ptr);

	Weapon* melee_weapon_item_ptr = new Weapon("Template melee weapon");
	ItemInventory::add(melee_weapon_item_ptr);

	Weapon* ranged_weapon_item_ptr = new Weapon("Template ranged weapon");
	ItemInventory::add(ranged_weapon_item_ptr);

	Consumable* consumable_item_ptr = new Consumable("Template consumable");
	ItemInventory::add(consumable_item_ptr);
}

ItemInventory::~ItemInventory()
{
	for (Item* item_ptr : inventory)
	{
		delete item_ptr;
	}
}

void ItemInventory::add(Item* item_ptr)
{
	if (item_ptr->weight > max_weight - current_weight)
	{
		std::cout << "Unable to add the item due to inventory overload!" << std::endl;
		return;
	}
	inventory.push_back(item_ptr);
	current_weight += item_ptr->weight;
}

void ItemInventory::remove(int vec_id)
{
	current_weight -= inventory[vec_id]->weight;
	delete inventory[vec_id];
	inventory.erase(inventory.begin() + vec_id);
}

void ItemInventory::remove(Item* item_ptr)
{
	for (size_t i = 0; i < inventory.size(); i++)
	{
		if (inventory[i] == item_ptr)
		{
			current_weight -= inventory[i]->weight;
			delete inventory[i];
			inventory.erase(inventory.begin() + i);
			return;
		}
	}
}

void ItemInventory::print()
{
	std::cout << "	---===[Inventory]===---" << std::endl;
	std::cout << "	    " << current_weight << " / " << max_weight << " kg\n" << std::endl;
	for (Item* item_ptr : inventory) //int i = 0; i < inventory.size(); i++
	{
		std::cout << "    * " << item_ptr->id << " | " << item_ptr->weight << " kg, durability: " << item_ptr->durability << std::endl;
		
		item_ptr->print_attributes();
	}
	std::cout << "\n	---===---=[ ]=---===---" << std::endl;
}


// Weapon class
Weapon::Weapon(std::string id)
{
	this->id = id;
	this->equipped_on = NULL;

	try
	{
		ItemList::set_attributes(this);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		abort();
	}
}

Weapon::~Weapon() {}

void Weapon::use() {}

void Weapon::print_attributes()
{
	if (this->is_ranged)
	{
		std::cout << "	+> [RANGED]" << std::endl;
		std::cout << "	|  Melee attack damage:  " << this->base_damage << std::endl;
		std::cout << "	|  Ranged attack damage: " << this->alternative_damage << std::endl;
		std::cout << "	|  Attacks count:        " << this->attack_count << std::endl;
		std::cout << "	+  Bullets:              " << this->current_load_size << " / " << this->max_load_size << std::endl;
		if (this->equipped_on != NULL) std::cout << "	+  Equipped on: " << this->equipped_on->name << std::endl;
	}
	else
	{
		std::cout << "	+> [MELEE]" << std::endl;
		std::cout << "	|  Base attack damage: " << this->base_damage << std::endl;
		std::cout << "	+  Attacks count:      " << this->attack_count << std::endl;
		if (this->equipped_on != NULL) std::cout << "	+  Equipped on: " << this->equipped_on->name << std::endl;
	}
}


// Consumable class
Consumable::Consumable(std::string id)
{
	this->id = id;

	try
	{
		ItemList::set_attributes(this);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		abort();
	}
}

Consumable::~Consumable() {}

void Consumable::use() {}

void Consumable::print_attributes()
{
	return;
}



// Armor class
Armor::Armor(std::string id)
{
	this->id = id;
	this->equipped_on = NULL;
	
	try
	{
		ItemList::set_attributes(this);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		abort();
	}
}

Armor::~Armor() {}

void Armor::use()
{

}

void Armor::print_attributes()
{
	std::cout << "	+> Shield points remain: " << this->shield_value << std::endl;
	if (this->equipped_on != NULL) std::cout << "	+  Equipped on: " << this->equipped_on->name << std::endl;
}
