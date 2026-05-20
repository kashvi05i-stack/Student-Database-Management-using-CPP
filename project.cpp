#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Student {
protected:
    char registrationNumber[9];
    char name[50];
    string contactNumber;
    string address;
    string email;

public:
    void inputDetails() {
        cout << "Enter registration number: ";
        cin >> registrationNumber;

        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter contact number: ";
        cin >> contactNumber;

        cout << "Enter address: ";
        cin.ignore();
        getline(cin, address);

        cout << "Enter email: ";
        cin >> email;
    }

    void displayDetails() {
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
    }

    void addDataToFile() {
        ofstream outfile("Example.txt", ios::app);
        outfile << registrationNumber << "\t"
                << name << "\t"
                << contactNumber << "\t"
                << address << "\t"
                << email << endl;
        outfile.close();
    }

    void displayFileData() {
        ifstream infile("Example.txt");
        string line;

        cout << "--------------------------------------------------------------------------------------------------\n";
        cout << "| Registration Number | Name                 | Contact Number     | Address              | Email |\n";
        cout << "--------------------------------------------------------------------------------------------------\n";

        while (getline(infile, line)) {
            stringstream ss(line);
            string token;

            cout << "| ";
            while (getline(ss, token, '\t')) {
                cout << setw(20) << left << token << " | ";
            }
            cout << endl;
        }

        cout << "---------------------------------------------------------------------------------------------\n";
        infile.close();
    }

    void searchStudent(const string& regNumber) {
        ifstream infile("Example.txt");
        string line;

        while (getline(infile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, '\t'); // registration number

            if (token == regNumber) {
                cout << "Student Found!" << endl;
                cout << "Details:" << endl;
                cout << line << endl;
                infile.close();
                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found!" << endl;
        infile.close();
    }

    void updateStudent(const string& regNumber) {
        ifstream infile("Example.txt");
        ofstream tempfile("temp.txt");
        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, '\t');

            if (token == regNumber) {
                cout << "Student Found!" << endl;
                cout << "Update Details:" << endl;
                inputDetails();
                tempfile << registrationNumber << "\t"
                         << name << "\t"
                         << contactNumber << "\t"
                         << address << "\t"
                         << email << endl;
                found = true;
            } else {
                tempfile << line << endl;
            }
        }

        infile.close();
        tempfile.close();

        if (found) {
            remove("Example.txt");
            rename("temp.txt", "Example.txt");
            cout << "Student details updated successfully!" << endl;
        } else {
            cout << "Student with registration number " << regNumber << " not found!" << endl;
        }
    }

    void deleteStudent(const string& regNumber) {
        ifstream infile("Example.txt");
        ofstream tempfile("temp.txt");
        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, '\t');

            if (token == regNumber) {
                cout << "Student Found!" << endl;
                cout << "Student details deleted." << endl;
                found = true;
            } else {
                tempfile << line << endl;
            }
        }

        infile.close();
        tempfile.close();

        if (found) {
            remove("Example.txt");
            rename("temp.txt", "Example.txt");
        } else {
            cout << "Student with registration number " << regNumber << " not found!" << endl;
        }
    }
};

int main() {
    int option;
    Student student;

    do {
        cout << "\nAvailable operations:\n";
        cout << "1. Add New Student\n";
        cout << "2. Display Student Details\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            student.inputDetails();
            student.addDataToFile();
            break;

        case 2:
            student.displayFileData();
            break;

        case 3: {
            string regNumber;
            cout << "Enter the registration number of the student: ";
            cin >> regNumber;
            student.searchStudent(regNumber);
            break;
        }

        case 4: {
            string regNumber;
            cout << "Enter the registration number of the student to update: ";
            cin >> regNumber;
            student.updateStudent(regNumber);
            break;
        }

        case 5: {
            string regNumber;
            cout << "Enter the registration number of the student to delete: ";
            cin >> regNumber;
            student.deleteStudent(regNumber);
            break;
        }

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
        }

    } while (option != 6);

    return 0;
}