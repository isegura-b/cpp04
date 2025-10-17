#include "inc/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource created" << std::endl;
    for (int i = 0; i < 4; ++i)
        _templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    std::cout << "MateriaSource copied" << std::endl;
    for (int i = 0; i < 4; ++i)
        _templates[i] = 0;
    _copyTemplates(other);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destroyed" << std::endl;
    _clearTemplates();
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    if (this != &other)
    {
        _clearTemplates();
        _copyTemplates(other);
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] == 0)
        {
            _templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] && _templates[i]->getType() == type)
        {
            std::cout << "MateriaSource created " << type << " materia" << std::endl;
            return _templates[i]->clone();
        }
    }
    return 0;
}

void MateriaSource::_clearTemplates()
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i])
        {
            delete _templates[i];
            _templates[i] = 0;
        }
    }
}

void MateriaSource::_copyTemplates(MateriaSource const & other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = 0;
    }
}


