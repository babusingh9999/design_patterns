#include <iostream>
#include <algorithm>
#include <vector>
#include <variant>
#include <execution>
using namespace std;
// using function object - functor
class MyClass{
    int x;
    int y;
    public:
        MyClass(int x,int y): x(x),y(y) {}
        std::size_t operator ()(){
            return x xor y;
        }
};
void fun(int a){
    std::cout<<"int"<<a<<std::endl;
}
void fun(string a){
    std::cout<<"string"<<a<<std::endl;
}
int main()
{
    std::vector<int> vec = {5,4,6,7,2,1};
    std::sort(vec.begin(),vec.end(),std::greater<int>());
    for(auto elem:vec){
        std::cout<<elem<<std::endl;
    }
    std::hash<string> stringHash;
    std::cout<<stringHash("Assignment description You will play a central role and often lead cross-discipline technical investigations by collecting information and drawing conclusions together with members from the different design teams. You are also responsible for the system documentation, both internally and externally.")<<std::endl;
    MyClass classObj(2,3);
    std::cout<<classObj()<<std::endl;
    std::vector<std::variant<int,string>> obj = {5,"Food"}; 
    for(auto &element:obj){
        visit([](auto &&args){fun(args);},element);
    }
    return 0;
}

// comments
// Feedback