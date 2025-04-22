/*You are building a student record management tool for a university system.
Requirements:
1. Define a structure Student with the following fields:
○ int id
○ string name
○ float gpa
2. Prompt the user to enter data for 5 students.
3. Write these records to a file named students.txt using ofstream with ios::out
mode.
4. Then, allow the user to append 1 additional student record using ios::app mode
(open in append mode and write without erasing old content).
5. Finally, read and display all student records from the file using ifstream.*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Student{
    int id;
    string name;
    float gpa;
    Student(){}
    Student(int i,string n,float gp):id(i),name(n),gpa(gp){}};
int main(){
    Student S[3];
    ofstream outputFile("Example.txt",ios::out|ios::app);
    if(!outputFile){
        cout<<"Error opening File"<<endl;
        return 1;
    }
    for(int i=0;i<3;i++){
        cout<<"Enter Your Name:     ";cin>>S[i].name;
        cout<<"Enter Your ID:     ";cin>>S[i].id;
        cout<<"Enter Your GPA:     ";cin>>S[i].gpa;
        // S[i](id,name,gpa);
        if(!outputFile){
            cout<<"Error opening File"<<endl;
            return 1;}
        outputFile<<"NAME:  "<<S[i].name;
        outputFile<<"   ID:  "<<S[i].id;
        outputFile<<"   GPA:  "<<S[i].gpa;
        outputFile<<"\n\n";
        outputFile.flush();
        cout<<"DATA STORED IN FILE"<<endl;
        

    }
    // outputFile.open("Example.txt",ios::app);
    // if(!outputFile){
    //     cout<<"Error opening File"<<endl;
    //     return 1;
    // }
    Student S1;
    cout<<"Enter Student Details To append"<<endl;
    cout<<"Enter Your Name:     ";cin>>S1.name;
    cout<<"Enter Your ID:     ";cin>>S1.id;
    cout<<"Enter Your GPA:     ";cin>>S1.gpa;
    outputFile<<"NAME:  "<<S1.name;
    outputFile<<"   ID:  "<<S1.id;
    outputFile<<"   GPA:  "<<S1.gpa;
    outputFile<<"\n\n";
    outputFile.flush();
    outputFile.close();
    cout<<"DATA STORED IN FILE"<<endl;
    string line;
    ifstream file;
    file.open("student.txt");
    if(file.is_open()){
    while (getline(file,line)){
          cout <<line<<endl;
    }
     file.close();
    }
    else cout<<"Unable to open file"<<endl;


    return 0;

}
