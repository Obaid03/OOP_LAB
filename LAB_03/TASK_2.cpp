#include <iostream>
#include <conio.h>
using namespace std;
class Tollbooth{
    private:
    unsigned int total_cars;
    double money_collected;
    public:
    Tollbooth(){
        total_cars=0;
        money_collected=0;
    }
    void payingcar(){
        total_cars++;
        money_collected+=0.50;
    }
    void nopay(){
        total_cars++;
    }
    void diplay(){
        cout<<"TOTAL NUMBER OF CARS PASSED\n"<<total_cars<<endl;
        cout<<"TOTAL MONEY COLLECTED\n"<<money_collected<<endl;
    }
};
int main(){
    Tollbooth t1;
    char choice;
    cout<<"\nMENU\nP:PAYING CARS\nN:NON PAYING CARS\nESC: EXIT";
    while(1){
        cout<<"\nCHOICE\t";
        choice=getche();
        switch (choice){
            case 'P':
            case 'p':t1.payingcar();break;
            case 'N':
            case 'n':t1.nopay();break;
            case 27:t1.diplay();return 0;
            default:
            cout<<"INVALID CHOICE"<<endl;return 0;
        }
    }
    return 0;
}