#include <iostream>
class GreetingCardTemplate{
    protected:
        virtual std::string intro(const std::string &to){
            return "Dear " + to + "\n";
        }
        virtual std::string occasion(){
            return " Just writing to say Hi ! Hope all well with you !\n";
        }
        virtual std::string closing(const std::string &from){
            return "Sincerely, \n " + from + "\n";
        }
    public:
        std::string generate(const std::string &to, const std::string &from){
            return intro(to) + occasion() + closing(from);
        } 
};

class BirthdayCardTemplate : public GreetingCardTemplate{
    protected:
        std::string occasion() override{
            return " Happy Birthday ! see you at gym tomorrow !\n";
        }
};

class NewyearsCardTemplate : public GreetingCardTemplate{
    protected:
        std::string intro(const std::string &to) override{
            return to + "!!!!!!!\n";
        }
        std::string occasion() override{
            return " Happy new Year !\n";
        }
};
int main(){
    GreetingCardTemplate gct;
    BirthdayCardTemplate bct;
    NewyearsCardTemplate nct;
    std::cout<<gct.generate("Alice","Bob")<<std::endl;
    std::cout<<bct.generate("Bob","Charlie")<<std::endl;
    std::cout<<nct.generate("Charlie","Alice")<<std::endl;
    return 0;
}