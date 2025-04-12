/*                          Question 2:
 Is it possible to overload an operator using a friend function if one of the
operands is a primitive data type?
Problem Statement:
Suppose we want to overload the + operator to allow addition between an object and a primitive
type (e.g., object + int).
 Can a friend function handle this case?
 If yes, how would it be implemented?
 If no, what limitations exist?
Justify your answer with supporting C++ code.*/

//                  Answer

/*                  Yes             */

//Implementation

#include <iostream>
using namespace std;
class complex{
    private:
        int a;
    public:
        complex(int x =0):a(x){}
        friend complex operator +(complex &c,const int n);
        void show(){
            cout <<"A =     "<<a<<endl;
        }
};
complex operator+(complex &c,const int n){
    complex temp;
    temp.a=c.a+n;
    return temp;
}
int main(){
    complex c(4);
    c.show();
    c=c+20;
    c.show();
}
