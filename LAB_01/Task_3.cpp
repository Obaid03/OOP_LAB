


/*Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1]
*/
#include <iostream>
using namespace std;
int main () {
    int n,i,t,j;
    cout<<"Enter the Number of Elements"<<endl;
    cin>>n;
    int *num= new int[n];
    if (!num){
        cout << "allocation of memory failed\n";}
    
    for (i=0;i<n;i++){
        cout<<"\nEnter Element "<<i+1<<endl;                cin>>num[i];}

        cout<<"ENTER TARGET Number"<<endl;                  cin>>t;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((num[i]+num[j+1])==t){
                cout<<"\n["<<i<<","<<j+1<<"]"<<endl;
                cout<<"\n num["<<i<<"]"<<"+"<<"num["<<j+1<<"]" "=="<<t<<endl;
                cout<<"so we return"<<"["<<i<<","<<j+1<<"]"<<endl;

                return 0;            }
        }
    }
    cout<<"No element is found"<<endl;                                            
delete num;
}