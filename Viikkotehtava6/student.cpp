#include "student.h"

Student::Student() {}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setName(std::string name)
{
    this->name = name;
}

std::string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

void Student::printStudentInfo()
{
    std::cout << "Student " << name << ", age: " << age << std::endl;
}
