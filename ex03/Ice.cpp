#include <iostream>
#include "inc/Ice.hpp"
#include "inc/ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice materia created" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
    std::cout << "Ice materia copied" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice materia destroyed" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
    if (this != &other)
    {
        // AMateria assignment ignores type copy by design
        AMateria::operator=(other);
    }
    return *this;
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


