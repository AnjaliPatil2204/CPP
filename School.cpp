#include <iostream>
#include <string>
using namespace std;

class School {
public:
    string name;

    School(string n) {
        name = n;
    }

    void displayName() {
        cout << "School Name: " << name << endl;
    }
};

class Student : public School {
public:
    string studentName;
    int rollNo;

    Student(string sName, int rNo, string schName) : School(schName) {
        studentName = sName;
        rollNo = rNo;
    }

    void displayStudentInfo() {
        displayName();
        cout << "Student Name: " << studentName << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

class Teacher : public School {
public:
    string teacherName;
    string subject;

    Teacher(string tName, string sub, string schName) : School(schName) {
        teacherName = tName;
        subject = sub;
    }

    void displayTeacherInfo() {
        displayName();
        cout << "Teacher Name: " << teacherName << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    Student student("John Doe", 101, "ABC School");
    student.displayStudentInfo();

    cout << endl;

    Teacher teacher("Ms. Smith", "Mathematics", "ABC School");
    teacher.displayTeacherInfo();

    return 0;
}
