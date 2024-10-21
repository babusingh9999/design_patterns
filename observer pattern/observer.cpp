#include <iostream>
#include <vector>
#include <algorithm>
class Subscriber{
    public:
        virtual void notify(const std::string &publisherName , const std::string &message)=0;
        virtual std::string getName()=0;
};

class Publisher{
    public:
        virtual void subscribe(Subscriber *subscriber)=0;
        virtual void unsubscribe(Subscriber *subscriber)=0;
        virtual void publish(const std::string &message)=0;
};

class ChatGroup : public Publisher{
    public:
        ChatGroup(const std::string &name) : groupName(name){};
        void subscribe(Subscriber *subscriber) override{
            this->subscribers.push_back(subscriber);
        }
        void unsubscribe(Subscriber *subscriber) override{
            subscribers.erase
            (std::remove_if(subscribers.begin(),subscribers.end(),[subscriber](Subscriber *s) { return s->getName() == subscriber->getName();}),subscribers.end());
        }
        void publish(const std::string &message) override{
            for(auto subscriber: subscribers){
                subscriber->notify(groupName,message);
            }
        }
    private:
        std::string groupName;
        std::vector<Subscriber*> subscribers;
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
    ChatUser *user1 = new ChatUser("Alice");
    ChatUser *user2 = new ChatUser("Bob");
    ChatUser *user3 = new ChatUser("Charlie");

    ChatGroup *group1 = new ChatGroup("Chit-Chat group");
    ChatGroup *group2 = new ChatGroup("DOg-Lover group");

    group1->subscribe(user1);
    group1->subscribe(user2);

    group2->subscribe(user2);
    group2->subscribe(user3);

    group1->publish("Lets go for tea!");
    group2->publish("Today is international dog day everyone!");

    delete user1;
    delete user2;
    delete user3;

    delete group1;
    delete group2;
    return 0;
}