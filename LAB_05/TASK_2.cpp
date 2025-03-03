/*Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%*/
#include <iostream>
using namespace std;

class LoanHelper{
    private:
        const float interestRate;
        float amount;
        int months;
    public:
        LoanHelper():interestRate(0.00),amount(0.00),months(0){}
        LoanHelper(float iR,float a,int m):interestRate(iR),amount(a),months(m){}
        void LoanPayement(float iR,float a,int m){
            float payment=0,LoanPayment=0;
            payment = amount/months;
            LoanPayment=payment+(payment*(interestRate/100));
            cout<<"You have to PAY "<<LoanPayment<<" for "<<months<<" months to repay your Loan"<<endl;
        }

};
int main(){
    float ir,a;
    int m;
    cout<<"Enter Interest Rate\t"<<endl;                            cin >> ir;
    cout<<"Enter Amount\t"<<endl;                                   cin >> a;
    cout<<"Enter Months to Repay\t"<<endl;                          cin >> m;
    if(ir<=0.00 &&ir>=0.50){
        cout<<"Wrong Interest Rate"<<endl;
        return 0;
    }
    LoanHelper l1(ir,a,m);
    LoanHelper l2(ir,a,m);
    l2.LoanPayement(ir,a,m);
}