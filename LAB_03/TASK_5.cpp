/*Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
only one entry is needed per day.
Create the following methods for your class:
 Add a task. Thisfunction accepts three parameters: task details, date and month. It should add
 a task on the day specified.
 Remove a task. Accepts the date and month as a parameter to remove the task from.
 Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
you’ll remove a task, and display the updated task list.*/
#include <iostream>
using namespace std;
class calender{
    private:
        string month[12][31];
        int year;
    public:
        calender(int y){
            for(int i=0;i<12;i++){
                for (int j=0;j<31;j++){
                    month[i][j]="\0";
                }
            }
            year=y;
        }
        void AddTask(int day,int mon,string task){
            if(day<1||day>31||mon<1||mon>12){
                cout<<"Invalid Input"<<endl;
            }
            else{
                month[mon-1][day-1]=task;
            }
        }
        void removeTask(int day,int mon,string task ){
            if(day<1||day>31||mon<1||mon>12){
                cout<<"Invalid Input"<<endl;
            }
            else{
                month[mon-1][day-1]="\0";
            }
        }
        void display(){
            cout<<"EVENTS FOR THE YEAR  "<<year<<endl;
            for(int i=0;i<12;i++){
                for (int j=0;j<31;j++){
                    if(!month[i][j].empty()){
                    cout<<"month    "<<i+1<<"   Day    "<<j+1<<"   "<<month[i][j]<<endl;
                }}
            }
        }
};
int main(){
    cout<<"ACTUAL EVENTS FOR THE YEAR"<<endl;
    calender c1(2025);
    c1.AddTask(25,1,"Birtday");
    c1.AddTask(20,5,"EID");
    c1.AddTask(10,6,"FEE SUBMISSSION");
    c1.AddTask(9,9,"Assignment Submission");
    c1.AddTask(25,12,"PAKISTAN DAY");
    c1.display();
    cout<<" REMOVING TASK(ASSIGNMENT SUBMISSION)"<<endl;
    cout<<" EVENTS AFTER REMOVAL"<<endl;
    c1.removeTask(9,9,"Assignment Submission");
    c1.display();
}
