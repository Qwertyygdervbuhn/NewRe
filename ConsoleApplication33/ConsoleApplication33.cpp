#include<iostream>
using namespace std;

class Student
{
    char* name;
    int age;
public:
    Student();
    Student(const char* n, int a);
    Student(const Student& obj);
    ~Student();

    void Input(); 
    void Print();
};

Student::Student()
{
    name = nullptr;
    age = 0;
}

Student::Student(const char* n, int a)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
}

Student::Student(const Student& obj)
{
    name = new char[strlen(obj.name) + 1];
    strcpy_s(name, strlen(obj.name) + 1, obj.name);
    age = obj.age;
    cout << "Copy constructor\n";
}

Student::~Student()
{
    cout << "Destructor\n";
    delete[] name;
}

void Student::Input()
{
    char temp[100];
    cout << "Enter name: ";
    cin >> temp;
    name = new char[strlen(temp) + 1];
    strcpy_s(name, strlen(temp) + 1, temp);

    cout << "Enter age: ";
    cin >> age;
}

void Student::Print()
{
    cout << "Name: " << name << "\tAge: " << age << endl;
}

int main()
{
    Student a;
    a.Input();
    a.Print();  

    Student b = a; 
    b.Print(); 
}
