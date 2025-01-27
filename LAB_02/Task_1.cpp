/*Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically
allocated array of type float. Then, the program should:
 Calculate the average of the numbers.
 Find the number closest to the average.
 Print the average and the number closest to it.
 Use pointer notation wherever possible.*/
#include <iostream>
using namespace std;
int main(){
    int n,i;
    float sum =0,avg=0,diff=100,closest;
    cout << "Enter the Number(n) of Numbers" << endl;
    cin >> n;
    float *group = new float[n];
    for (i=0;i<n;i++){
        cout << "enter the number at element at "<<i+1<<":"<< endl;
        cin >> group[i];
    }
    for (i=0;i<n;i++){
        sum= sum + group[i];
    }
    avg=sum/n;
    cout << avg<<endl;
    for (i=0;i<n;i++){
        for(i=0;i<n;i++){
            float temp=avg-group[i];
            if (temp<0) temp= temp*(-1);
            if (temp<diff){
                diff=temp;
                closest=*(group+i);}}} 
    cout << "The number closest to the AVERAGE is " << closest <<endl;
    delete[] group;}