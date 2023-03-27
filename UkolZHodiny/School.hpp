#pragma once
#include <string>
#include "Student.hpp"
#include "SchoolClass.hpp"
using namespace std;
class School{
    private:
        string name;
        Student ** student_list;
        SchoolClass ** class_list;
        int student_size;
        int class_size;
    public:
        School(string name );
        ~School();
        void AddStudent(string name, SchoolClass* cl);
        SchoolClass* RegisterClass(string name, int max_capacity);
        Student* GetStudentByName(string name);
};