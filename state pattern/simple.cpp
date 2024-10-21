#include <iostream>

class TrafficLight{
    public:
        enum State {RED,GREEN,YELLOW};
        TrafficLight():currentState(RED){}
        void changeState(){
            if (currentState == RED) {
                currentState = GREEN;
                std::cout << "Changing from RED to GREEN. Cars can go.\n";
            } else if (currentState == GREEN) {
                currentState = YELLOW;
                std::cout << "Changing from GREEN to YELLOW. Prepare to stop.\n";
            } else if (currentState == YELLOW) {
                currentState = RED;
                std::cout << "Changing from YELLOW to RED. Stop!\n";
            }
        }
    private:
        State currentState;
};

int main(){
    TrafficLight light;
    light.changeState();
    light.changeState();
    light.changeState();
    return 0;
}