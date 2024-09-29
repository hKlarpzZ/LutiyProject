#pragma once
#include <iostream>
#include <vector>
#include "CharacterLogic.h"

// Debug state
#include "ApplicationState.h"
extern ApplicationState applicationstate;

class Character;

class Item
{
public:

	std::string id;
	int weight;
	int durability;

	Item();

	~Item();

	virtual void use();

	virtual void print_attributes();
};

class Weapon : public Item
{
public:

	int base_damage; // Плоский урон обычной атаки
	int alternative_damage; // Урон дальнего боя или способности
	int attack_count; // Сколько пуль&ударов в атаке
	int max_load_size; // Вместимость магазина
	int current_load_size; // Текущий размер магазина
	bool is_ranged; // Является ли дальним

	std::vector<std::string> moves;

	Character* equipped_on;

	Weapon(std::string id);

	~Weapon();

	virtual void use() override;

	virtual void print_attributes() override;
};

class Consumable : public Item
{
public:

	Consumable(std::string id);

	~Consumable();

	virtual void use() override;

	virtual void print_attributes() override;
private:

};

class Armor : public Item
{
public:

	int shield_value;

	Character* equipped_on;

	Armor(std::string id);

	~Armor();

	virtual void use() override;

	virtual void print_attributes() override;

private:

};

class ItemInventory
{
public:

	std::vector<Item*> inventory;
	int max_weight;
	int current_weight;

	ItemInventory();
	~ItemInventory();

	void add(Item* item_ptr);

	void remove(int vec_id);

	void remove(Item* item_ptr);

	void print();
};