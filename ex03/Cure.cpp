#include <iostream>
#include "inc/Cure.hpp"
#include "inc/ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure materia created" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
    std::cout << "Cure materia copied" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure materia destroyed" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


