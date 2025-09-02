#include "../includes/Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : name(other.name) {
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i]) {
			inventory[i] = other.inventory[i]->clone();
		} else {
			inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;  
		// Delete current inventory
		for (int i = 0; i < 4; i++) {
			delete inventory[i];
			inventory[i] = NULL;
		}  
		// Copy new inventory
		for (int i = 0; i < 4; i++) {
			if (other.inventory[i]) {
				inventory[i] = other.inventory[i]->clone();
			}
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete inventory[i];
	}
}

std::string const & Character::getName() const {
	return name;
}

void Character::equip(AMateria* mat) {
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = mat;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		inventory[idx]->use(target);
	}
}