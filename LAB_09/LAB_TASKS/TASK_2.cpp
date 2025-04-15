/*Problem: A homeowner wants to integrate smart lights and thermostats from different
brands into a single app. The system must provide a unified way to turn devices on/off,
adjust settings, and check statuses without requiring users to interact with brand-specific
interfaces. Future devices (e.g., smart locks) should integrate without altering the core
system.
Classes and Structure:
• Abstract Class SmartDevice:
o Member Functions:

▪ turnOn(): Pure virtual function to activate the device.
▪ turnOff(): Pure virtual function to deactivate the device.
▪ getStatus(): Pure virtual function to return the device’s current state.

• Derived Class LightBulb:
o Data Members:
▪ isOn (bool): Tracks if the light is on/off.
▪ brightness (int): Stores brightness level (0-100%).
o Implements turnOn(), turnOff(), and getStatus() for light control.
• Derived Class Thermostat:
o Data Members:
▪ isOn (bool): Tracks if the thermostat is active.
▪ temperature (double): Stores the current temperature setting.
o Implements turnOn(), turnOff(), and getStatus() for temperature control.

Flow:
• Create LightBulb and Thermostat objects.
• Turn devices on/off and display their statuses.*/

#include<iostream>
using namespace std;
class SmartDevices{
    private:

    public:
        virtual void turnOn()=0; // Pure virtual function to activate the device.
        virtual void turnOff()=0; // Pure virtual function to deactivate the device.
        virtual void getStatus()=0; // Pure virtual function to return the device’s current state.

};
class LightBulbs:public SmartDevices{
    private:
        bool ison;
        int brightness;
    public:
    LightBulbs(bool is,int b):ison(is),brightness(b){}
        void turnOn()override{
            ison =true;
        }
        void turnOff()override{
            ison =false;
        }
        void getStatus()override{
            cout<<"LIGHTS STATUS"<<endl;
            cout<<"Brightness -->"<<brightness<<endl;
            if(ison){
                cout<<"Light is ON"<<endl;
            }
            else cout<<"Light is OFF"<<endl;
        }
};
class Thermostat:public SmartDevices{
    private:
        bool ison;
        bool temperature;
    public:
        Thermostat(bool is,double b):ison(is),temperature(b){}
        void turnOn()override{
            ison =true;
        }
        void turnOff()override{
            ison =false;
        }
        void getStatus()override{
            cout<<"THERMOSTAT STATUS"<<endl;
            cout<<"Temperature -->"<<temperature<<endl;
            if(ison){
                cout<<"THERMOSTAT is ON"<<endl;
            }
            else cout<<"THERMOSTAT is OFF"<<endl;
        }
};
int main(){
    LightBulbs l1(false,100);
    Thermostat t1(false,100);
    l1.getStatus();
    t1.getStatus();
    l1.turnOn();
    t1.turnOn();
    l1.getStatus();
    t1.getStatus();
}