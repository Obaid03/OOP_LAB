#ifndef Book
#define Book
#include<iostream>
using namespace std;
class book{
    private:
        string Title;
        string Author;
        string ISBN;
    public:
        book(string title,string author,string isbn);
        string getTitle();
        string getAuthor();
        string getISBN();
};
#endif