/*AGGREGATION SAMPLE CODE*/
#include <iostream>
using namespace std;
class Student {
public:
string name;
Student(string n) : name(n) {}
void show() { cout << "Student: " << name << endl; }
};
class University {
public:
string name;
Student* student; // Aggregation: University has a reference to Student
University(string n, Student* s) : name(n), student(s) {}
void show() {
cout << "University: " << name << endl;
student->show();
}
};
int main() {
Student s1("Ali"); // Student exists independently
University u1("Fast", &s1);
u1.show();
cout << "University object destroyed, but student still exists!\n";
return 0;
}