/*Task Requirements:
1. Create a base class BankAccount with attributes like accountNumber, balance, and a
virtual function calculateInterest().
2. Implement two derived classes:
    o SavingsAccount (Interest: 5% per year)
    o CurrentAccount (Interest: No interest)
3. Overload the deposit method in both derived classes to handle:
    o Deposit via cash
    o Deposit via check
    o Deposit via online transfer
4. Override the withdraw method in both derived classes with different rules:
    o SavingsAccount: Cannot withdraw if balance is below $500
    o CurrentAccount: Allows overdraft up to $1000
5. Implement operator overloading in BankAccount:
    o + to add two account balances
    o - to subtract an amount from balance
    o * to apply interest on balance
    o / to calculate equal installment payments from balance
6. Create objects of both SavingsAccount and CurrentAccount, demonstrate method
overloading, overriding, and operator overloading with real transaction examples.*/
#include<iostream>
using namespace std;
class bankAccount{
    protected:
        string AccountNumber;
        double Balance;
    public:
        bankAccount(string AN="",double b=0):AccountNumber(AN),Balance(b){}
        void Display(){
            cout<<"Bank Account: "<<AccountNumber<<"Balance:    "<<Balance<<endl;
        }
        virtual void CalculateInterest()=0;
        virtual void withrdraw(double amount)=0;
        void deposit(double amount){
            cout<<"Depositing RS:   "<<amount<<"    VIA CASH in  "<<this->AccountNumber<<endl;
            Balance+=amount;
        }
        void deposit(double amount,string type){
            if(type=="check"){
                cout<<"Depositing RS:   "<<amount<<"    VIA CHECK   "<<this->AccountNumber<<endl;
                Balance+=amount;
            }
            else if(type=="online"){
                cout<<"Depositing RS:   "<<amount<<"    VIA Online Transfer in  "<<this->AccountNumber<<endl;
                Balance+=amount;
            }
            else {
                cout<<"INVALID TYPE!"<<endl;
            }

        } 
        double operator+(bankAccount &b){
            return Balance+b.Balance;
        }
        void operator-(double n){
             Balance-=n;
        }
        void operator*(int n){
            double rate=Balance*n;
            cout<<"Interest on your BALANCE  "<<Balance<<"  is RS  "<<rate<<endl;
        }
        void operator/(int n){
            if(n<=0){
                cout<<"Months cannot be less than or equal to ZERO!!!"<<endl;
            }
            else{
            double rate=Balance/n;
            cout<<"Installements on your BALANCE  "<<Balance<<"  is RS  "<<rate<<"For "<<n<<"MOnths"<<endl;
        }}
};
class SavingsAccount:public bankAccount{
    private:
        const double Rate=5; 
    public:
        SavingsAccount(string AN="",double b=0):bankAccount(AN,b){}
        void CalculateInterest()override{
            double rate=Balance*0.05;
            cout<<"Interest on your BALANCE  "<<Balance<<"  is RS  "<<rate<<endl;
        }
        void withrdraw(double amount)override{
            if(Balance>=500){
                if (amount>Balance){
                    cout<<"Cannot Withdraw RS:   "<<amount<<"   As balance is only    "<<Balance<<endl;
                }
                else{
                cout<<"Withdrawing RS:   "<<amount<<endl;
                Balance-=amount;}
            }
            else 
                cout<<"Cannot Withdraw RS:   "<<amount<<"As balance less than 500/."<<endl;
        }

};
class CurrentAccount:public bankAccount{
    public:
        CurrentAccount(string AN="",double b=0):bankAccount(AN,b){}
        void CalculateInterest()override{
            cout<<"NO Interest on Current ACCOUNT"<<endl;
        }
        void withrdraw(double amount)override{
            if(amount>Balance){
            if(amount-Balance<-1000){//overdraft concept
                cout<<"Cannot Withdraw RS:   "<<amount<<"As overdraft is exceeding $1000 "<<endl;}
            else {
                cout<<"Withdrawing RS:   "<<amount<<endl;
                Balance-=amount;
                cout<<"Overdraft is RS:   "<<Balance<<endl;

            }}
            else{
                cout<<"Withdrawing RS:   "<<amount<<endl;
                Balance-=amount;}
            }
};
int main(){
    SavingsAccount S("Saving101",1000);
    CurrentAccount C("Current101",1000);
    cout<<"=============================================================="<<endl;
    cout<<"********************Bank Management System********************\n"<<endl;

    //Depositing Money //Overloading
    S.deposit(1000);
    S.deposit(1000,"check");
    S.deposit(1000,"online");
    C.deposit(1000);
    C.deposit(1000,"check");
    C.deposit(1000,"online");
    cout<<"\n=============================================================="<<endl;
    S.Display();
    C.Display();
    //Calculating Ineterest
    cout<<"\n=============================================================="<<endl;
    S.CalculateInterest();
    C.CalculateInterest();
    cout<<"\n=============================================================="<<endl;
    //Operator Overloading
    double Total=S+C;
    cout<<"Total Balance in Both Accounts   "<<Total<<endl;
    S-1000;
    cout<<"withdrawing RS 1000 From Saving Account Using Operator overloading  "<<endl;
    C-1000;
    cout<<"withdrawing RS 1000 From Current Account Using Operator overloading  "<<endl;
    cout<<"\n=============================================================="<<endl;
    S.Display();
    C.Display();
    S*10;
    // cout<<"Applying Interest of 10\% on Saving Account Using Operator overloading  "<<Total<<endl;
    C/10;
    // cout<<"MAKING Installments of 10 MONSTHS on Current Account Using Operator overloading  "<<Total<<endl;
    cout<<"\n=============================================================="<<endl;
    S.Display();
    C.Display();
    cout<<"\n=============================================================="<<endl;
    //Withdrawing Money //Overriding
    S.withrdraw(1000);
    S.withrdraw(3000);
    C.withrdraw(1000);
    C.withrdraw(3000);
    cout<<"\n=============================================================="<<endl;
    S.Display();
    C.Display();


}