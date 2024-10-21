#include <iostream>

class Person{
    public:
        virtual void greet(const std::string & name)=0;
};
class BusinessPerson : public Person{
    public:
        void greet(const std::string & name){
            std::cout<<" Hello ! How do you do! "<<std::endl
        }
};
class NormalPerson : public Person{
    public:
        void greet(const std::string & name){
            std::cout<<" Hi, How are you do! "<<std::endl
        }
};
class CoolPerson : public Person{
    public:
        void greet(const std::string & name){
            std::cout<<" Hey ! whats up? "<<std::endl
        }
};
class PoliticianPerson : public Person{
    public:
        void greet(const std::string & name){
            std::cout<<" Hello ! How do you do! "<<std::endl
        }
};
int main(int argc, const char * argv[]){
    return 0;
}