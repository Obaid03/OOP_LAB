/*Problem: A fitness app wants to help users track calories burned during activities like
running and cycling. Each activity requires unique calculations (e.g., distance vs. speed), but
the app must present results consistently. The system should allow adding new activities
(e.g., swimming) in the future.
Classes and Structure:
• Abstract Class Activity:
o Member Function:
▪ calculateCaloriesBurned(): Pure virtual function to compute calories.

• Derived Class Running:
o Data Members:
▪ distance (double): Stores distance in kilometers.
▪ time (double): Stores duration in minutes.
o Implements calculateCaloriesBurned() for running.
• Derived Class Cycling:

o Data Members:
▪ speed (double): Stores speed in km/h.
▪ time (double): Stores duration in hours.
o Implements calculateCaloriesBurned() for cycling.

Flow:
• Create Running and Cycling objects.
• Display calories burned for each activity.*/
#include<iostream>
using namespace std;
class Activity{
    public:
        virtual void CalculateCaloriesBurned()=0; 
};
class Running:public Activity{
    private:
        double distance;//kms
        double time;//hours
    public:
        Running(double dis=0,double ti=0):distance(dis),time(ti){cout<<"Running Created"<<endl;}
        void CalculateCaloriesBurned()override{
            cout<<"Calories Burned From Running:"<<endl;//assuming average weight(70) and my own formula
            double cal=70*distance*time;
            cout<<"You Burned   "<<cal<<"   Calories after Running for   "<<time<<"   hrs to cover a distance of   "<<distance<<"   KMs"<<endl;
        }
};
class Cycling:public Activity{
    private:
        double speed;//km/hr
        double time;//hours
    public:
        Cycling(double dis=0,double sp=0):speed(dis),time(sp){cout<<"Cycling Created"<<endl;}
        void CalculateCaloriesBurned()override{
            cout<<"Calories Burned From Running:"<<endl;//assuming average weight(70) and my own formula
            double cal=70*speed*time;
            cout<<"You Burned   "<<cal<<"   Calories after cycling for   "<<time<<"   hrs with a speed of   "<<speed<<"   KM/hr"<<endl;
        }
};
int main(){
    cout<<"=============================================================="<<endl;
    cout<<"********************Fitness APP********************\n"<<endl;
    Running R1(10,2);
    Cycling C1(100,2);
    cout<<"\n=============================================================="<<endl;
    R1.CalculateCaloriesBurned();
    C1.CalculateCaloriesBurned();
    cout<<"\n=============================================================="<<endl;
}