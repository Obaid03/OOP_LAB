/*You are building a bank account management system. Create a class `Account` to manage bank
accounts.
Requirements:
1. Attributes:
 `accountNumber` (string)
 `accountHolderName` (string)
 `balance` (double)
2. Define a default constructor that initializes `balance` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `deposit(double amount)`: Adds the amount to the balance.
 `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
available).
 `checkBalance()`: Displays the current balance.
5. Create a few `Account` objects and test the methods.*/
#include<iostream>
using namespace std;
class Account{
    private:
        string AccNum;      string AccName;
        double bal;
    public:
        Account(){
            AccName='\0';   AccNum='\0';
            bal=0.0;
        }
        Account(string AccNum,string Accname,double bal){
            this->AccNum=AccNum;
            this->AccName=AccName;
            this->bal=bal;
        }
        void Deposit(double amount){
            if(amount<0){
                cout<<"Invalid Amount Entered\n";
            }
           else{
            cout<<"Depositing Amount->\t"<<amount<<endl;
            bal+=amount;
            cout<<"Successfuly Deposited\n";
            cout<<"Balance ->   "<<bal<<endl;
           } 
        }
        void withdraw(double amount){
            if(amount>bal){
                cout<<"Insufficient balance\n";
            }
            else{
                cout<<"Withdrawing Amount->\t"<<amount<<endl;
                bal-=amount;
                cout<<"Successfuly Withdrawn\n";
                cout<<"Balance ->   "<<bal<<endl;
            }
        }
        void checkBal(){
            cout<<"Balance ->   "<<bal<<endl;
        }
};
int main(){
    cout<<"-----------ACCOUNT MANAGEMENT SYSTEM-----------"<<endl;
    Account a1;Account a2("123Meezan","OBAID",100000);Account a3("321HBL","Muhammad",500000);
    cout<<"-----------Account 1-----------"<<endl;
    a1.checkBal();
    cout<<"-----------Account 2-----------"<<endl;
    a2.checkBal();
    a2.Deposit(40000);
    cout<<"-----------Account 3-----------"<<endl;
    a3.withdraw(150000);

return 0;
}