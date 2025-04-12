/*Question 1: Can a friend function be used to overload an operator that modifies the
invoking object?
Problem Statement:
Consider the += operator, which modifies the left-hand operand. Can a friend function be used
to overload this operator?
 If yes, how should it be implemented?
 If no, what alternative approach should be used?
Justify your answer with supporting C++ code.*/


//Answer
/*YES*/

//Implementation

#include <iostream>
using namespace std;
class complex{
    private:
        int a;
    public:
        complex(int x =0):a(x){}
        friend complex operator +=(complex &c,const complex &c1);
        void show(){
            cout <<"A =     "<<a<<endl;
        }
};
complex operator+=(complex &c,const complex &c1){
    c.a+=c1.a;
    return c;
}
int main(){
    complex c(4),c1(4);
    c.show();
    c1.show();
    c+=c1;
    c.show();
}
