#include "CharacterList.h"

void CharacterList::set_attributes(Character* character)
{
	const char* name = (character->name).c_str();

	if (applicationstate) std::cout << "Creating Character class instance with name \"" << name << "\"" << std::endl;

	character->armor_ptr = NULL;
	character->weapon_ptr = NULL;

	switch (str_hash(name))
	{
		// <---=========================
	case (str_hash("Template character")):
		character->atack_points = 10;
		character->food_consumption = 3;
		character->health_points = 200;
		// <---=========================
	default:
		break;
	}
}
