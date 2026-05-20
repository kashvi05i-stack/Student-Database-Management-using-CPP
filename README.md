# Student Database Management System (C++)

## Overview
This project is a Student Database Management System developed using C++. The system allows users to add, display, search, update, and delete student records. Student information is stored in a CSV file, making the data easy to manage and access.

The project demonstrates the implementation of file handling, object-oriented programming, and CRUD (Create, Read, Update, Delete) operations in C++.

---

## Features
- Add new student records
- Display all student details
- Search student by registration number
- Update existing student information
- Delete student records
- CSV-based data storage
- Menu-driven interface

---

## Technologies Used
- C++
- File Handling
- CSV Data Storage
- Object-Oriented Programming (OOP)

---

## Concepts Implemented
- Classes and Objects
- Encapsulation
- File Streams (`ifstream`, `ofstream`)
- String Handling
- CSV Parsing using `stringstream`
- CRUD Operations

---

## File Structure
```text
Student-Database-System
│
├── main.cpp
├── students.csv
└── README.md
```

---

## CSV Format
The student records are stored in the following format:

```csv
RegistrationNumber,Name,ContactNumber,Address,Email
23010001,Aarav Sharma,9876543210,Pune,aarav.sharma@gmail.com
```

---

## How to Run

### Compile
```bash
g++ main.cpp -o studentdb
```

### Run
```bash
.\studentdb
```

---

## Menu Options
```text
1. Add New Student
2. Display Student Details
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## Sample Output
Output for 1:
![image alt](https://github.com/kashvi05i-stack/Student-Database-Management-using-CPP/blob/3f0f554fdaf4ac6f1e1b8fa8c0797b456eb127cf/Adding%20Student.png)

Output for 2:
![image alt](https://github.com/kashvi05i-stack/Student-Database-Management-using-CPP/blob/3f0f554fdaf4ac6f1e1b8fa8c0797b456eb127cf/Display%20Student%20Details.png)

Output for 3:
![image alt](https://github.com/kashvi05i-stack/Student-Database-Management-using-CPP/blob/3f0f554fdaf4ac6f1e1b8fa8c0797b456eb127cf/Search%20Student.png)

Output for 4:
![image alt](https://github.com/kashvi05i-stack/Student-Database-Management-using-CPP/blob/3f0f554fdaf4ac6f1e1b8fa8c0797b456eb127cf/Update%20Student%20Data.png)

Output for 5:
![image alt](https://github.com/kashvi05i-stack/Student-Database-Management-using-CPP/blob/3f0f554fdaf4ac6f1e1b8fa8c0797b456eb127cf/Delete%20Student.png)

Output for 6:
![image alt](https://github.com/kashvi05i-stack/Student-Database-Management-using-CPP/blob/fc07bb309da531b0119a4ff90013da8b3ad9bf30/Exiting%20the%20Code.png)

## Learning Outcomes
- Learned implementation of file handling in C++
- Understood CSV-based data management
- Gained experience with CRUD operations
- Improved understanding of OOP concepts
- Enhanced problem-solving and debugging skills

---

## Future Improvements
- Password-protected login system
- GUI-based application
- Database integration using MySQL
- Sorting and filtering functionality
- Data validation and exception handling

---

## Author
Kashvi Chaturvedi
