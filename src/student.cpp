#include "student.hpp"

Student::Student(std::string name,
                std::string lastName,
                std::string address,
                int indexNumber,
                std::string pesel,
                Gender gender)
    : _name(name)
    , _lastName(lastName)
    , _address(address)
    , _indexNumber(indexNumber)
    , _pesel(pesel)
    , _gender(gender)
{

}

std::string Student::show() const
{
    return _name + " " + _lastName + "; " + _address + "; " + std::to_string(_indexNumber) + "; " + _pesel + "; " + "Male\n";
}
