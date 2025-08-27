#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include <iostream>

int main() {
	//ANIMALS ARRAY
	const int SIZE = 4;
	Animal* animals[SIZE];
	for (int i = 0; i < SIZE; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < SIZE; i++) {
		delete animals[i];
	}

	//DEEP COPY
	std::cout << std::endl;
	std::cout << "-- Copy test --" << std::endl;
	Dog original;
	original.setIdea(0, "Bark");
	Dog copied = original;
	std::cout << "Original--> " << original.getIdea(0) << std::endl;
	std::cout << "Copied---->" << copied.getIdea(0) << std::endl;
	copied.setIdea(0, "Sleep");
	std::cout << "After" << std::endl;
	std::cout << "Original--> " << original.getIdea(0) << std::endl;
	std::cout << "Copied---->" << copied.getIdea(0) << std::endl;
}