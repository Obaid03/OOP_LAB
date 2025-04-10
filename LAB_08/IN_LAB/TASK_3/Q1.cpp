/*Question 1: Can a friend function be used to overload an operator that modifies the
invoking object?
Problem Statement:
Consider the += operator, which modifies the left-hand operand. Can a friend function be used
to overload this operator?
 If yes, how should it be implemented?
 If no, what alternative approach should be used?
Justify your answer with supporting C++ code.*/


//Answer
/*Yes, a friend function can be used to overload an operator*/

//Implementation

#include <iostream>
using namespace std;
class complex{
    private:
        int a,b;
    public:
        complex(int x =0, int y=0):a(x),b(y){}
        friend complex operator +=(complex &c,complex &c1);
        void show(){
            cout <<"A =     "<<a<<endl;
            cout <<"B =     "<<b<<endl;
        }
};
complex operator+=(complex &c,complex &c1){
    complex temp;
    temp.a=c.a+c1.a;
    temp.b=c.b+c1.b;
    // temp.a+=c.a;
    // temp.b+=c.b;
    return temp;
}
int main(){
    complex c(4,4),c1(4,4),c2;
    c.show();
    c1.show();
    c2=operator+=(c,c1);
    c2.show();

}