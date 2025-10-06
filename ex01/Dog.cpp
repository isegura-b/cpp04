#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog created!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copied!" << std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) 
{
    std::cout << "Dog assigned" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "Dog destroyed!" << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return brain->getIdea(index);
}
