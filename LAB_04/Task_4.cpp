/*You are building a car rental system. Create a class `Car` to manage cars available for rent.
Requirements:
1. Attributes:
 `carID` (int)
 `model` (string)
 `year` (int)
 `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:

 `rentCar()`: Marks the car as rented.
 `returnCar()`: Marks the car as available.
 `isVintage()`: Returns `true` if the car's year is before 2000.

5. Create a few `Car` objects and test the methods.*/
#include<iostream>
using namespace std;
class Car{
    private:
        int carId;
        string model;
        int year;
        bool isrented;
    public:
        Car(){
            carId=0; model='\0';year=0;isrented=0;
        }
        Car(int carID,string model,int year,bool isrented){
            this->carId=carID;
            this->model=model;
            this->year=year;
            this->isrented=isrented;
        }
        void rent(){
            isrented=true;
            cout<<"CAR SUCCESSFULY RENTED\n";
            cout <<"AVAILABE FOR RENT ->       "<< (isrented ? "YES" : "NO") << endl;
        }
        void returnCar(){
            isrented=false;
            cout<<"CAR SUCCESSFULY RETURNED\n";
            cout << "AVAILABE FOR RENT ->    "<<(isrented ? "YES" : "NO") << endl;
        }
        bool isvintage(){
            if(year<200){
                return true;
            }
            else    return false;
        }
        void displayInfo() {
        cout << "Car ID: " << carId << "\nModel: " << model 
             << "\nYear: " << year << "\nRented: " << (isrented ? "Yes" : "No") << endl;
    }
};
int main(){
    cout<<"-----------CAR RENTAL SYSTEM-----------"<<endl;
    Car c1;Car c2(1234,"BMW",2024,false);Car c3(321,"Bugatti",1993,true);
    cout<<"-----------CAR 1-----------"<<endl;
    c1.displayInfo();
    cout<<"-----------CAR 2-----------"<<endl;
    c2.displayInfo();
    c2.rent();
    c2.isvintage();
    cout<<"-----------CAR 3-----------"<<endl;
    c3.displayInfo();
    c3.returnCar();
    c3.isvintage();
return 0;
}

