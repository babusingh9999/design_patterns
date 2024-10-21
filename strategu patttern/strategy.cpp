#include <iostream>

class GreetingStrategy{
    public:
        virtual void greet(const std::string & name)=0;
};
class FormalGreeting : public GreetingStrategy{
    public:
        void greet(const std::string & name){
            std::cout<<" Hello ! How do you do! "<<std::endl;
        }
};
class NormalGreeting : public GreetingStrategy{
    public:
        void greet(const std::string & name){
            std::cout<<" Hi, How are you do! "<<std::endl;
        }
};
class InformalGreeting : public GreetingStrategy{
    public:
        void greet(const std::string & name){
            std::cout<<" Hey ! whats up? "<<std::endl;
        }
};

class Person{
        GreetingStrategy *greetingStrategy;
    public:
        Person(GreetingStrategy *greetingStrategy) : greetingStrategy(greetingStrategy){};
        void greet(const std::string &name){
            greetingStrategy->greet(name);
        }
};


int main(int argc, const char * argv[]){
    Person businees(new FormalGreeting);
    businees.greet("Bob");
    return 0;
}