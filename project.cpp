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

        ifstream checkFile("students.csv");
        bool isEmpty = checkFile.peek() == ifstream::traits_type::eof();
        checkFile.close();

        ofstream outfile("students.csv", ios::app);

        // Add header if file is empty
        if (isEmpty) {
            outfile << "RegistrationNumber,Name,ContactNumber,Address,Email\n";
        }

        outfile << registrationNumber << ","
                << name << ","
                << contactNumber << ","
                << address << ","
                << email << endl;

        outfile.close();

        cout << "Student data added successfully!" << endl;
    }

    void displayFileData() {
        ifstream infile("students.csv");
        string line;
        if (!infile) {
            cout << "Error opening file!" << endl;
            return;
        }
        cout << "\n====================================================================================================================\n";
        cout<< left
            << setw(20) << "Registration No"
            << setw(25) << "Name"
            << setw(18) << "Contact Number"
            << setw(25) << "Address"
            << setw(30) << "Email" << endl;
        cout << "====================================================================================================================\n";
        // Skip CSV header
        getline(infile, line);
        // Read data rows
        while (getline(infile, line)) {
            stringstream ss(line);
            string regNo, studentName, contact, addr, mail;
            getline(ss, regNo, ',');
            getline(ss, studentName, ',');
            getline(ss, contact, ',');
            getline(ss, addr, ',');
            getline(ss, mail, ',');
            
            cout<< left
                << setw(20) << regNo
                << setw(25) << studentName
                << setw(18) << contact
                << setw(25) << addr
                << setw(30) << mail << endl;
        }
        cout << "====================================================================================================================\n";
        infile.close();
    }

    void searchStudent(const string& regNumber) {

        ifstream infile("students.csv");
        string line;

        // Skip header
        getline(infile, line);

        while (getline(infile, line)) {

            stringstream ss(line);
            string token;

            getline(ss, token, ',');

            if (token == regNumber) {

                string name, contact, address, email;

                getline(ss, name, ',');
                getline(ss, contact, ',');
                getline(ss, address, ',');
                getline(ss, email, ',');

                cout << "\nStudent Found!" << endl;
                cout << "----------------------------------\n";
                cout << "Registration Number: " << token << endl;
                cout << "Name: " << name << endl;
                cout << "Contact Number: " << contact << endl;
                cout << "Address: " << address << endl;
                cout << "Email: " << email << endl;
                cout << "----------------------------------\n";

                infile.close();
                return;
            }
        }

        cout << "Student with registration number " << regNumber << " not found!" << endl;

        infile.close();
    }

    void updateStudent(const string& regNumber) {

        ifstream infile("students.csv");
        ofstream tempfile("temp.csv");

        string line;
        bool found = false;

        // Copy header
        getline(infile, line);
        tempfile << line << endl;

        while (getline(infile, line)) {

            stringstream ss(line);
            string token;

            getline(ss, token, ',');

            if (token == regNumber) {

                cout << "Student Found!" << endl;
                cout << "Enter Updated Details:\n";

                inputDetails();

                tempfile << registrationNumber << ","
                         << name << ","
                         << contactNumber << ","
                         << address << ","
                         << email << endl;

                found = true;

            } else {

                tempfile << line << endl;
            }
        }

        infile.close();
        tempfile.close();

        if (found) {

            remove("students.csv");
            rename("temp.csv", "students.csv");

            cout << "Student details updated successfully!" << endl;

        } else {

            cout << "Student with registration number "
                 << regNumber
                 << " not found!" << endl;
        }
    }

    void deleteStudent(const string& regNumber) {

        ifstream infile("students.csv");
        ofstream tempfile("temp.csv");

        string line;
        bool found = false;

        // Copy header
        getline(infile, line);
        tempfile << line << endl;

        while (getline(infile, line)) {

            stringstream ss(line);
            string token;

            getline(ss, token, ',');

            if (token == regNumber) {

                cout << "Student Found!" << endl;
                cout << "Student details deleted successfully!" << endl;

                found = true;

            } else {

                tempfile << line << endl;
            }
        }

        infile.close();
        tempfile.close();

        if (found) {

            remove("students.csv");
            rename("temp.csv", "students.csv");

        } else {

            cout << "Student with registration number "
                 << regNumber
                 << " not found!" << endl;
        }
    }
};

int main() {

    int option;
    Student student;

    do {

        cout << "\n========== STUDENT DATABASE MANAGEMENT SYSTEM ==========\n";

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
