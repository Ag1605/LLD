
#include <iostream>
using namespace std;

// Step 1: Target Interface
// Our application expects this interface
class Payment {

public:

    virtual void makePayment() = 0;

    virtual ~Payment() {}
};


// Step 2: Adaptee
// Existing class with a different method name
class OldPaymentSystem {

public:

    void payAmount() {

        cout << "Payment completed using Old Payment System" << endl;

    }
};


// Step 3: Adapter
// Connects Payment interface with OldPaymentSystem
class PaymentAdapter : public Payment {

private:

    // Object of existing class
    OldPaymentSystem* oldPayment;

public:

    // Constructor receives old payment object
    PaymentAdapter(OldPaymentSystem* obj) {

        oldPayment = obj;

    }

    // Implement the expected interface
    void makePayment() override {

        // Convert new method call into old method call
        oldPayment->payAmount();

    }
};


// Step 4: Main Function
int main() {

    // Create old payment system object
    OldPaymentSystem oldSystem;

    // Create adapter and pass old system object
    Payment* payment = new PaymentAdapter(&oldSystem);

    // Client calls the expected method
    payment->makePayment();

    delete payment;

    return 0;
}
