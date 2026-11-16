#include <iostream>
using namespace std;

class Singleton {

private:

    // Static instance
    static Singleton* instance;

    // Private constructor
    Singleton() {
        cout << "Singleton Object Created" << endl;
    }

public:

    // Public method to access object
    static Singleton* getInstance() {

        if (instance == nullptr) {
            instance = new Singleton();
        }

        return instance;
    }

};

// Initialize static instance
Singleton* Singleton::instance = nullptr;


int main() {

    Singleton* obj1 = Singleton::getInstance();

    Singleton* obj2 = Singleton::getInstance();

    if (obj1 == obj2) {
        cout << "Both objects are same" << endl;
    }

    return 0;
}