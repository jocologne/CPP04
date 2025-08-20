#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include <iostream>

int main(){
	Dog a;
	std::cout << a.getType() << std::endl;
	a.makeSound();
	return 0;
}