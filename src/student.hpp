#pragma once 
#include <string>

enum class Gender {
    Male,
    Female
};

class Student
{
public:
    Student(std::string name,
        std::string lastName,
        std::string address,
        int indexNumber,
        std::string pesel,
        Gender gender);
    
    std::string show() const;
    std::string getPesel() const { return _pesel; }
    std::string getLastName() const { return _lastName; }
    std::string getGenderStr() const { return _gender == Gender::Female ? "Kobieta" : "Mezczyzna"; }
    int getIndexNumber() const { return _indexNumber; }

private:
    Gender _gender;
    std::string _name;
    std::string _lastName;
    std::string _address;
    int _indexNumber;
    std::string _pesel;
};