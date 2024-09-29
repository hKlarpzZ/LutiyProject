#pragma once
#include "CharacterLogic.h"

// Debug state
#include "ApplicationState.h"
extern ApplicationState applicationstate;


class CharacterList
{
public:
	static void set_attributes(Character* character);
};

// https://stackoverflow.com/questions/650162/why-cant-the-switch-statement-be-applied-to-strings
constexpr unsigned int str_hash(const char* s, int off = 0) {
	return !s[off] ? 5381 : (str_hash(s, off + 1) * 33) ^ s[off];
}