#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
class Command{
    public:
        virtual ~Command() {}
        virtual void execute() = 0;
};

class Subscriber{
    public:
        virtual void notify(const std::string &publisherName , const std::string &message)=0;
        virtual std::string getName()=0;
};

class Publisher{
    public:
        virtual void subscribe(std::shared_ptr<Subscriber> subscriber)=0;
        virtual void unsubscribe(std::shared_ptr<Subscriber> subscriber)=0;
        virtual void publish(const std::string &message)=0;
};

class SubscribeCommand : public Command{
    public:
        SubscribeCommand(std::shared_ptr<Publisher>  group, std::shared_ptr<Subscriber> user) :group(group),user(user){}
        void execute() override{
            group->subscribe(user);
        }
    private:
        std::shared_ptr<Publisher>  group;
       std::shared_ptr<Subscriber> user; 
};

class UnSubscribeCommand : public Command{
    public:
        UnSubscribeCommand(std::shared_ptr<Publisher> group, std::shared_ptr<Subscriber> user) :group(group),user(user){}
        void execute() override{
            group->unsubscribe(user);
        }
    private:
        std::shared_ptr<Publisher> group;
        std::shared_ptr<Subscriber> user; 
};

class PublishMessageCommand : public Command{
    public:
        PublishMessageCommand(std::shared_ptr<Publisher> group, const std::string &message) :group(group),message(message){}
        void execute() override{
            group->publish(message);
        }
    private:
        std::shared_ptr<Publisher> group;
        std::string message; 
};

class CommandManager{
    public:
        void execute_command(std::shared_ptr<Command> command){
            command->execute();
            CmdHistory.push_back(command);
        }
    private:
        std::vector<std::shared_ptr<Command>> CmdHistory;
};



class ChatGroup : public Publisher{
    public:
        ChatGroup(const std::string &name) : groupName(name){};
        void subscribe(std::shared_ptr<Subscriber> subscriber) override{
            this->subscribers.push_back(subscriber);
        }
        void unsubscribe(std::shared_ptr<Subscriber> subscriber) override{
            subscribers.erase
            (std::remove_if(subscribers.begin(),subscribers.end(),[subscriber](std::shared_ptr<Subscriber>s) { return s->getName() == subscriber->getName();}),subscribers.end());
        }
        void publish(const std::string &message) override{
            for(auto subscriber: subscribers){
                subscriber->notify(groupName,message);
            }
        }
    private:
        std::string groupName;
        std::vector<std::shared_ptr<Subscriber>> subscribers;
};

class ChatUser : public Subscriber{
    public:
        ChatUser(const std::string &userName) : userName(userName){};
        void notify(const std::string &publisherName , const std::string &message) override{
            std::cout<<userName<<" received a message from : "<<publisherName<<" - "<<message<<std::endl;
        }
        std::string getName() override{ return userName;}
    private:
        std::string userName;
};



int main(int argc, const char* argv[])
{
    auto user1 = std::make_shared<ChatUser>("Alice");
    auto user2 = std::make_shared<ChatUser>("Bob");
    auto user3 = std::make_shared<ChatUser>("Charlie");

    auto group1 = std::make_shared<ChatGroup>("Chit-Chat group");
    auto group2 = std::make_shared<ChatGroup>("DOg-Lover group");


    CommandManager cmdManager;   

    auto subscribeCmd1 = std::make_shared<SubscribeCommand>(group1,user1);
    auto subscribeCmd2 = std::make_shared<SubscribeCommand>(group1,user2);
    auto subscribeCmd3 = std::make_shared<SubscribeCommand>(group2,user2);
    auto subscribeCmd4 = std::make_shared<SubscribeCommand>(group2,user3);

    cmdManager.execute_command(subscribeCmd1);
    cmdManager.execute_command(subscribeCmd2);
    cmdManager.execute_command(subscribeCmd3);
    cmdManager.execute_command(subscribeCmd4);


    auto publishMessage1 = std::make_shared<PublishMessageCommand>(group1,"Lets go for tea!");
    auto publishMessage2 = std::make_shared<PublishMessageCommand>(group2,"Today is international dog day everyone!");

    cmdManager.execute_command(publishMessage1);
    cmdManager.execute_command(publishMessage2);

    
    return 0;
}