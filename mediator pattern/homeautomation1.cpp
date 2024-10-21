#include <iostream>


class Light{
    public:
        void turnOn(){
            std::cout<<"Turning On the lights... "<<std::endl;
        }
};

class Thermostat{
    public:
        void setTemprature(int temp){
            if(temp>75){
                std::cout<<"Temprature is high ! activating sprinklers... "<<std::endl;
                sprinklers.activate();
            }
        }
    private:
        class Sprinklers{
            public:
                void activate(){
                    std::cout<<"sprinklers is activated... "<<std::endl;
                }
        }sprinklers;

};


class HomeAutomation{
    public:
        void simulateEvents(){
            light.turnOn();
            thermostat.setTemprature(60);
        }
    private:
        Light light;
        Thermostat thermostat;
};

int main(int argc, const char *argv[]){
    HomeAutomation ha;
    ha.simulateEvents();


    return 0;
}