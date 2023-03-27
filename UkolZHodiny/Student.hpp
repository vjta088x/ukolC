#pragma once
#include <string>
#include "SchoolClass.hpp"
using namespace std;

class Student{
    private:
        string name;
        SchoolClass * cl;
    public:
        Student(string name = "a", SchoolClass * cl = nullptr);
        SchoolClass* GetSchoolClass();
        string GetName();
};