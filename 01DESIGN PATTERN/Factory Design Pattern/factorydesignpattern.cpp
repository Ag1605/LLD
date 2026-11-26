
#include <iostream>
using namespace std;

// Step 1: Common interface
class Payment {

public:

    virtual void pay() = 0;

    virtual ~Payment() {}
};


// Step 2: UPI payment class
class UPI : public Payment {

public:

    void pay() override {
        cout << "Payment using UPI" << endl;
    }
};


// Credit Card payment class
class CreditCard : public Payment {

public:

    void pay() override {
        cout << "Payment using Credit Card" << endl;
    }
};


// PayPal payment class
class PayPal : public Payment {

public:

    void pay() override {
        cout << "Payment using PayPal" << endl;
    }
};


// Step 3: Factory class
class PaymentFactory {

public:

    static Payment* createPayment(string type) {

        if (type == "UPI") {
            return new UPI();
        }

        else if (type == "CARD") {
            return new CreditCard();
        }

        else if (type == "PAYPAL") {
            return new PayPal();
        }

        return nullptr;
    }
};


// Step 4: Main function
int main() {

    Payment* payment;

    payment = PaymentFactory::createPayment("UPI");

    if (payment != nullptr) {
        payment->pay();
    }

    delete payment;

    return 0;
}
