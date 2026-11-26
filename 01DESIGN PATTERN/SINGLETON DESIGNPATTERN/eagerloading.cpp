#include <iostream>
using namespace std;

class Singleton {

private:

    // Private constructor
    Singleton() {
        cout << "Object Created" << endl;
    }

    // Object created immediately
    static Singleton instance;

public:

    static Singleton& getInstance() {
        return instance;
    }
};

// Initialize object before main()
Singleton Singleton::instance;

int main() {

    cout << "Main Started" << endl;

    Singleton& obj1 = Singleton::getInstance();

    Singleton& obj2 = Singleton::getInstance();

    return 0;
}