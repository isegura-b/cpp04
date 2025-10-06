#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_templates[4];

    void _clearTemplates();
    void _copyTemplates(MateriaSource const & other);

public:
    MateriaSource();
    MateriaSource(MateriaSource const &other);
    virtual ~MateriaSource();
    MateriaSource &operator=(MateriaSource const &other);

    virtual void learnMateria(AMateria *);
    virtual AMateria *createMateria(std::string const &type);
};

#endif