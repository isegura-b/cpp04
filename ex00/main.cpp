#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    std::cout << "[Polymorphism]" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " says: ";
    j->makeSound();
    std::cout << i->getType() << " says: ";
    i->makeSound();
    std::cout << meta->getType() << " says: ";
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n[No Polymorphism]" << std::endl;
    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* wrongi = new WrongCat();

    std::cout << wrongmeta->getType() << " says: ";
    wrongmeta->makeSound();
    std::cout << wrongi->getType() << " says: ";
    wrongi->makeSound(); // No Polymorphism

    delete wrongmeta;
    delete wrongi;

    return 0;
}
