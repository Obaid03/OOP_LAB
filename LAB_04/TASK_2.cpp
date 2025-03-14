/*TASK # 02
Scenario:
A library system allows users to borrow and return books. The system should:
1. Add new books to the collection.
2. Borrow books (check availability).
3. Return books.
4. Display all available books.
Requirements:
 Implement a Book class with attributes: ID, title, author, availability.
 Implement a Library class with:
1. Method to add a book (with unique ID).
2. Method to borrow a book (updates availability).
3. Method to return a book (marks it available).
4. Method to display all available books.
 Store book records dynamically using pointers and DMA.
 Use constructor overloading to initialize books with or without availability status.*/
#include<iostream>
using namespace std;
class Book{

    public:

    int Id;
    string title;
    string name;
    bool Availability;
    Book(){
        
    }
    Book(int id,string title,string name,bool Available){
        this->Id = id;
        this->title = title;
        this->name = name;
        this->Availability = Available;
    }
    Book(int id,string title,string name){
        this->Id = id;
        this->title = title;
        this->name = name;
    }
    
};
class Library{
    
    Book *B1 =new Book[0];
    int noOfBooks =0;
    public:
    void addBook(Book BN){
       Book *B = new Book[noOfBooks +1];

        for(int i=0;i<noOfBooks;i++){
            B[i].Id = B1[i].Id;
            B[i].name = B1[i].name;
            B[i].title = B1[i].title;
            B[i].Availability = B1[i].Availability;
        }
            B[noOfBooks].Id=BN.Id;
            B[noOfBooks].title=BN.title;
            B[noOfBooks].name=BN.name;
            B[noOfBooks].Availability=BN.Availability;
        noOfBooks++;
        delete [] B1;
        B1 = B;

    }
    void BorrowBook(int id){
            for(int i=0;i<noOfBooks;i++){
                if(B1[i].Id == id){
                    B1[i].Availability = false;
                }
            }
    }
    void ReturnBook(int id){
            for(int i=0;i<noOfBooks;i++){
                if(B1[i].Id == id){
                    B1[i].Availability = true;
                }
            }
    }
    void DisplayBooks(){
        for(int i=0;i<noOfBooks;i++){
            cout<<"Book "<<i+1<<" : \n"<<endl;
            cout<<"Book Name : "<<B1[i].name<<endl;
            cout<<"Book ID : "<<B1[i].Id<<endl;
            cout<<"Book Title : "<<B1[i].title<<endl;
            cout<<"Book Available : "<<B1[i].Availability<<endl;
        }
    }
};
int main(){

Library L1;
Book B1(123,"Science","Discovery",true);
Book B2(13,"Wildlife","Jungle",true);
L1.addBook(B1);
L1.addBook(B2);
L1.DisplayBooks();
L1.BorrowBook(123);
L1.DisplayBooks();
return 0;
}