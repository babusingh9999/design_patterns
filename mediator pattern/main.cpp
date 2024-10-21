#include <iostream>
#include <string>

class user{
    public:
        user(const std::string &name) : name(name){}

        void sendMessage(const std::string &message, user &receiver){
            std::cout<<name<<" sends: "<<message<<" to"<<receiver.name<<std::endl;
            receiver.receiveMessage(message,*this);

        }
        void receiveMessage(const std::string &message, const user &sender){
            std::cout<<name<<" received "<<message<<" from"<<sender.name<<std::endl;
        }

    private:
        const std::string name;
};

int main(int argc, const char *argv[]){
    user alice("alice");
    user bob("bob");

    alice.sendMessage("Hi Bob",bob);
    bob.sendMessage("Hi Alice",alice);
    return 0;
}