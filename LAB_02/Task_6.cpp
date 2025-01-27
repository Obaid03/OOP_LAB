/*You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks:
 Implement the Register and Student structures.
 Inherit the Register structure in the Student structure.
 Create an array of Student structures to store information for 5 students.
 Take input for each student, including their courseId, courseName, studentId, firstName,
lastName, cellNo, and email.
 Display the information for all 5 students.*/
#include <iostream>
#include <string>
using namespace std;
struct Register {
    int courseid;
    string coursename;
};
struct student : Register {
    int studentid;
    string firstname;
    string lastname;
    string cellno;
    string email;
};
int main() {
    student students[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Course ID: ";                                          cin >> students[i].courseid;
        cin.ignore();
        cout << "Course Name: ";                                        getline(cin, students[i].coursename);
        cout << "Student ID: ";                                         cin >> students[i].studentid;
        cout << "First Name: ";                                         getline(cin, students[i].firstname);
        cout << "Last Name: ";                                          getline(cin, students[i].lastname);
        cout << "Cell Number: ";                                        getline(cin, students[i].cellno);
        cout << "Email: ";                                              getline(cin, students[i].email);
        cout << endl;}
    cout << "\nDisplaying Student Information:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << " Details:\n";
        cout << "Course ID: " << students[i].courseid << endl;
        cout << "Course Name: " << students[i].coursename << endl;
        cout << "Student ID: " << students[i].studentid << endl;
        cout << "First Name: " << students[i].firstname << endl;
        cout << "Last Name: " << students[i].lastname << endl;
        cout << "Cell Number: " << students[i].cellno << endl;
        cout << "Email: " << students[i].email << endl;}
    return 0;
}
