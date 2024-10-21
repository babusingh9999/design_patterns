#include<iostream>
#include <regex>
class StringValidator {
    public: 
        virtual ~StringValidator() {};
        virtual StringValidator* setNext(StringValidator *nextValidator) = 0;
        virtual std::string validate(std::string) = 0;
};

class BaseValidator: public StringValidator{
    private:
        StringValidator *next = nullptr;
    public:
        virtual ~BaseValidator() {delete next;};
        StringValidator* setNext(StringValidator *nextValidator) override{
            next = nextValidator;
            return nextValidator;
        }
        std::string validate(std::string testString) override{
            if(this->next){
                return this->next->validate(testString);
            }
            return "Success!";
        }
};

class NotEmptyValidator : public BaseValidator{
    public:
        NotEmptyValidator() {};
        std::string validate(std::string testString) override{
           std::cout<<"Checking Empty String !"<<std::endl; 
           if(testString.empty()){
                return "please enter valid string!";
           }
           return BaseValidator::validate(testString);
        }
};
class LengthValidator : public BaseValidator{
        int minLength;
    public:
        LengthValidator(int minLength) : minLength(minLength) {};
        std::string validate(std::string testString) override{
           std::cout<<"Checking Length of the String !"<<std::endl; 
           if(testString.length()<minLength){
                return " string " + testString+ " a string which is not longer than " + std::to_string(minLength);
           }
           return BaseValidator::validate(testString);
        }
};
class RegexValidator : public BaseValidator{
        std::string patternName;
        std::string regexString;
    public:
        RegexValidator( std::string patternName, std::string regexString) : 
        patternName(patternName), regexString(regexString) {};
        std::string validate(std::string testString) override{
           std::cout<<"Checking regex match !"<<std::endl; 
           if(!std::regex_match(testString, std::regex(regexString))){
                return "entered value does not match proper format for a pattern "+ patternName;
           }
           return BaseValidator::validate(testString);
        }
};
bool in_array(const std::string &value, const std::vector<std::string> &array){
    return std::find(array.begin(),array.end(),value) != array.end();
}

class HistoryValidator : public BaseValidator{
    private:
        std::vector<std::string> &historyItems;
    public:
        HistoryValidator(std::vector<std::string> &historyItems) : 
        historyItems(historyItems) {};
        std::string validate(std::string testString) override{
           std::cout<<"Checking if string has been used before !"<<std::endl; 
           if(in_array(testString,historyItems)){
                return "please enter new string which havn't entered before !";
           }
           historyItems.push_back(testString);
           return BaseValidator::validate(testString);
        }
};

int main(int argc, const char *argv[]){
    
    StringValidator *emailValidator = new BaseValidator;
    emailValidator->setNext(new NotEmptyValidator)->setNext(new RegexValidator("email address",
    "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"));

    std::cout<<"checking Email ...."<<std::endl;
    std::cout<<"Input : "<<std::endl;
    std::cout<<emailValidator->validate("")<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Input : shaun"<<std::endl;
    std::cout<<emailValidator->validate("shaun")<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"Input : shaun@test.com"<<std::endl;
    std::cout<<emailValidator->validate("shaun@test.com")<<std::endl;
    std::cout<<std::endl;
    
    delete emailValidator;

    StringValidator *passwordValidator = new BaseValidator;
    std::vector<std::string> vec;
    passwordValidator->setNext(new LengthValidator(8))
                     ->setNext(new HistoryValidator(vec));


    std::cout<<"checking Password ...."<<std::endl;
    std::cout<<"Input password : "<<std::endl;
    std::cout<<passwordValidator->validate("132332")<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Input : 1234567890"<<std::endl;
    std::cout<<passwordValidator->validate("1234567890")<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Input : 1234567890"<<std::endl;
    std::cout<<passwordValidator->validate("1234567890")<<std::endl;
    std::cout<<std::endl;

    delete passwordValidator;
    return 0;
}