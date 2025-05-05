#include<iostream>
#include<exception>
using namespace std;
class StackOverflowException:public exception{
    public:
        const char* what()const noexcept override{
            return "Stack is Full";
        }
};
class StackUnderflowException:public exception{
    public:
        const char* what()const noexcept override{
            return "Stack is Empty";
        }
};
template <typename T> class Stack{
    private:
       static const int cap=2;
        T capacity[cap];
        int size;
    public:
        Stack(){
            capacity[0]=T();
            capacity[1]=T();
            size=-1;
        }
        void push(int n){
            try{
                if(size>=cap-1){
                    throw StackOverflowException();
                }
                else {
                    capacity[++size]=n;
                }
            }
            catch(StackOverflowException& oe){
                cout<<oe.what()<<endl;
            }
            
        }
        void pop(){
            try{
                if(size<0){
                    throw StackUnderflowException();
                }
                else {
                    capacity[size--];
                }
            }
            catch(StackUnderflowException& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            
        }
};
int main(){
    Stack<int> s1,s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s2.pop();
}