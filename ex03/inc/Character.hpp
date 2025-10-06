#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria   *_inventory[4];

    void _clearInventory();
    void _copyInventory(Character const & other);

public:
    Character(std::string const &name);
    Character(Character const &other);
    virtual ~Character();
    Character &operator=(Character const &other);

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

#endif


