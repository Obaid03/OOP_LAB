#include<iostream>
#include<fstream>
using namespace std;
struct Resume{
    string name;
    string email;
    int experience;
    string summary;
};

int main(){
    Resume r1,r2;
    cout<<"Enter Details for Resume   "<<endl;
    cout<<"Enter Name:     ";cin>>r1.name;
    cout<<"Enter Email:     ";cin>>r1.email;
    cout<<"Enter Years Of Experience:     ";cin>>r1.experience;
    cout<<"Enter Summary:     ";cin>>r1.summary;
    
    ofstream file("TASK_2.txt",ios::out);//Opening File
    if(!file.is_open()){
        cout<<"Error opening File"<<endl;
        return 1;}
    file<<"NAME:  "<<r1.name;
    file<<"   Email:  "<<r1.email;
    file<<"   Experience:  "<<r1.experience;
    file<<"   Summary:     "<<r1.summary;
    file<<"\n\n";
    file.flush();
    file.close();
    cout<<"Resume DATA STORED IN FILE "<<endl;
    cout<<"\n\n";
    
    cin.ignore();
    // New Data
    cout<<"Enter Details for Resume   "<<endl;//Trunc
    cout<<"Enter Name:     ";cin>>r2.name;
    cout<<"Enter Email:     ";cin>>r2.email;
    cout<<"Enter Years Of Experience:     ";cin>>r2.experience;
    cout<<"Enter Summary:     ";cin>>r2.summary;
    
    file.open("TASK_2.txt",ios::trunc);//Opening File in Trunc Mode
    if(!file.is_open()){
        cout<<"Error opening File"<<endl;
        return 1;}
    file<<"NAME:  "<<r2.name;
    file<<"   Email:  "<<r2.email;
    file<<"   Experience:  "<<r2.experience;
    file<<"   Summary:     "<<r2.summary;
    file<<"\n\n";
    file.flush();
    cout<<"Resume DATA STORED IN FILE "<<endl;
    cout<<"\n\n";
    file.close();

    string line;
    ifstream File;
    File.open("TASK_2.txt");//Opening To Read
    if(File.is_open()){
    while(getline(File,line)){
          cout <<line<<endl;
    }
     File.close();
    }
    else cout<<"Unable to open file"<<endl;    
    return 0;
}
