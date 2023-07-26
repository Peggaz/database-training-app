#include "database.hpp"


bool Database::add(const Student& student)
{
    if(!_isAdded){
        _students.push_back(student);
    }
    _isAdded = !_isAdded;
    return _isAdded;
    
    
}

void Database::display() const
{
    std::cout << show();
}

std::string Database::show() const
{
    std::string res = "";
    for(auto && student : _students){
        res += student.show();
    }
    return res;
}

