#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "Animal created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
    std::cout << "Animal copied!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Animal assigned!" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destroyed!" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}


