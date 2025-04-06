#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct for Patient
struct Patient {
    string name;
    int age;
    string disease;
};

// Define a struct for Doctor
struct Doctor {
    string name;
    string specialization;
};

// Function to add a patient
void addPatient(vector<Patient>& patients) {
    Patient newPatient;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, newPatient.name);
    cout << "Enter patient age: ";
    cin >> newPatient.age;
    cout << "Enter patient disease: ";
    cin.ignore();
    getline(cin, newPatient.disease);
    patients.push_back(newPatient);
    cout << "Patient added successfully!" << endl;
}

// Function to add a doctor
void addDoctor(vector<Doctor>& doctors) {
    Doctor newDoctor;
    cout << "Enter doctor name: ";
    cin.ignore();
    getline(cin, newDoctor.name);
    cout << "Enter doctor specialization: ";
    getline(cin, newDoctor.specialization);
    doctors.push_back(newDoctor);
    cout << "Doctor added successfully!" << endl;
}

// Function to display patients
void displayPatients(vector<Patient> patients) {
    cout << "Patient List:" << endl;
    for (int i = 0; i < patients.size(); i++) {
        cout << "Name: " << patients[i].name << ", Age: " << patients[i].age << ", Disease: " << patients[i].disease << endl;
    }
}

// Function to display doctors
void displayDoctors(vector<Doctor> doctors) {
    cout << "Doctor List:" << endl;
    for (int i = 0; i < doctors.size(); i++) {
        cout << "Name: " << doctors[i].name << ", Specialization: " << doctors[i].specialization << endl;
    }
}

int main() {
    vector<Patient> patients;
    vector<Doctor> doctors;
    int choice;
    while (true) {
        cout << "Hospital Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Add a patient" << endl;
        cout << "2. Add a doctor" << endl;
        cout << "3. Display patients" << endl;
        cout << "4. Display doctors" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addPatient(patients);
                break;
            case 2:
                addDoctor(doctors);
                break;
            case 3:
                displayPatients(patients);
                break;
            case 4:
                displayDoctors(doctors);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
