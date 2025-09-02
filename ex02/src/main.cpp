#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Testing Abstract Animal Class (Exercise 02) ===" << std::endl;
	std::cout << std::endl;

	// 1. Test that Animal cannot be instantiated (UNCOMMENT TO VERIFY COMPILATION ERROR)
	/*
	std::cout << "Attempting to create an Animal object..." << std::endl;
	A_Animal animal; // This should cause a compilation error
	std::cout << "Animal type: " << animal.getType() << std::endl;
	animal.makeSound();
	*/

	// 2. Test that Dog and Cat can still be created through Animal pointers
	std::cout << "Creating Dog and Cat through Animal pointers:" << std::endl;
	const A_Animal* dog = new Dog();
	const A_Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << std::endl;

	// 3. Test polymorphism
	std::cout << "Testing makeSound() (polymorphism):" << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	// 4. Test deep copy for Dog
	std::cout << "=== Testing Deep Copy for Dog ===" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->setIdea(0, "I want to play fetch!");
	originalDog->setIdea(1, "I'm hungry!");

	Dog* copiedDog = new Dog(*originalDog); // Copy constructor
	std::cout << "Original Dog idea 0: " << originalDog->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea 0: " << copiedDog->getIdea(0) << std::endl;

	// Modify the copy to prove deep copy
	copiedDog->setIdea(0, "I want to sleep!");
	std::cout << "After modification:" << std::endl;
	std::cout << "Original Dog idea 0: " << originalDog->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea 0: " << copiedDog->getIdea(0) << std::endl;
	std::cout << std::endl;

	// 5. Test deep copy for Cat
	std::cout << "=== Testing Deep Copy for Cat ===" << std::endl;
	Cat* originalCat = new Cat();
	originalCat->setIdea(0, "I want to chase mice!");
	originalCat->setIdea(1, "I need a nap!");

	Cat* copiedCat = new Cat(*originalCat); // Copy constructor
	std::cout << "Original Cat idea 0: " << originalCat->getIdea(0) << std::endl;
	std::cout << "Copied Cat idea 0: " << copiedCat->getIdea(0) << std::endl;

	// Modify the copy to prove deep copy
	copiedCat->setIdea(0, "I want to eat fish!");
	std::cout << "After modification:" << std::endl;
	std::cout << "Original Cat idea 0: " << originalCat->getIdea(0) << std::endl;
	std::cout << "Copied Cat idea 0: " << copiedCat->getIdea(0) << std::endl;
	std::cout << std::endl;

	// 6. Cleanup
	std::cout << "=== Cleaning Up ===" << std::endl;
	delete dog;
	delete cat;
	delete originalDog;
	delete copiedDog;
	delete originalCat;
	delete copiedCat;

	std::cout << std::endl;
	std::cout << "=== Test Complete ===" << std::endl;

	return 0;
}