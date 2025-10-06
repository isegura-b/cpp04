#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other) 
{
    std::cout << "Brain copy constructed" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other) 
{
    int i = 0;
    std::cout << "Brain assigned" << std::endl;
    if (this != &other) 
    {
        while (i < 100)
        {
            ideas[i] = other.ideas[i];
            i++;
        }
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) 
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const 
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return ("No idea");
}
