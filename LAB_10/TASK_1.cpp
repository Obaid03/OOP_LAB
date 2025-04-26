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
    Student S[5];
    ofstream outputFile("Example.txt",ios::out);//Creating||Opening File
    if(!outputFile){
        cout<<"Error opening File"<<endl;
        return 1;
    }
    for(int i=0;i<5;i++){
        cout<<"Enter Details for Student    "<<i+1<<endl;
        cout<<"Enter Name:     ";cin>>S[i].name;
        cout<<"Enter ID:     ";cin>>S[i].id;
        cout<<"Enter GPA:     ";cin>>S[i].gpa;
        if(!outputFile){
            cout<<"Error opening File"<<endl;
            return 1;}
        outputFile<<"NAME:  "<<S[i].name;
        outputFile<<"   ID:  "<<S[i].id;
        outputFile<<"   GPA:  "<<S[i].gpa;
        outputFile<<"\n\n";
        outputFile.flush();
        cout<<"DATA STORED IN FILE FOR Student "<<i+1<<endl;
        cout<<"\n\n";
    }
    outputFile.close();//Closing File
    
    outputFile.open("Example.txt",ios::app);//Append mode
    Student S1;
    cout<<"Enter New Student Details"<<endl;
    cout<<"Enter Name:     ";cin>>S1.name;
    cout<<"Enter ID:     ";cin>>S1.id;
    cout<<"Enter GPA:     ";cin>>S1.gpa;
    outputFile<<"NAME:  "<<S1.name;
    outputFile<<"   ID:  "<<S1.id;
    outputFile<<"   GPA:  "<<S1.gpa;
    outputFile<<"\n\n";
    outputFile.flush();
    outputFile.close();//Closing Fil
    cout<<"New Student DATA STORED IN FILE"<<endl;
    cout<<"\n\n";
    string line;
    ifstream file;
    file.open("Example.txt");//Opening To Read
    if(file.is_open()){
    while (getline(file,line)){
          cout <<line<<endl;
    }
     file.close();
    }
    else cout<<"Unable to open file"<<endl;
    return 0;

}
