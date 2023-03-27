#include "Student.hpp"
Student :: Student(string name, SchoolClass * cl){
    this->name = name;
    this->cl = cl;
}

SchoolClass* Student:: GetSchoolClass(){
    return this->cl;
}
string Student ::GetName(){
    return this->name;
}