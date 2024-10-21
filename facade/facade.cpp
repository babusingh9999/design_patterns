#include <iostream>

// subsystem 1 : Lightning
class Lightning{
    public:
        void TurnOnLightning(){
            std::cout<<"turning on the lightning..."<<std::endl;
        }
         void TurnOffLightning(){
            std::cout<<"turning off the lightning..."<<std::endl;
        }
};
// subsystem 2 : security
class Security{
    public:
        void activateSecurity(){
            std::cout<<"activating the securty system in house..."<<std::endl;
        }
         void deactivateSecurity(){
            std::cout<<"deactivating the securty system..."<<std::endl;
        }
};
// subsystem 3 : temprature control
class TempratureControl{
    public:
        void setTemp(int temp){
            std::cout<<"temprature set to "<<temp<<std::endl;
        }
};

class HomeAutomationFacede{
    private:
        Lightning light;
        Security security;
        TempratureControl tempcontrol;
    public:
        void turnOnHouse(){
            light.TurnOnLightning();
            security.activateSecurity();
            tempcontrol.setTemp(20);
            std::cout<<"All set ."<<std::endl;
        }
        void turnOffHouse(){
            light.TurnOffLightning();
            security.deactivateSecurity();
            tempcontrol.setTemp(10);
            std::cout<<"All reset ."<<std::endl;
        }
};
int main(){
    HomeAutomationFacede homeautomation;
    // when arriving home
    homeautomation.turnOnHouse();
    std::cout<<" --------------- "<<std::endl;
    homeautomation.turnOffHouse();
    return 0;
}