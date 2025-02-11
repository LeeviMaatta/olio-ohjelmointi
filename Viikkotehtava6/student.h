#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student
{
public:
    Student();
    void setAge(int);
    void setName(std::string);
    std::string getName();
    int getAge();
    void printStudentInfo();
private:
    std::string name;
    int age;
};

#endif // STUDENT_H
