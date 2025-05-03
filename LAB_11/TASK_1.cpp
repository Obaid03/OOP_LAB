#include<iostream>
#include <exception>
using namespace std;
class InvalidValueException:public exception{
    public:
        const char* what()const noexcept override{
            return "Age Cannot be nagative or greater than 120";
        }
};
void validateAge(int age){
    if (age>120||age<0){
        throw InvalidValueException();
    }
    cout<<"Age Successfuly Entered"<<endl;
}
int main(){
        int age;
    try{
        cout<<"Enter Your age"<<endl;
        cin>>age;
        validateAge(age);
    }
    catch(InvalidValueException I){
        cout<<I.what();
    }
    
}