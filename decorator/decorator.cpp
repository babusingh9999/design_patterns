#include <iostream>
#include <memory>
class Coffee{
    public:
        virtual ~Coffee() = default;
        virtual std::string descripotion() const=0;
        virtual double cost() const =0;
};

class SimpleCoffee : public Coffee{
    public:
        std::string descripotion() const override{
            return "Simple Coffee ";
        }
        virtual double cost() const override{
            return 5.0; // Basic cost of the coffee
        }
};

class CoffeeDecorator : public Coffee{ // Base decorator
    protected:
        std::unique_ptr<Coffee> coffee;
    public:
        CoffeeDecorator(std::unique_ptr<Coffee> c) : coffee(std::move(c)) {}
        std::string descripotion() const override{
            return coffee->descripotion(); // delecate the description to coffee object
        }
        virtual double cost() const override{
            return coffee->cost(); // delecate the cost to coffee object
        }
};


// Concrete decorator
class MilkDecorator : public CoffeeDecorator{
    public:
        MilkDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {} 
        std::string descripotion() const override{
            return coffee->descripotion() + " . Added milk"; // adding the description
        }
        virtual double cost() const override{
            return coffee->cost()+1.5; // added cost of the milk
        }
};
class SugerDecorator : public CoffeeDecorator{
    public:
        SugerDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {} 
        std::string descripotion() const override{
            return coffee->descripotion() + " . Added Suger in the coffee . "; // adding the description
        }
        virtual double cost() const override{
            return coffee->cost()+0.5; // added cost of the suger
        }
};
int main(){
    // Simple Coffee
    std::unique_ptr<Coffee> simplecoffee = std::make_unique<SimpleCoffee>();
    std::cout<<"This is the cost of simple coffee : "<<simplecoffee->cost()<<" and details "<<simplecoffee->descripotion()<<std::endl;

    // Adding milk to the coffee
    simplecoffee = std::make_unique<MilkDecorator>(std::move(simplecoffee));
    std::cout<<"After adding milk to the coffee : "<<simplecoffee->cost()<<" and details "<<simplecoffee->descripotion()<<std::endl;

    // Adding Suger to it
    simplecoffee = std::make_unique<SugerDecorator>(std::move(simplecoffee));
    std::cout<<"Added Sugar to the coffee : "<<simplecoffee->cost()<<" and details "<<simplecoffee->descripotion()<<std::endl;

    return 0;
}