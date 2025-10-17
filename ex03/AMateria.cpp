#include "inc/AMateria.hpp"
#include "inc/ICharacter.hpp"
#include "inc/IMateriaSource.hpp"

ICharacter::~ICharacter() {}

IMateriaSource::~IMateriaSource() {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &other) : _type(other._type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &other)
{
    if (this != &other)
    {
        // type is intrinsic to the concrete Materia; do not copy on assignment
        (void)other;
    }
    return *this;
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target)
{
    (void)target;
}


