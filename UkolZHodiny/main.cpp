#include <iostream>
#include "School.hpp"
using namespace std;
int main(){
    School school("skola");
    SchoolClass* cl = school.RegisterClass("1.A", 16);
    school.AddStudent("Vojta", cl);

    cout << school.GetStudentByName("Vojta")->GetSchoolClass()->GetName() << endl;
    return 0;
}