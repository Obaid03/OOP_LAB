#include <iostream>
using namespace std;

class Time{
    private:
    int hrs;
    int mins;
    int secs;

    public:
    Time(){
        hrs=0;
        mins=0;
        secs=0;
    }
    Time(int hr,int min,int sec){
        hrs=hr;
        mins=min;
        secs=sec;
    }
    void display(){
        cout <<hrs<<":"<<mins<<":"<<secs<<endl;
    }
    Time addtime(Time t1){
        Time temp;
        temp.hrs=hrs+t1.hrs;
        temp.mins=mins+t1.mins;
        temp.secs=secs+t1.secs;
        return temp;       
    }   
};
int main(){
    Time time1(3, 45, 13),time2(2,10,20),time3;
    time3=time1.addtime(time2);
    time3.display();
}