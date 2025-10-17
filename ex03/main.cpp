#include <iostream>
#include "inc/IMateriaSource.hpp"
#include "inc/MateriaSource.hpp"
#include "inc/ICharacter.hpp"
#include "inc/Character.hpp"
#include "inc/AMateria.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    AMateria *iceTemplate = new Ice();
    AMateria *cureTemplate = new Cure();
    src->learnMateria(iceTemplate);
    src->learnMateria(cureTemplate);
    delete iceTemplate;  // learnMateria clones, so we delete originals
    delete cureTemplate;

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    AMateria *iceMateria = tmp;  // Save reference to ice materia
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    me->use(0, *bob);
    delete iceMateria;  // Clean up unequipped materia

    Character *alice = new Character("alice");
    alice->equip(src->createMateria("ice"));
    alice->equip(src->createMateria("cure"));
    Character copy(*alice);
    delete alice;
    copy.use(0, *bob);
    copy.use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}


