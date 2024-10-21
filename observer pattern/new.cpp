#include<iostream>
#include <vector>
class Observer{
    public:
        ~Observer(){};
        virtual void notify() const = 0;
};
class Admin : public Observer{
    public:
        void notify() const override{
            std::cout<<"There is change in position admin do something!"<<std::endl;
        }
};
class User : public Observer{
    public:
        void notify() const override{
            std::cout<<"There is change in position user. now you can do something!"<<std::endl;
        }
};
class Subject{
    private:
        int position;
        std::vector<const Observer*> ObserverCollection;
    public:
        void setPosition(int newPosition){
            position = newPosition;
            NotifyObserver();
        }
        void RegisterObserver(const Observer *obj){
            ObserverCollection.push_back(obj);
        }
         void UnregisterObserver(const Observer *obj){
            //while(ObserverCollection)
            //ObserverCollection.pop_back(obj);
        }
        void NotifyObserver(){
            for(auto &obj: ObserverCollection){
                obj->notify();
            }
        }
};
int main(int argc, const char*argv[]){
    Admin admin;
    User user;
    Subject sub;
    sub.RegisterObserver(&admin);
    sub.RegisterObserver(&user);

    sub.setPosition(10);


    return 0;
}