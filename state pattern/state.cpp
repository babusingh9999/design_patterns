#include <iostream>
#include <memory> // Include memory header for smart pointers

// Forward declaration of classes
class TrafficLight; // Forward declare TrafficLight class
class State; // Forward declare State class

// Abstract State class
class State {
public:
    virtual void change(TrafficLight *light) = 0; // Pure virtual function
    virtual ~State() {}
};

// TrafficLight class which uses State
class TrafficLight {
public:
    TrafficLight(); // Constructor declaration

    void setState(std::unique_ptr<State> newState) {
        currentState = std::move(newState); // Transfer ownership of the new state
    }

    void changeState() {
        currentState->change(this); // Delegate to the current state
    }

private:
    std::unique_ptr<State> currentState; // Smart pointer to manage state
};

// Definition of RedState class
class RedState : public State {
public:
    void change(TrafficLight *light) override {
        std::cout << "Changing from RED to GREEN. Cars can go.\n";
        light->setState(std::make_unique<GreenState>()); // Create new GreenState
    }
};

// Definition of GreenState class
class GreenState : public State {
public:
    void change(TrafficLight *light) override {
        std::cout << "Changing from GREEN to YELLOW. Cars can go.\n";
        light->setState(std::make_unique<YellowState>()); // Create new YellowState
    }
};

// Definition of YellowState class
class YellowState : public State {
public:
    void change(TrafficLight *light) override {
        std::cout << "Changing from YELLOW to RED. Cars can go.\n";
        light->setState(std::make_unique<RedState>()); // Create new RedState
    }
};

// Constructor definition for TrafficLight
TrafficLight::TrafficLight() {
    currentState = std::make_unique<RedState>(); // Start with RedState
}

int main() {
    TrafficLight light; // Create a TrafficLight object
    light.changeState(); // RED -> GREEN
    light.changeState(); // GREEN -> YELLOW
    light.changeState(); // YELLOW -> RED
    return 0;
}
