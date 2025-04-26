#include <iostream>
#include <fstream>
using namespace std;
//Dummy Data
struct chap1{
    string name="Introduction to C++";
    string content="This chapter covers the basics of C++ programming.";
}c1;
struct chap2{
    string name="Object-Oriented Programming";
    string content="This chapter explains classes, objects, inheritance, and polymorphism.";
}c2;
int main(){
    //Writing in Chapter 1
    ofstream file("TASK_3(CH#1).txt",ios::out);
    if(!file){
        cout<<"Error opening CHAPTER 1(Writing)"<<endl;
        return 1;
    }
    file<<"CHAPTER NAME:    "<<c1.name;
    file<<endl;
    file<<"CHAPTER Content:    "<<c1.content;
    file.close();
    //Writing in Chapter 2
    file.open("TASK_3(CH#2).txt",ios::out);
    if(!file){
        cout<<"Error opening CHAPTER 2(Writing)"<<endl;
        return 1;
    }
    file<<"CHAPTER NAME:    "<<c2.name;
    file<<endl;
    file<<"CHAPTER Content:    "<<c2.content;
    file.close();
    
    ofstream book;

    //Reading from Chapter 1
    ifstream chap1("TASK_3(CH#1).txt");
    string line;
    if(chap1){
        book.open("TASK_3(Book).txt",ios::app);
        if(!book){
            cout<<"Error opening BOOK(Writing CHAPTER 1)"<<endl;
            return 1;}
        while (getline(chap1,line)){
            book<<line<<endl;
            
      }
      book<<endl;//newline between the chapters
      book.close();
      chap1.close();
    }
    else cout<<"Unable to open chap1(Reading)"<<endl;
    
    //Reading from Chapter 2

    ifstream chap2("TASK_3(CH#2).txt");
    string l;
    if(chap2){
        book.open("TASK_3(Book).txt",ios::app);
            if(!book){
                cout<<"Error opening BOOK(Writing CHAPTER 2)"<<endl;
                return 1;}
        while (getline(chap2,l)){
            book<<l<<endl;
      }
      book<<endl;
      book.close();
      chap2.close();
    }
    else cout<<"Unable to open chap2(Reading)"<<endl;

    ifstream Book("TASK_3(Book).txt");
    string Line;
    if(Book){
        while (getline(Book,Line)){
            cout<<Line<<endl;
      }
      Book.close();
    }
    else cout<<"Unable to open Book(Reading)"<<endl;

    
    
}
