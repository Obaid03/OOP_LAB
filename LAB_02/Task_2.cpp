/*Write a C++ program that:
 Reads n strings from the user and stores them in a dynamically allocated array of char*.
 Prints the strings in reverse order using pointer arithmetic.
 Finds and prints the string with the most vowels (a, e, i, o, u).
 Calculates and prints the average length of all the strings.
Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,i,j,m,avg=0,vowel=0,temp=0,u=0,y;
    char mostvowels[40];
    cout<< "ENTER the Number(n) of Strings"<< endl;
    cin >> n;
    cin.ignore();
    string *strings= new string[n];
    // Taking Input
     for(i=0;i<n;i++){
        cout<<"Enter The String At Element "<<i+1<<endl;
        getline(cin,*(strings+i));
    }
    // REVERSING
    for(i=0;i<n;i++){
        m=strings[i].length();
        for(j=m;j>=0;j--){
            cout<< strings[i][j];
    }
    avg=avg+m;
    cout <<endl;}
    // COUNTING VOWELS
    for(i=0;i<n;i++){
        m=strings[i].length();
        for(j=0;j<m;j++){
            if(strings[i][j]=='a'||strings[i][j]=='e'||strings[i][j]=='i'||strings[i][j]==strings[i][j]=='o'||strings[i][j]=='u'
            ||strings[i][j]=='A'||strings[i][j]=='E'||strings[i][j]=='I'||strings[i][j]=='O'||strings[i][j]=='U'){
                temp=temp+1;}}
    if (temp>vowel){
        vowel=temp;
        u=i;}}   
        y=avg/n;
        cout <<"String with most wovels is:"<<strings[u]<<endl;
        cout<<"THE AVERAGE LENGTH IS :"<<y<<endl;
}