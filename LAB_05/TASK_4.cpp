/*Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber,
accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account
details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if
sufficient funds are available.
• display(): Displays the account details including the account number, account holder name,
and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three
elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder
name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.*/
#include<iostream>
using namespace std;
class BankAccount{
    private:
        int AccNum;      string AccName;
        double bal;
    public:
        BankAccount(){
            AccName='\0';   AccNum='\0';
            bal=0.0;
        }
        BankAccount(int AccNum,string AccName,double bal){
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
        void Display(){
            cout<<"-----------ACCOUNT DETAILS-----------"<<endl;
            cout<<"Account Number ->    "<<AccNum<<endl;
            cout<<"Account NAME ->    "<<AccName<<endl;  
            cout<<"Balance ->   "<<bal<<endl;
        }
};
int main(){
    BankAccount accounts[2]{
        BankAccount(100,"OBAID",1000),
        BankAccount(201,"ALI",1000)};
        
    cout<<"-----------ACCOUNT MANAGEMENT SYSTEM-----------"<<endl;

    for (int i = 0; i < 2; i++)
    {
        accounts[i].Display();
    }
    cout<<"-----------Account 1-----------"<<endl;
    accounts[0].Deposit(500);
    cout<<"-----------Account 2-----------"<<endl;
    accounts[1].withdraw(300);
    for (int i = 0; i < 2; i++)
    {
        accounts[i].Display();
    }
    return 0;

return 0;
}