/*Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F
*/

#include <iostream>
#include <memory>
using namespace std;
typedef struct {
    float math;
    float english;
    float science;

}student;
int main () {
    int n,i;
    float total=0,avg=0,grade,tmarks=0;
    cout<<"Enter the Number of students"<<endl;
    cin>>n;
    student *s= new student[n];
    if (!s){
        cout << "allocation of memory failed\n";}
    for (i=0;i<n;i++){
        cout<<"Enter the Numbers Score in Maths for Student " <<i+1<<endl;                                           cin>>s[i].math;
        cout<<"Enter the Numbers Score in English for Student " <<i+1<<endl;                                         cin>>s[i].english;
        cout<<"Enter the Numbers Score in Science for Student " <<i+1<<endl;                                         cin>>s[i].science;
    }
    
    for (i=0;i<n;i++){
        total=(s[i].math+s[i].english+s[i].science);
        //avg=(total/3);
        tmarks=tmarks+ total;
        cout<<"\nStudent"<<i+1<<endl; 


        cout<<"The Total Score  "<<total<<endl;                                           
        grade=(total/300)*100;
        if(grade>=90 && grade <=100){
            cout<<"GRADE is A"<<endl;
        }
        else if(grade>=80 && grade <90){
            cout<<"GRADE is B"<<endl;
        } 
        else if(grade>=70 && grade <80){
            cout<<"GRADE is C"<<endl;
        } 
        else if(grade>=60 && grade <70){
            cout<<"GRADE is D"<<endl;
        } 
        else if(grade <60){
            cout<<"GRADE is F"<<endl;
        }
        else cout<<"Invalid score entered"<<endl; 

}
avg=tmarks/n;
cout<<"\n\nThe AVERAGE Score is "<<avg<<endl;

delete s;




}