#include <iostream>
#include "Book.h"
// #include "Library.h"
int main(){
    cout<<"=============================================================="<<endl;
    cout<<"********************Library Management System********************\n"<<endl;
    book b1("Physics","Newton","Ph101");
    book b2("chemistry","chewton","ch101");
    book b3("olio","bewton","be101");
    cout<<"TITLE:   "<<b1.getTitle()<<endl;
    cout<<"Author:   "<<b1.getAuthor()<<endl;
    cout<<"ISBN:   "<<b1.getISBN()<<endl;
    cout<<"TITLE:   "<<b2.getTitle()<<endl;
    cout<<"Author:   "<<b2.getAuthor()<<endl;
    cout<<"ISBN:   "<<b2.getISBN()<<endl;
    cout<<"TITLE:   "<<b3.getTitle()<<endl;
    cout<<"Author:   "<<b3.getAuthor()<<endl;
    cout<<"ISBN:   "<<b3.getISBN()<<endl;
    
}