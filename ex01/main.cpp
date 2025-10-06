#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "================ Polymorphism basics ================" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        dog->makeSound();
        cat->makeSound();
        delete dog;
        delete cat;
    }

    std::cout << "\n================ Array of Animals ===================" << std::endl;
    {
        const int size = 6;
        Animal *animals[size];

        int i = 0;
        while (i < size)
        {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
            i++;
        }

        i = 0;
        while (i < size)
        {
            animals[i]->makeSound();
            i++;
        }

        i = 0;
        while (i < size)
        {
            delete animals[i];
            i++;
        }
    }

    std::cout << "\n================ Copy semantics =====================" << std::endl;
    {
        Dog d1;
        d1.setIdea(0, "Chase the mailman");
        d1.setIdea(1, "Guard the house");
        Dog d2(d1);           // copy constructor
        Dog d3;                // default
        d3 = d1;               // copy assignment

        Cat c1;
        c1.setIdea(0, "Climb the curtain");
        c1.setIdea(1, "Nap on keyboard");
        Cat c2(c1);           // copy constructor
        Cat c3;                // default
        c3 = c1;               // copy assignment

        d1.makeSound();
        d2.makeSound();
        d3.makeSound();
        c1.makeSound();
        c2.makeSound();
        c3.makeSound();

        std::cout << "Dog ideas: "
                  << d1.getIdea(0) << ", "
                  << d2.getIdea(1) << ", "
                  << d3.getIdea(0) << std::endl;

        std::cout << "Cat ideas: "
                  << c1.getIdea(0) << ", "
                  << c2.getIdea(1) << ", "
                  << c3.getIdea(0) << std::endl;

        d1.setIdea(0, "New dog plan");
        c1.setIdea(0, "New cat plan");
        std::cout << "After mutation — d1: " << d1.getIdea(0)
                  << ", d2: " << d2.getIdea(0)
                  << ", d3: " << d3.getIdea(0) << std::endl;
        std::cout << "After mutation — c1: " << c1.getIdea(0)
                  << ", c2: " << c2.getIdea(0)
                  << ", c3: " << c3.getIdea(0) << std::endl;
    }

    std::cout << "\n================ Scoped destruction =================" << std::endl;
    {
        Animal *a = new Dog();
        a->makeSound();
        delete a;
        a = new Cat();
        a->makeSound();
        delete a;
    }

    std::cout << "\nAll tests finished." << std::endl;
    return 0;
}