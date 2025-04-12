/*Question 3: Can a friend function access private and protected members of a class without
using an object of that class?
Problem Statement:
A friend function is granted access to private and protected members of a class.
 Does it always need an object to access these members?
 Can a friend function access them directly without an object?
 Under what conditions might it fail?
Justify your answer with supporting C++ code.
*/
/*                  ANSWER                      */
/*: Friend Function can access private/protected data members of a class, but it can not 
access them without object. Since  friend function is not a member function of class and  
it does not have  “this” pointer, so it cannot access private/protected data members of 
class without the object.*/

#include <iostream>
using namespace std;
class complex{
    private:
        int a;
    protected:
        int b;
    public:
        complex(int x =0,int y=0):a(x),b(y){}
        friend complex access(complex &c);
        void show(){
            
        }
};
complex access(complex &c){
    cout <<"A =     "<<c.a<<endl;
    cout <<"B =     "<<c.b<<endl;
    return 0;
}
int main(){
    complex c(4,5);
    access(c);
}