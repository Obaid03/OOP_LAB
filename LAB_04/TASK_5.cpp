/*You are building an employee management system. Create a class `Employee` to manage employee
records.
Requirements:
1. Attributes:
 `employeeID` (int)
 `name` (string)
 `department` (string)
 `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
 `isManager()`: Returns `true` if the employee's department is "Management".
 `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.*/
#include <iostream>
using namespace std;
class Employee{
    private:    
        int employeeId;
        string name;
        string department;
        double salary;

    public:
        Employee(){
            salary=0.0;
        }    
        Employee(int employeeId,string name,string department,double salary){
            this-> employeeId=employeeId;
            this-> name=name;
            this->department=department;
            this->salary=salary;
        }
        void giveBonus(double bonus){
            salary=salary+bonus;
            cout <<"Employee Salary After Adding Bonus ->\t"<<salary << endl;
        }
        bool isManager(){
            if(department=="Management"||department=="management"){
                return true;
            }
        return false;        
        }
        void display(){
            cout << "\n-------------Employee Details-------------\n";                 cout <<"Employee ID ->\t"<< employeeId <<endl;
            cout <<"Employee NAME ->\t"<< name <<endl;                                cout <<"Employee Department ->\t"<< department <<endl;
            cout <<"Employee Salary ->\t"<<salary << endl;                           
        }
};
        int main(){
            cout << "\n-------------STUDENT MANAGEMENT SYSTEM-------------\n";
            Employee e1(1234,"MUHAMMAD","IT",50000);
            Employee e2(4321,"UMER","Management",25000);
            e1.display();  
            cout<<"MANAGER ->\t";                               (e1.isManager() == true) ? (cout << "True" << endl) : (cout << "False" << endl);   
            cout<<"Bonus (0)\n"<<endl;                          e1.giveBonus(0);
            e2.display();
            cout<<"MANAGER ->\t";                               (e2.isManager() == true) ? (cout << "True" << endl) : (cout << "False" << endl);
            cout<<"Bonus (25000) \n"<<endl;                     e2.giveBonus(25000);
}