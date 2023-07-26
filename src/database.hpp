#pragma once
#include "student.hpp"
#include <string>
#include <iostream>
#include <vector>

class Database
{
public:
    bool add(const Student& student);
    void display() const;
    std::string show() const;
    // void remove(const Student& student);
    // void update(const Student& student);
    // Student get(const std::string& pesel);
    // std::vector<Student> getAll();
private:
    std::vector<Student> _students;
    bool _isAdded = false;
};
