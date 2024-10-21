#include<iostream>
class Item{};
class Bike : public Item{};
class Macbook : public Item{};
class Iphone11 : public Item{};
class Iphone12 : public Item{};
class Iphone13 : public Item{};
class Pen : public Item{};

class Factory{
    public:
        Item * getItem(std::string type){
            if(type == "Bike") return new Bike();
            if(type == "Macbook") return new Macbook();
            if(type == "Iphone11") return new Iphone11();
            if(type == "Iphone12") return new Iphone12();
            if(type == "Iphone13") return new Iphone13();
            if(type == "Pen") return new Pen();
            return nullptr;
        }
};

class Amazon{
    public:
        Amazon(){}
        Factory factory;
        Item * getItem(std::string type){
            return factory.getItem(type);
        }
};

int main(){
    Amazon amazon;
    Item *it = amazon.getItem("Pen");
    return 0;
}