#include "SchoolClass.hpp"
SchoolClass::SchoolClass(string name, int capacity){
            this->name = name;
            this->max_student_capacity = capacity;
}
string SchoolClass::GetName(){
    return this->name;
}