#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name_p;

public:
    Student(const char* n) {
        name_p = new char[strlen(n) + 1];
        strcpy(name_p, n);
    }
    const char* sName() {
        return name_p;
    }
    ~Student() {
        delete[] name_p;
    }
};

class Department {
private:
    char* name_p;

public:
    Department(const char* n) {
        name_p = new char[strlen(n) + 1];
        strcpy(name_p, n);
    }
    const char* dName() {
        return name_p;
    }
    ~Department() {
        delete[] name_p;
    }
};

class Course {
private:
    char* courseName_p;
    Student std_p;

public:
    Course(const char* courseName, const char* studentName) : std_p(studentName) {
        courseName_p = new char[strlen(courseName) + 1];
        strcpy(courseName_p, courseName);
    }
    const char* cName() {
        return courseName_p;
    }
    ~Course() {
        delete[] courseName_p;
    }
};


int main() {
    const char* studentName = "Daksh";
    const char* departmentName = "Computer Science";
    const char* courseName = "Data Structures";

    Student student(studentName);
    Department department(departmentName);
    Course course(courseName, studentName);

    cout << "Student Name: " << student.sName() << endl;
    cout << "Department Name: " << department.dName() << endl;
    cout << "Course Name: " << course.cName() << endl;

    return 0;
}

