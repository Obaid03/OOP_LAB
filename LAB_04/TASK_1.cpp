/*You are building a student management system. Create a class `Student` to manage student records.
Requirements:
1. Attributes:
 `studentID` (int)
 `name` (string)
 `age` (int)
 `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
 `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
 `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods.*/
#include<iostream>
using namespace std;
class Student{
    private:
        int id;
        string name;
        int age;
        char grade;
    public:
        Student(){
            id=0;name='\0';age=0;grade='N';
        }
        Student(int id,string name,int age,char grade){
            this -> id=id;
            this -> name=name;
            this ->age=age;
            this ->grade=grade;
        }
        void promotestudent(){
            if (grade > 'A'){
                grade--;
            }
        }
        bool isEligibleForScholarship(){
            if (grade=='A'){
                return true;
            }
            return false;
        }
        void display(){
            cout << "\n-------------Student Details-------------\n";                 cout <<"STUDENT ID ->\t"<< id <<endl;
            cout <<"STUDENT NAME ->\t"<< name <<endl;                                   cout <<"STUDENT AGE ->\t"<< age <<endl;
            cout <<"Student Grade ->   "<<grade << endl;
        } 
};

int main(){
    cout << "\n-------------STUDENT MANAGEMENT SYSTEM-------------\n";
    Student s1(1234,"MUHAMMAD",18,'B');
    Student s2(4321,"UMER",17,'C');
    s1.display();
    s2.display();
    cout << "\n\n-------------Promoting STUDENTS-------------\n";
    s1.promotestudent();
    s2.promotestudent();
    s1.display();
    s2.display();
    int is=s1.isEligibleForScholarship();
    if(is ==1){
        cout <<"\nEligibility of Student 1 -> TRUE"<<endl;
    }
    else{
        cout <<"\nEligibility of Student 1 -> FALSE"<<endl;
    }
    int is_2=s2.isEligibleForScholarship();
    if(is_2 ==1){
        cout <<"\nEligibility of Student 2 -> TRUE"<<endl;
    }
    else{
        cout <<"\nEligibility of Student 2 -> FALSE\n\n"<<endl;
    }    
}
