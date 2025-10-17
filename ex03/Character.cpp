#include "inc/Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name)
{
    std::cout << "Character " << _name << " created" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

Character::Character(Character const &other) : _name(other._name)
{
    std::cout << "Character " << _name << " copied" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    _copyInventory(other);
}

Character::~Character()
{
    std::cout << "Character " << _name << " destroyed" << std::endl;
    _clearInventory();
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        _name = other._name;
        _clearInventory();
        _copyInventory(other);
    }
    return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i] == 0)
        {
            _inventory[i] = m;
            std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (_inventory[idx])
        std::cout << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
    _inventory[idx] = 0; // do not delete, per spec
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}

void Character::_clearInventory()
{
    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = 0;
        }
    }
}

void Character::_copyInventory(Character const & other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}


