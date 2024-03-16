#include <iostream>
#include <cstring>

class Employee {
private:
    char* myName_p;

public:
    Employee(const char* name) {
        myName_p = new char[strlen(name) + 1];
        strcpy(myName_p, name);
        std::cout << "Employee " << myName_p << " created" << std::endl;
    }
    ~Employee() {
        delete[] myName_p;
        std::cout << "Employee destroyed" << std::endl;
    }
};

class Company {
private:
    char* name_p;
    Employee myEmp;

public:
    Company(const char* name, const char* empName) : myEmp(empName) {
        name_p = new char[strlen(name) + 1];
        strcpy(name_p, name);
        std::cout << "Company " << name_p << " created" << std::endl;
    }
    ~Company() {
        delete[] name_p;
        std::cout << "Company destroyed" << std::endl;
    }
};

int main() {
    Company company("My Company", "Daksh Arora");
    return 0;
}
