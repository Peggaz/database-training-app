#pragma once
#include "student.hpp"
#include <string>
#include <iostream>


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
    bool _isAdded = false;
};
