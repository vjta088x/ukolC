#include "School.hpp"
School :: School(string name = "school"){
        this->student_size = 0;
        this->class_size = 0;


        this->class_list = (SchoolClass**) malloc(sizeof(SchoolClass*) * 999);
        this->student_list = (Student**) malloc(sizeof(Student*) * 999);
}
School ::~School(){
        for(int i = 0; i < this->class_size; i ++){
                free(this->class_list[i]);
        }
        for(int i = 0; i < this->student_size; i ++){
                free(this->student_list[i]);
        }
        free(class_list);
        free(student_list);
}
void School :: AddStudent(string name, SchoolClass* cl){
        Student * student = new Student(name, cl);
        this->student_list[this->student_size] = student;
        this->student_list ++;
}
SchoolClass* School:: RegisterClass(string name, int max_capacity){
        SchoolClass* cl = new SchoolClass(name, max_capacity);
        this->class_list[this->class_size] = cl;
        this->class_size ++;
        return cl;
}
Student * School::GetStudentByName(string name){
        for(int i = 0; i < student_size; i ++){
                if(this->student_list[student_size]->GetName() == name){
                        return this->student_list[student_size];
                }
        }
}