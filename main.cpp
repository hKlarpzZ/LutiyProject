#include <iostream>
#include "ItemLogic.h"
#include "CharacterLogic.h"
using namespace std;

// Debug state
#include "ApplicationState.h"
extern ApplicationState applicationstate;

int main()
{
	ItemInventory itemInventory;
	
	itemInventory.print();
	
	/*Character test1("Template character");
	test1.print();*/

	return 0;
}