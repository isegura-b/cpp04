#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal 
{
protected:
    std::string type;
public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();
    
    virtual void makeSound() const = 0;  // método virtual puro -> clase abstracta (No tiene sentido tener el sonido un animal que no sabemos cual es)
    std::string getType() const;
};
#endif
/*
AAnimal a;          // ❌ error, es abstracta
AAnimal* dog = new Dog(); // ✅ OK
*/