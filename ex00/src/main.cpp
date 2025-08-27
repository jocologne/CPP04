#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include <iostream>

int main(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	//WRONG ANIMAL
	std::cout << std::endl;
	std::cout << "-- WrongAnimal test --" << std::endl;
	WrongAnimal* wrong = new WrongAnimal();
	WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrong->getType() <<std::endl;
	std::cout << wrongcat->getType() <<std::endl;
	wrong->makeSound();
	wrongcat->makeSound();
	delete wrong;
	delete wrongcat;
	return(0);
}