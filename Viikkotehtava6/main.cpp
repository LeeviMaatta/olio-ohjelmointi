#include <algorithm>
#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

bool compareAge(Student &a, Student &b);
bool compareName(Student &a, Student &b);

int main ()
{
    string name;
    int age;
    int selection =0;
    vector<Student> studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0: {
            cout << "Student name ?" << endl;
            cin >> name;
            cout << "Student age ?" << endl;
            cin >> age;
            Student newStudent;
            newStudent.setName(name);
            newStudent.setAge(age);
            studentList.push_back(newStudent);
            cout << "Student added successfully!\n";
            break; }
        case 1:
            for (auto &student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 2:
            sort(studentList.begin(), studentList.end(), compareName);
            for (auto &student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 3:
            sort(studentList.begin(), studentList.end(), compareAge);
            for (auto &student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 4: {
            string searchName;
            cout << "Student to be found by name ?" << endl;
            cin >> searchName;

            auto studentNameIt = find_if(studentList.begin(), studentList.end(), [&](Student &a) {
                return a.getName() == searchName;
            });
            if (studentNameIt != studentList.end()) {
                cout << "Student found: " << endl; studentNameIt->printStudentInfo();
            } else {
                cout << "Student named " << searchName << " not found" << endl;
            }
            break; }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    } while(selection < 5);
    return 0;
}

bool compareAge(Student &a, Student &b)
{
    return a.getAge() < b.getAge();
}

bool compareName(Student &a, Student &b)
{
    return a.getName() < b.getName();
}
