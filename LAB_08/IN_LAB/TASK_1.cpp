#include <iostream>
using namespace std;
class DeviceMangement{
    protected:
        const string deviceId;
        string deviceType;
        double powerRating;
        bool status;
        
    public:
        DeviceMangement(string dI="",string dT="",double pR=0,bool s=false):deviceId(dI),deviceType(dT),powerRating(pR),status(s){}
        virtual void turnOn(){
            status=true;
        }
        virtual void turnOff(){
            status=false;
        }
        virtual double calPower(int hours)=0;

};
class Light:public DeviceMangement{
    private:

    public:
        Light(string dI="",string dT="",double pR=0,bool s=false):DeviceMangement(dI,dT,pR,s){}
        void turnOn(){
            status=true;
            cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"  Turned ON !"<<endl;
        }
        void turnOff(){
            status=false;
            cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"  Turned OFF !"<<endl;
        }
        double calPower(int hours){
            powerRating=powerRating*hours;
            // cout<<""
            return powerRating;
        }
};
class Fan:public DeviceMangement{
    private:
        double speedFactor;

    public:
        Fan(string dI="",string dT="",double pR=0,bool s=false,double speed=0):DeviceMangement(dI,dT,pR,s),speedFactor(speed){}
        void turnOn(){
            status=true;
            cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"  Turned ON ! with speed Factor of:    "<<speedFactor<<endl;
        }
        void turnOff(){
            status=false;
            cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"  Turned OFF !"<<endl;
        }
        double calPower(int hours){
            powerRating=powerRating*hours*speedFactor;
            // cout<<""
            return powerRating;
        }
};
class AC:public DeviceMangement{
    private:
        double desireTemp;
        const double currentTemp=30;//no where mentioned so assumed current temperature is 30 C.

    public:
        AC(string dI="",string dT="",double pR=0,bool s=false,double dtemp=0):DeviceMangement(dI,dT,pR,s),desireTemp(dtemp){}
        void turnOn(){
            status=true;
            cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"  Turned ON ! to achieve a temperature of    "<<desireTemp<<" C"<<endl;
        }
        void turnOff(){
            if(currentTemp<=desireTemp){
                desireTemp=currentTemp;
                status=false;
                cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"  Turned OFF !"<<endl;
            }
            else cout<<"Device:  "<<deviceType<<"   with ID:    "<<deviceId<<"  didnot achieve desired Temperature,cannot turn of !"<<endl;
            
        }
        double calPower(int hours){
            powerRating=powerRating*hours*(1-(currentTemp-desireTemp)/100);
            // cout<<""
            return powerRating;
        }

};
class SecuritySystems:DeviceMangement{
    private:
        int password=123;
    public:
        SecuritySystems(string dI="",string dT="",double pR=0,bool s=false):DeviceMangement(dI,dT,pR,s){}
        void turnOn(){
            status=true;
            cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"Turned ON !"<<endl;
        }
        void turnOff(){
            status=false;
            cout<<"Device:  "<<deviceType<<"    with ID:    "<<deviceId<<"  Turned OFF !"<<endl;
            
        }
        double calPower(int hours){
            int temp;
            cout<<"Enter Password to Calculate Security Systems Power Consumptions\t";
            cin>>temp;
            if(temp==password){
                return powerRating*hours;
            }
            else {cout<<"Not Authorised to Do so"<<endl;
                return 0;}

        }
        friend void AccessSecurityLogs(SecuritySystems &obj);
        friend class MaintenanceTool;

};
class SpecialSecuritytools;
class UserManagement{
    protected:
        string UserId;
        string UserRole;
        int AccessLevel;
    public:
        UserManagement(string uI="",string uR="",int aL=0):UserId(uI),UserRole(uR),AccessLevel(aL){}
        virtual void viewAccessibleDevice(){
            if (AccessLevel==1){
                cout<<UserRole<<":   "<<UserId<<"--> Accessible Devices "<<endl;
                cout<<"LED Lights"<<endl;
                cout<<"Cieling Fans"<<endl;
                cout<<"Split AC's"<<endl;
            }
            else if(AccessLevel==2) {
                cout<<UserRole<<":   "<<UserId<<"--> Accessible Devices "<<endl;
                cout<<"LED Lights"<<endl;
                cout<<"Cieling Fans"<<endl;
                cout<<"Split AC's"<<endl;
                cout<<"Security Systems"<<endl;
            }
            else cout<<"Invalid Access Level Entered!"<<endl;
        }
        void accessSecurityLogs();

};
class SpecialSecuritytools{
    private:
        bool CameraStatus=true;//For Simplicity as proper statements not Mentioned
        bool Intrusion=true;
    public:
        friend void UserManagement::accessSecurityLogs();

};
void UserManagement::accessSecurityLogs(){
    if (AccessLevel==2){
        cout<<"Special Security Tools Access Granted to -->"<<UserRole<<"   with User ID -->"<<UserId<<endl;
        cout<<"CAMERA status Active!"<<endl;
        cout<<"NO intrusion uptill NOW!"<<endl;
        cout<<"SYSTEM Reset Not Required"<<endl;
    }
    else {
        cout<<"Special Security Tools Access Denied to -->"<<UserRole<<"   with User ID -->"<<UserId<<endl;
    }
}

int main(){
    cout<<"=============================================================="<<endl;
    cout<<"********************Home Management System********************\n"<<endl;
    //USERS
    UserManagement User1("R101","Regular User",1);
    UserManagement User2("M101","Maintanance Staff",2);
    //Devices
    Light L1("L101","LED LIGHT",1000,false);//initially off
    Fan F1("F101","Smart Fan",1500,false,3);//initially off
    AC AC1("Ac101","LED LIGHT",1000,false,25);//initially off
    SecuritySystems S1("S101","Intruder Alarm",100,false);//initially Off

    //Device Operations
    cout<<"=========================================================="<<endl;
    cout<<"********************Devices Turning ON********************\n"<<endl;

    L1.turnOn();
    F1.turnOn();
    AC1.turnOn();
    S1.turnOn();

    cout<<"\n=========================================================="<<endl;
    cout<<"********************Devices Turning ON********************\n"<<endl;

    L1.turnOff();
    F1.turnOff();
    AC1.turnOff();
    S1.turnOff();

    //Power Consumptions
    cout<<"\n======================================================================"<<endl;
    cout<<"********************Calculating Power Consumptions********************\n"<<endl;
    
    cout<<"Power Consumed By Light:"<<L1.calPower(5)<<" Watts"<<endl;
    cout<<"Power Consumed By FAN:"<<F1.calPower(5)<<" Watts"<<endl;
    cout<<"Power Consumed By AC:"<<AC1.calPower(5)<<" Watts"<<endl;
    cout<<"Power Consumed By Security Systems:\n"<<S1.calPower(5)<<" Watts"<<endl;
    //Attempting To Access Security Logs
    cout<<"\n====================================================================="<<endl;
    cout<<"********************Displaying Accessible Devices********************\n"<<endl;
    User1.viewAccessibleDevice();
    cout<<endl;
    User2.viewAccessibleDevice();
    
    cout<<"==========================================================================="<<endl;
    cout<<"********************Accessing Special Security Controls********************\n"<<endl;

    User1.accessSecurityLogs();
    cout<<endl;
    User2.accessSecurityLogs();
}