#include <iostream>
#include <vector>
#include <string>

class user;

class mediator{
    public:
        virtual void sendMessage(const std::string &message, user &sender) = 0;
};

class user{
    public:
        user(const std::string &name, mediator &mediator) : name(name),mediator_name(mediator){}

        void sendMessage(const std::string &message){
            std::cout<<name<<" sends: "<<message<<std::endl;
            mediator_name.sendMessage(message,*this);

        }
        void receiveMessage(const std::string &message, const user &sender){
            std::cout<<name<<" received "<<message<<" from"<<sender.get_name()<<std::endl;
        }

        std::string get_name() const{
            return name;
        }
    private:
        const std::string name;
        mediator &mediator_name;
};


class chatMediator: public mediator{
    public:
        void add_user(user *user_name){
            users.push_back(user_name);
        }
        void sendMessage(const std::string &message, user &sender){
            for(user* user_name:users){
                if(user_name!=&sender)
                {
                    user_name->receiveMessage(message,sender);
                }
            }
        }
    private:
        std::vector<user*> users;
};




int main(int argc, const char *argv[]){
    chatMediator mediator;
    user alice("alice",mediator);
    user bob("bob",mediator);
    user charlie("charlie",mediator);

    mediator.add_user(&alice);
    mediator.add_user(&bob);
    mediator.add_user(&charlie);

    alice.sendMessage("Hi everyone !");
    bob.sendMessage("Hi Alice");
    charlie.sendMessage("Hello All ");
    return 0;
}