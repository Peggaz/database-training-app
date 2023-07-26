#include "database.hpp"


bool Database::add(const Student& student)
{
    if(findPerPesel(student.getPesel()) == nullptr && findPerLastName(student.getLastName()) == nullptr){
        _students.push_back(student);
        return true;
    }
    return false;
    
    
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

Student* Database::findPerPesel(std::string pesel)
{
    for(auto && student : _students){
        if(student.getPesel() == pesel){
            return &student;
        }
    }
    return nullptr;
}

Student* Database::findPerLastName(std::string lastName)
{
    for(auto && student : _students){
        if(student.getLastName() == lastName){
            return &student;
        }
    }
    return nullptr;
}


void Database::removePerIndex(int index)
{
    for(auto it = _students.begin(); it != _students.end(); ++it){
        if(it->getIndexNumber() == index){
            _students.erase(it);
            return;
        }
    }
}

void Database::sortedByPesel()
{
    std::sort(_students.begin(), _students.end(), [](const Student& a, const Student& b){
        return a.getPesel() < b.getPesel();
    });
}

void Database::sortedByLastName()
{
    std::sort(_students.begin(), _students.end(), [](const Student& a, const Student& b){
        return a.getLastName() < b.getLastName();
    });
}
