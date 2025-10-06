#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main() 
{
    std::cout << "=== POLYMORPHISM EXAMPLE ===" << std::endl;

    AAnimal *animal0 = new Dog();
    AAnimal *animal1 = new Cat();
    AAnimal *animal2 = new Dog();
    AAnimal *animal3 = new Cat();
//    AAnimal a; <-- No se puede declarar a causa de ser abstracto

    std::cout << "\n--- Animals making sounds ---" << std::endl;
    animal0->makeSound();
    animal1->makeSound();
    animal2->makeSound();
    animal3->makeSound();

    std::cout << "\n--- Deleting animals ---" << std::endl;
    delete animal0;
    delete animal1;
    delete animal2;
    delete animal3;

    std::cout << "\n=== END OF PROGRAM ===" << std::endl;
    return 0;
}
