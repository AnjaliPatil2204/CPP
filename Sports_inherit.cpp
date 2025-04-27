#include <iostream>
#include <string>
using namespace std;

class Sports {
public:
    string name;

    Sports(string n) {
        name = n;
    }

    void display() {
        cout << "Sport: " << name << endl;
    }
};

class Football : public Sports {
public:
    string league;

    Football(string n, string l) : Sports(n) {
        league = l;
    }

    void displayDetails() {
        display();
        cout << "League: " << league << endl;
    }
};

class Cricket : public Sports {
public:
    string format;

    Cricket(string n, string f) : Sports(n) {
        format = f;
    }

    void displayDetails() {
        display();
        cout << "Format: " << format << endl;
    }
};

int main() {
    Football football("Football", "Premier League");
    football.displayDetails();

    Cricket cricket("Cricket", "Test Match");
    cricket.displayDetails();

    return 0;
}

