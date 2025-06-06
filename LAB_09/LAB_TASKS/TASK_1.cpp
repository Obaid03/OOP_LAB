/*Problem: A vehicle rental company is expanding its services to include cars, bikes, and
future vehicle types. They need a flexible system to manage daily rates and display vehicle
details without exposing internal calculations. The goal is to ensure new vehicle types (e.g.,
scooters, trucks) can be added seamlessly while maintaining a consistent interface for
customers to view rental options.
Classes and Structure:
• Abstract Class Vehicle:
o Data Members:
▪ model (string): Stores the vehicle’s model name.
▪ rate (double): Stores the daily rental rate.
o Member Functions:
▪ getDailyRate(): Pure virtual function to return the daily rate.
▪ displayDetails(): Pure virtual function to show model and rate.

• Derived Class Car:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide car-specific
behavior.
• Derived Class Bike:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide bike-specific
behavior.

Flow:
• Create Car and Bike objects.
• Use polymorphism to call displayDetails() and getDailyRate() for each vehicle.*/

#include <iostream>
using namespace std;

class Vehicle{
    protected:
        string model;
        double rate;
    public:
    Vehicle(string m,double r):model(m),rate(r){}
        virtual double getDailyRate()=0;
        virtual void DisplayDetails()=0;
};
class Car:public Vehicle{
    public:
        Car(string m,double r):Vehicle(m,r){}
        double getDailyRate() override {
            return rate;}
        // string getmodel()const{
        //     return model;
        // }
        void DisplayDetails() override {
            cout<<"CAR'S Model is -->"<<model<<endl;
            cout<<"CAR'S Rental Rate is -->"<<getDailyRate()<<endl;
    }
};
class Bike:public Vehicle{
    public:
        Bike(string m,double r):Vehicle(m,r){}
        double getDailyRate()override {
            return rate;
    }
        void DisplayDetails()override {
            cout<<"BIKE'S Model is -->"<<model<<endl;
            cout<<"BIKE'S Rental Rate is -->"<<getDailyRate()<<endl;
    }

};
int main(){
    Car c1("BMW", 1000);
    Bike b1("H2R", 100);
    Vehicle* v=&c1;
    Vehicle* v1=&b1;
    v->DisplayDetails();
    v1->DisplayDetails();
}
