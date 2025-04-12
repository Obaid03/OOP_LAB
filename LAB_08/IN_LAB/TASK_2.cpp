#include<iostream>
using namespace std;
class Accounts{
    private:
        string AccountNumber;
        string AccountHolder;
        double Balance;
    public:
        Accounts(string AN="",string AH="",double bal=0.0):AccountNumber(AN),AccountHolder(AH),Balance(bal){}
        // void deposit(double amount){
        //     if (amount<0){
        //         cout<<"Invalid Amount Entered"<<endl;
        //         return;
        //     }
        //     Balance+=amount;
        //     cout<<"Amount "<<amount<<"has been added."<<endl;
        // }
        // void withdraw(double amount){
        //     if (amount<0 ||amount>Balance){
        //         cout<<"Invalid Amount Entered"<<endl;
        //         return;
        //     }
        //     Balance-=amount;
        //     cout<<"Amount "<<amount<<"has been removed."<<endl;
        // }
        Accounts operator+(const Accounts &a){
            Accounts temp;
            temp.AccountNumber="103";
            temp.AccountHolder="MO";
            temp.Balance=Balance+a.Balance;
            return temp;
        }
        Accounts operator-=(double amount){
            Balance-=amount;
            return *this;
        }
        Accounts operator+=(double amount){
            Balance+=amount;
            return *this;
        }
        bool operator>(const Accounts &c){
            if( Balance>c.Balance)
                {cout<<"Obaid' Account has More BALANCE"<<endl;            return true;
                }
            else 
                {cout<<"ALI' Account has More BALANCE"<<endl;            return false;
                }
        }
        friend ostream& operator<<(ostream &,const Accounts &);
    };
    ostream& operator<<(ostream &out,const Accounts &a){
        out<<"ACCOUNT NUMBER --->"<<a.AccountNumber<<endl;
        out<<"ACCOUNT HOLDER --->"<<a.AccountHolder<<endl;
        out<<"BALANCE --->"<<a.Balance<<endl;
        return out;
    }
    int main(){
        Accounts a("101","OBAID",5000),a1("102","ALI",3000);
        cout<<"*********************************************"<<endl;
        cout<<a<<a1<<endl;
        cout<<"*********************************************"<<endl;
        cout<<"ADDING BALANCE"<<endl;
        Accounts a2("103","MO",000); 
        a2=a+a1;
        cout<<a2<<endl;
        cout<<"*********************************************"<<endl;
        a-=2000;
        a1+=2000;
        cout<<"Comparison"<<endl;
        a>a1;
        cout<<"*********************************************"<<endl;
        cout<<a<<a1<<endl;
    }
