#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public A_Animal {
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	virtual void makeSound() const;
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
};

#endif