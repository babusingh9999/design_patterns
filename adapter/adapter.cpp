#include<iostream>
#include <memory>
class IndianSocket{
    public: 
        virtual void IndianCharge()=0;
};
class USASocket{
    public:
        void USACharge(){
            std::cout<<"USA CHarging in progress ..."<<std::endl;
        }
};
class SocketAdapter : public IndianSocket, public USASocket{
    public:
        void IndianCharge(){
            USACharge();
        }
};
int main(){
    std::unique_ptr<IndianSocket> socketadapter = std::make_unique<SocketAdapter>();

    socketadapter->IndianCharge();


    return 0;
}