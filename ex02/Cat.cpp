#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal(), brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) 
{
    std::cout << "Cat copied!" << std::endl;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) 
{
    std::cout << "Cat assigned" << std::endl;
    if (this != &other) 
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Cat destroyed!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return brain->getIdea(index);
}
