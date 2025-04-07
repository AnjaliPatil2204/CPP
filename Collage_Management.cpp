#include <iostream>
#include <string>
using namespace std;

// Base Class Person
class Person 
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void display() 
	{
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Getter functions for protected members
    string getName() const { return name; }
    int getAge() const { return age; }
};

// Derived Class Student
class Student : public Person 
{
protected:
    int rollNumber;
    string branch;
    double marks;

public:
    Student(string n, int a, int roll, string b, double m)
        : Person(n, a), rollNumber(roll), branch(b), marks(m) {}

    double calculateCGPA() 
	{
        return marks / 10;  // Assuming CGPA is marks/10 for simplicity
    }

    void display() 
	{
        Person::display();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Branch: " << branch << endl;
        cout << "Marks: " << marks << ", CGPA: " << calculateCGPA() << endl;
    }

    // Getter functions for Student-specific members
    int getRollNumber() const { return rollNumber; }
    string getBranch() const { return branch; }
    double getMarks() const { return marks; }
};

// Derived Class Faculty
class Faculty : public Person 
{
protected:
    int facultyID;
    string department;
    double salary;

public:
    Faculty(string n, int a, int id, string dep, double sal)
        : Person(n, a), facultyID(id), department(dep), salary(sal) {}

    void display() 
	{
        Person::display();
        cout << "Faculty ID: " << facultyID << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }

    // Getter functions for Faculty-specific members
    int getFacultyID() const { return facultyID; }
    string getDepartment() const { return department; }
    double getSalary() const { return salary; }
};

// TeachingAssistant Class (Multiple Inheritance)
class TeachingAssistant : public Student, public Faculty 
{
public:
    TeachingAssistant(string studentName, int studentAge, int roll, string branch, double marks,
                      string facultyName, int facultyAge, int id, string dep, double sal)
        : Student(studentName, studentAge, roll, branch, marks), Faculty(facultyName, facultyAge, id, dep, sal) {}

    void display() {
        Student::display();
        Faculty::display();
    }
};

// Administration Class (Friend Function)
class Administration 
{
public:
    // Friend function to access private details of Student and Faculty
    friend void showDetails(const Student& s, const Faculty& f);
};

void showDetails(const Student& s, const Faculty& f) 
{
    cout << "Administration Friend Function:" << endl;
    cout << "Student " << s.getName() << " from " << s.getBranch() << " scored " << s.getMarks() << " marks." << endl;
    cout << "Faculty " << f.getName() << " teaches " << f.getDepartment() << "." << endl;
}

int main() 
{
    // Creating objects of Student, Faculty, and TeachingAssistant
    Student student1("ABC", 20, 2436, "CSE (AI-ML)", 89);
    Faculty faculty1("xyz", 45, 1001, "Computer Science", 120000);
    TeachingAssistant ta1("XYZ", 25, 1923105, "CSE (AI-ML)", 90, "abc", 45, 2005, "Artificial Intelligence", 35000);

    // Displaying details using function overriding
    cout << "Student Details:" << endl;
    student1.display();
    cout << endl;

    cout << "Faculty Details:" << endl;
    faculty1.display();
    cout << endl;

    cout << "Teaching Assistant Details:" << endl;
    ta1.display();
    cout << endl;

    // Demonstrating friend function accessing private details
    showDetails(student1, faculty1);

    return 0;
}
