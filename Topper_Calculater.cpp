#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;

// Function to calculate average
double calculateAverage(const vector<int>& marks) {
    return accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
}

int main() {
    map<string, vector<int> > studentRecords;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add student record\n";
        cout << "2. Display all records with average\n";
        cout << "3. Display student with highest average\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            vector<int> marks(3);

            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter 3 marks: ";
            for (int i = 0; i < 3; ++i) {
                cin >> marks[i];
            }

            studentRecords[name] = marks;
        }
        else if (choice == 2) {
            // Using explicit iterator type
            for (map<string, vector<int> >::iterator it = studentRecords.begin(); it != studentRecords.end(); ++it) {
                const string& name = it->first;
                const vector<int>& marks = it->second;
                double avg = calculateAverage(marks);

                cout << "Student: " << name << ", Marks: ";
                for (int i = 0; i < marks.size(); ++i) {
                    cout << marks[i] << " ";
                }
                cout << ", Average: " << avg << endl;
            }
        }
        else if (choice == 3) {
            if (studentRecords.empty()) {
                cout << "No records available.\n";
                continue;
            }

            // Finding the topper using explicit iterator type
            string topperName;
            double highestAvg = -1;

            for (map<string, vector<int> >::iterator it = studentRecords.begin(); it != studentRecords.end(); ++it) {
                double avg = calculateAverage(it->second);
                if (avg > highestAvg) {
                    highestAvg = avg;
                    topperName = it->first;
                }
            }

            cout << "Topper: " << topperName << " with average " << highestAvg << endl;
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
