/*You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
*/
#include <iostream>
using namespace std;
int main(){
    int n,i,j,max=0,area,min;
    cout<<"Enter The Number of Heights \n";
    cin >> n;
    int *height = new int[n];
    for(i=0;i<n;i++){
        cout<<"Enter the hight at element "<<i<<endl;
        cin>>height[i];
    }
     for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            min= height[i];
            if (height[j] < height[i]) {
                min= height[j];
            }

            area = min * (j - i);

            if (area > max) {
                max= area;
            }
        }
    }
    cout<<"The Maximum volume is "<<max<<endl;

}