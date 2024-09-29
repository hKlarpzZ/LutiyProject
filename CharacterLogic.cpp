#include "CharacterLogic.h"
#include <iostream>

#include "CharacterList.h"

Character::Character(std::string name)
{
	this->name = name;
	CharacterList::set_attributes(this);
}

Character::~Character() {}

void Character::print() const
{
	std::cout << "	---===[Character]===---" << std::endl;
	std::cout << "	    " << this->name << std::endl;
	std::cout << "\n	---===---=[ ]=---===---" << std::endl;
}
