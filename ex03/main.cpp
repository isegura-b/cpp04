#include <iostream>
#include "inc/IMateriaSource.hpp"
#include "inc/MateriaSource.hpp"
#include "inc/ICharacter.hpp"
#include "inc/Character.hpp"
#include "inc/AMateria.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"
 /*
int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());


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
}*/

int main()
{
    std::cout << "=== Creando una MateriaSource ===" << std::endl;
    MateriaSource src;

    std::cout << "\n=== Aprendiendo materias base ===" << std::endl;
    src.learnMateria(new Ice());   // Guarda un "prototipo" de Ice
    src.learnMateria(new Cure());  // Guarda un "prototipo" de Cure

    std::cout << "\n=== Creando personaje principal ===" << std::endl;
    Character me("me");

    AMateria* tmp; // puntero temporal para materias creadas
    AMateria* iceMateria; // Guardar referencia a ice para poder borrarla después

    std::cout << "\n=== Creando materias a partir de la fuente ===" << std::endl;
    tmp = src.createMateria("ice");    // Clona el prototipo de Ice
    iceMateria = tmp;                  // Guardar referencia
    me.equip(tmp);                     // El personaje lo equipa (slot 0)

    tmp = src.createMateria("cure");   // Clona el prototipo de Cure
    me.equip(tmp);                     // El personaje lo equipa (slot 1)

    std::cout << "\n=== Creando otro personaje para usar como objetivo ===" << std::endl;
    Character bob("bob");

    std::cout << "\n=== Usando las materias equipadas ===" << std::endl;
    me.use(0, bob);  // Usa Ice → * shoots an ice bolt at bob *
    me.use(1, bob);  // Usa Cure → * heals bob’s wounds *

    std::cout << "\n=== Intentando usar un slot vacío ===" << std::endl;
    me.use(2, bob);  // No hay materia → no pasa nada

    std::cout << "\n=== Desequipando materia ===" << std::endl;
    me.unequip(0);   // Libera el slot 0, pero no borra el puntero (seguridad)
    me.use(0, bob);  // Ahora no hace nada
    delete iceMateria;  // Liberar la materia desequipada

    std::cout << "\n=== Creando una nueva materia y equipándola ===" << std::endl;
    tmp = src.createMateria("ice");
    me.equip(tmp);
    me.use(0, bob);  // Funciona otra vez

    std::cout << "\n=== Copiando un personaje (para probar copia profunda) ===" << std::endl;
    Character clone = me;  // Constructor de copia profunda
    clone.use(0, bob);     // Usa su propia copia de la materia

    std::cout << "\n=== Borrando personajes ===" << std::endl;
    // Cuando 'me' y 'clone' salen de scope, sus destructores liberan sus materias.
    // Gracias al destructor virtual de AMateria, se destruyen correctamente Ice/Cure.
    return 0;
}
