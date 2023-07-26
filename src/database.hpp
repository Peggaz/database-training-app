#pragma once
#include "student.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Database
{
public:
    bool add(const Student& student);
    void display() const;
    std::string show() const;
    Student* findPerPesel(std::string pesel);
    Student* findPerLastName(std::string lastName);
    void removePerIndex(int index);
    void sortedByPesel();
    void sortedByLastName();
    // void remove(const Student& student);
    // void update(const Student& student);
    // Student get(const std::string& pesel);
    // std::vector<Student> getAll();
private:
    std::vector<Student> _students;
};
