#include <iostream>
using namespace std;
void func(){
    cout<<"before main";
}
class abc{
        int a;
    public:
        abc(){func();};

};
abc b;
int main(){
    abc a;
    std::cout<<&a<<std::endl;
    return 0;
}