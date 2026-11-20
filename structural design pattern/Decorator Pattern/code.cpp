
#include <iostream>
using namespace std;

// Step 1: Component Interface
class Coffee {

public:

    virtual string getDescription() = 0;

    virtual int getCost() = 0;

    virtual ~Coffee() {}
};


// Step 2: Concrete Component
// Basic coffee without any extra ingredients
class SimpleCoffee : public Coffee {

public:

    string getDescription() override {
        return "Simple Coffee";
    }

    int getCost() override {
        return 100;
    }
};


// Step 3: Base Decorator
// It wraps an existing Coffee object
class CoffeeDecorator : public Coffee {

protected:

    Coffee* coffee;

public:

    CoffeeDecorator(Coffee* c) {
        coffee = c;
    }

};


// Step 4: Milk Decorator
class MilkDecorator : public CoffeeDecorator {

public:

    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    string getDescription() override {
        return coffee->getDescription() + " + Milk";
    }

    int getCost() override {
        return coffee->getCost() + 20;
    }
};


// Step 5: Sugar Decorator
class SugarDecorator : public CoffeeDecorator {

public:

    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    string getDescription() override {
        return coffee->getDescription() + " + Sugar";
    }

    int getCost() override {
        return coffee->getCost() + 10;
    }
};


// Step 6: Chocolate Decorator
class ChocolateDecorator : public CoffeeDecorator {

public:

    ChocolateDecorator(Coffee* c) : CoffeeDecorator(c) {}

    string getDescription() override {
        return coffee->getDescription() + " + Chocolate";
    }

    int getCost() override {
        return coffee->getCost() + 30;
    }
};


// Step 7: Main Function
int main() {

    // Create simple coffee
    Coffee* coffee = new SimpleCoffee();

    // Add milk
    coffee = new MilkDecorator(coffee);

    // Add sugar
    coffee = new SugarDecorator(coffee);

    // Add chocolate
    coffee = new ChocolateDecorator(coffee);

    // Display final coffee details
    cout << "Coffee: " << coffee->getDescription() << endl;

    cout << "Total Cost: Rs. " << coffee->getCost() << endl;

    return 0;
}
