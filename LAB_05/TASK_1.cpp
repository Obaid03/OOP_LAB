/*Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and
allareas to display the updated values.*/

#include <iostream>
using namespace std;

class Square{
    private:    
        float sidelength;
        float area;
        static float allareas;
    public: 
        Square(){
            sidelength=0.00;area=0.00;
        }
        Square(float sl){
            sidelength=sl;
        }
        float get_sidelength(){
            return sidelength;
        }
        float get_area(){
            return area;
        }
        void set_sidelength(float s1){
            this-> sidelength=s1;
        }
        void calArea(float s1){
            cout<<"SIDE--> "<<s1<<endl;
            this-> area=s1*s1;
            cout<<"AREA--> "<<area<<endl;
            allareas+=area;
            cout<<"ALL AREAS--> \n"<<allareas<<endl;
        }
};
    float Square::allareas=0.00;

int main(){
    Square Side1(5),Side2(8),Side3(10);
    cout<<"---------- SQUARE 1 ---------- \n"<<endl;
    Side1.calArea(5);
    cout<<"---------- SQUARE 2 ---------- \n"<<endl;
    Side1.calArea(8);
    cout<<"---------- SQUARE 3 ---------- \n"<<endl;
    Side1.calArea(10);
}
