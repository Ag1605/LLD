#include <iostream>
using namespace std;

class Singleton {

private:

    Singleton() {
        cout << "Object Created" << endl;
    }

public:

    static Singleton& getInstance() {

        // Created only on first call
        static Singleton instance;

        return instance;
    }
};

int main() {

    cout << "Main Started" << endl;

    Singleton& obj1 = Singleton::getInstance();

    Singleton& obj2 = Singleton::getInstance();

    return 0;
}