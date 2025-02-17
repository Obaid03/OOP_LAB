/*Scenario: A bank wants to develop a system for managing customer accounts. The system
should allow customers to:
1. Create a new account with an account number, owner’s name, and initial balance
(default balance is 0 if not provided).
2. Deposit money into their account.
3. Withdraw money from their account, ensuring they cannot withdraw more than the
available balance.
4. Display account details including account number, owner’s name, and current balance.
Your task is to implement a C++ program that fulfills these requirements.*/
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
        void create(){
            
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