#include<iostream>
#include <memory>
// Interface
class PaymentGateway{
    public:
        virtual void processPayment(int amount) const=0;
        virtual ~PaymentGateway()=default;
};

// Concrete Impl
class PaypelGateway : public PaymentGateway{
    public:
        void processPayment(int amount) const override {
            std::cout<<"Processing paypel Payment..."<<amount<<std::endl;
        }
};
class StripeGateway : public PaymentGateway{
    public:
        void processPayment(int amount) const override {
            std::cout<<"Processing Stripe Payment..."<<amount<<std::endl;
        }
};
class PaymentMethods{
    protected:
        std::shared_ptr<PaymentGateway> pg;
    public:
        PaymentMethods(std::shared_ptr<PaymentGateway> pg) : pg(pg){}
        virtual ~PaymentMethods()=default;
        virtual void makePayment(int amount) const=0;
};
class CreditCardMethod : public PaymentMethods{
    public:
        CreditCardMethod(std::shared_ptr<PaymentGateway> pg) : PaymentMethods(pg){}
        void makePayment(int amount) const override{
            std::cout<<"Paying by credit card..."<<std::endl;
            pg->processPayment(amount);
        }
};
class BankTranferMethod : public PaymentMethods{
    public:
    BankTranferMethod(std::shared_ptr<PaymentGateway> pg) : PaymentMethods(pg){}
     void makePayment(int amount) const override{
            std::cout<<"Paying by Bank Transfer ..."<<std::endl;
            pg->processPayment(amount);
        }
};
int main(){
    std::shared_ptr<PaymentGateway> paypel = std::make_shared<PaypelGateway>();
    std::shared_ptr<PaymentGateway> stripe = std::make_shared<StripeGateway>();

    // using credit card with different gateways
    CreditCardMethod creditcardpaypel(paypel);
    CreditCardMethod creditcardstripe(stripe);

    // pay 
    creditcardpaypel.makePayment(100);
    creditcardstripe.makePayment(200);

    // using Bank transfer with different gateways
    BankTranferMethod banktranferpaypel(paypel);
    BankTranferMethod banktranferstripe(stripe);

    // pay
    banktranferpaypel.makePayment(300);
    banktranferpaypel.makePayment(400);

    return 0;
}