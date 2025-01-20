/* Write a C++ program to check whether a given number is prime or not. Allow
the user to input a number and display whether it's prime or not? */

#include <iostream>
using namespace std;
int main () {
    int i,n;
    cout<<"Enter the Number"<<endl;
    cin>>n;
    if(n==1||n==0){
        cout<<"It is not a prime number"<<endl;
        return 0;
    }
    for (i=2;i<n;i++)
    {
        if (n%i==0)
        {
            cout<<"It is not a prime Number"<<endl;
            return 0;
        } 
    }
    cout<<"It is a prime Number"<<endl;
return 0;
}