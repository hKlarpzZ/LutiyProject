#pragma once
#include "ItemLogic.h"
//#include <stdexcept>

// Debug state
#include "ApplicationState.h"
extern ApplicationState applicationstate;


class ItemList
{
public:
	ItemList();
	~ItemList();

	static void set_attributes(Weapon* item);
	static void set_attributes(Consumable* item);
	static void set_attributes(Armor* item);
};

// https://stackoverflow.com/questions/650162/why-cant-the-switch-statement-be-applied-to-strings
constexpr unsigned int str_hash(const char* s, int off = 0) { 
	return !s[off] ? 5381 : (str_hash(s, off + 1) * 33) ^ s[off];
}