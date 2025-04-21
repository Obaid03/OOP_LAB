/*Task 04
Problem: An e-commerce platform aims to support multiple payment methods (credit
cards, digital wallets) to attract global customers. The payment system must validate
transactions securely and allow new payment options (e.g., cryptocurrency) to be added
without rewriting existing code.
Classes and Structure:
• Abstract Class PaymentMethod:
o Member Function:
▪ processPayment(double amount): Pure virtual function to handle
transactions.
• Derived Class CreditCard:
o Data Members:
▪ cardNumber (string): Stores the card number.
o Implements processPayment() to validate and process payments.
• Derived Class DigitalWallet:
o Data Members:
▪ DigitalWallet (double): Tracks available funds.
o Implements processPayment() to deduct balance.

Flow:
• Create CreditCard and DigitalWallet objects.
• Simulate payments and check for success/failure.
*/
#include <iostream>
using namespace std;
class PaymentMethod{
    public:
        virtual void processPayment(double amount)=0;
};
class CreditCard:PaymentMethod{
    private:
        string CardNumber;
        
    public:
        CreditCard(string PM=""):CardNumber(PM){cout<<"CreditCard Created\n";}
        void processPayment(double amount)override{
            char p='P';
            char k='K';
            if(CardNumber[0]==p&&CardNumber[1]==k){//CardNumber should start from PK
                cout<<"Validation Successful!\nPayment OF RS:   "<<amount<<"    Processed From Card NUMBER:  "<<CardNumber<<endl;
            }
            else cout<<"Invalid Card Number!\nTry Again"<<endl;

        }
};
class DigitalWallet:PaymentMethod{
    private:
        double  Balance;

    public:
        DigitalWallet(double bal=0):Balance(bal){{cout<<"DigitalWallet Created\n";}}
        void processPayment(double amount)override{
            char p=p;
            char k=k;
            if(amount<=Balance){//CardNumber should start from PK
                cout<<"Transfering RS:  "<<amount<<endl;
                Balance-=amount;
            }
            else cout<<"Cannot Transfer Rs:    "<<amount<<"    AS Your Balance is Only RS:    "<<Balance<<endl;

        }
};
int main(){
    cout<<"=============================================================="<<endl;
    cout<<"********************E-COMMERCE System********************\n"<<endl;
    CreditCard C1("PK101");
    CreditCard C2("101PK");
    DigitalWallet D1(3000);
    DigitalWallet D2(4000);
    cout<<"\n=============================================================="<<endl;
    C1.processPayment(1000);
    C2.processPayment(2000);
    cout<<"\n=============================================================="<<endl;
    D1.processPayment(2000);
    D2.processPayment(5000);

}
