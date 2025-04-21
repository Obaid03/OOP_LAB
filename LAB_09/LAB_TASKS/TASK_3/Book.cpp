#include <iostream>
using namespace std;
#include "Book.h"
book::book(string title,string author,string isbn):Title(title),Author(author),ISBN(isbn){}
string book::getTitle(){
    return Title;
}
string book::getAuthor(){
    return Author;
}
string book::getISBN(){
    return ISBN;
}