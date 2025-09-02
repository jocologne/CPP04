#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other.templates[i]) {
			templates[i] = other.templates[i]->clone();
		} else {
			templates[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		// Delete current templates
		for (int i = 0; i < 4; i++) {
			delete templates[i];
			templates[i] = NULL;
		}
		// Copy new templates
		for (int i = 0; i < 4; i++) {
			if (other.templates[i]) {
				templates[i] = other.templates[i]->clone();
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* mat) {
	for (int i = 0; i < 4; i++) {
		if (!templates[i]) {
			templates[i] = mat;
			return;
		}
	}
	delete mat;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (templates[i] && templates[i]->getType() == type) {
			return templates[i]->clone();
		}
	}
	return NULL;
}