/*Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/

#include <iostream>
using namespace std;
class ValidateString{
    private:
        string sample;
    public:
        ValidateString(string s):sample(s){}
        void check(string str1){
            for(int i=0;i<str1.length();i++){
                if(str1[i]>='a'&&str1[i]<='z'||str1[i]>='A'&&str1[i]<='Z'){
                    continue;
                }
                else{
                    cout << "Invalid string\n" << endl;
                    return;
                }
            }
            cout << "Valid string\n" << endl;
    
         }
};
int main (){
    ValidateString v1("obaid12"),v2("obaid"),v3("OBAID@!");
    cout<<"---------- STRING 1 ---------- \n"<<endl;
    v1.check("obaid12");
    cout<<"---------- STRING 2 ---------- \n"<<endl;
    v2.check("obaid");
    cout<<"---------- STRING 3 ---------- \n"<<endl;
    v3.check("OBAID@!");
}