#pragma once
#include <string>
using namespace std;
class SchoolClass{
    private:
        string name;
        int max_student_capacity;
    public:
        SchoolClass(string name, int capacity);
        string GetName();
};