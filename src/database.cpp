#include "database.hpp"


bool Database::add(const Student& student)
{
    _isAdded = !_isAdded;
    return _isAdded;
    
    
}

void Database::display() const
{
    std::cout << show();
}

std::string Database::show() const
{
    return "";
}

