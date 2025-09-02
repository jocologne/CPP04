#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include <iostream>

int main() {
	std::cout << "=== Testing Materia System ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	// Additional tests
	std::cout << "\n=== Additional Tests ===" << std::endl;

	// Test full inventory
	std::cout << "\n--- Testing Full Inventory ---" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << "Created ice materia: " << tmp << std::endl;
	me->equip(tmp);
	std::cout << "Equipped ice materia in slot 2" << std::endl;

	tmp = src->createMateria("cure");
	std::cout << "Created cure materia: " << tmp << std::endl;
	me->equip(tmp);
	std::cout << "Equipped cure materia in slot 3" << std::endl;

	std::cout << "Inventory is now full (4/4)" << std::endl;

	tmp = src->createMateria("ice"); // Should not equip (full)
	std::cout << "Created another ice materia: " << tmp << std::endl;
	std::cout << "Attempting to equip to full inventory..." << std::endl;
	me->equip(tmp); // This should fail silently
	std::cout << "Equip attempt completed" << std::endl;

	std::cout << "Cleaning up unequipped materia..." << std::endl;
	delete tmp; // Cleanup
	std::cout << "Unequipped materia deleted" << std::endl;

	// Test unequip
	me->unequip(0);
	me->use(0, *bob); // Should do nothing

	// Test deep copy
	Character* original = new Character("original");
	tmp = src->createMateria("ice");
	original->equip(tmp);

	std::cout << std::endl;
	Character* copy = new Character(*original);
	std::cout << "Original name: " << original->getName() << std::endl;
	std::cout << "Copy name: " << copy->getName() << std::endl;

	copy->use(0, *bob);

	// Cleanup
	delete original;
	delete copy;
	delete bob;
	delete me;
	delete src;

	std::cout << "=== Test Complete ===" << std::endl;
	return 0;
}