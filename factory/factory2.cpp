#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>


class Observer{
    public:
        virtual void notify(float temp) const=0;
        virtual std::string getDeviceName() = 0;
        virtual ~Observer(){};
};
class PhoneDisplay : public Observer{
    std::string name;
    public:
        PhoneDisplay(std::string name) : name(name){}
        void notify(float temp) const override{
            std::cout<<name<<" Display is notified that there is temprature change. current is "<<temp<<std::endl;
        }
        virtual std::string getDeviceName(){
            return name;
        }

};

class LaptopDisplay : public Observer{
    std::string name;
    public:
        LaptopDisplay(std::string name) : name(name){}
        void notify(float temp) const override{
            std::cout<<name<<" Display is notified that there is temprature change. current is "<<temp<<std::endl;
        }
        virtual std::string getDeviceName(){
            return name;
        }

};
class WatchDisplay : public Observer{
    std::string name;
    public:
        WatchDisplay(std::string name) : name(name){}
        void notify(float temp) const override{
            std::cout<<name<<" Display is notified that there is temprature change. current is "<<temp<<std::endl;
        }
        virtual std::string getDeviceName(){
            return name;
        }

};
class WeatherStation{
    float temprature;
    std::vector<Observer*> observes;
    public:
        void setTemprature(float newTemp){
            temprature = newTemp;
            notifyObservers();
        }
        void RegisterDevice(Observer *observer) {
            observes.push_back(observer);
            std::cout<<observer->getDeviceName()<<" device is registered successfully."<<std::endl;
        }
        void DeRegisterDevice(Observer *observer) {
            observes.erase(std::remove(observes.begin(),observes.end(),observer),observes.end());
            std::cout<<observer->getDeviceName()<<" device is removed successfully from the list."<<std::endl;
        }
        void notifyObservers(){
            for(const auto &elem : observes)
            {
                elem->notify(temprature);
            }
        }
};

int main(){
    WeatherStation weatherstation;
    PhoneDisplay phoneObject("PHONE");
    LaptopDisplay laptopObject("LAPTOP");
    WatchDisplay watchObject("SMART WATCH");
   
   weatherstation.RegisterDevice(&phoneObject);
    weatherstation.RegisterDevice(&laptopObject);


    weatherstation.setTemprature(22.6);

    weatherstation.DeRegisterDevice(&phoneObject);

   
    weatherstation.RegisterDevice(&watchObject);
    weatherstation.setTemprature(10.9);
    return 0;
}