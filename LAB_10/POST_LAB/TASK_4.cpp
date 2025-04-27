/*Write the sentence "C++ is a powerful programming language." to a file named
info.txt using ofstream in ios::out mode.
2. Reopen the file using fstream with both ios::in | ios::out modes.
3. Display the initial position of get pointer using tellg() and put pointer using tellp().
4. Use seekg(6) to move the read pointer to the word "powerful" and read the word
from there.
5. Use seekp(6) to move the write pointer to the same position, and overwrite
"powerful" with "dynamic" (same length).
6. Use tellg() and tellp() again to show the new pointer positions.
7. Display the updated content of the file.*/

#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string word,line;
    ofstream info("info.txt",ios::out);
    if(!info){
        cout<<"Error Creating/Opening Info.txt"<<endl;
        return 1;
    }
    info<<"C++ is a powerful programming language."<<endl;
    info.close();
    fstream file("info.txt",ios::in|ios::out);
    if(!file){
        cout<<"Error Creating/Opening Info.txt"<<endl;
        return 1;
    }
    cout<<"Position of Get Pointer:    "<<file.tellg()<<endl;
    cout<<"Position of Put Pointer:    "<<file.tellp()<<endl;
    file.seekg(9);
    file>>word;
    cout<<"Reading From File at 9th Index:  "<<word<<endl;
    file.seekp(9);
    file<<"dynamic*";
    cout<<"Position of Get Pointer:    "<<file.tellg()<<endl;
    cout<<"Position of Put Pointer:    "<<file.tellp()<<endl;
    file.seekg(0);
    getline(file,line);
    cout<<line<<endl;
    file.close();

}