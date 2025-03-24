#include <iostream>
using namespace std;

class Device{
    private:
        string DeviceId;
        string DeviceType;
        double PowerRating;
        bool Status;
    public: 
        Device(string id,string type,double pr,bool s):DeviceId(id),DeviceType(type),PowerRating(pr),Status(s){}
        void TurnOff(){
            Status=false;
        }
        void TurnOn(){
            Status=true;
        } 

        double Calculate(int hours) override{
            return 
        }
};
class Lights{};
class Fanse{};
class ACs{};


class User{
    private:
        string UserId;
        string UserRole;
        int AccessLevel;
    public: 
        void viewAccessibleDevices(){}


};






int main(){


}