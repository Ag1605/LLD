
#include <iostream>
using namespace std;

// ============================================
// STEP 1: IMPLEMENTATION
// Common interface for all devices
// ============================================

class Device {
public:

    virtual void turnOn() = 0;

    virtual void turnOff() = 0;

    virtual void setVolume(int volume) = 0;

    virtual ~Device() {}
};


// ============================================
// STEP 2: CONCRETE IMPLEMENTATION
// TV is one implementation of Device
// ============================================

class TV : public Device {
public:

    void turnOn() override {
        cout << "TV is turned ON" << endl;
    }

    void turnOff() override {
        cout << "TV is turned OFF" << endl;
    }

    void setVolume(int volume) override {
        cout << "TV volume set to " << volume << endl;
    }
};


// ============================================
// RADIO is another implementation of Device
// ============================================

class Radio : public Device {
public:

    void turnOn() override {
        cout << "Radio is turned ON" << endl;
    }

    void turnOff() override {
        cout << "Radio is turned OFF" << endl;
    }

    void setVolume(int volume) override {
        cout << "Radio volume set to " << volume << endl;
    }
};


// ============================================
// STEP 3: ABSTRACTION
// Remote is the base abstraction
// It holds a reference to Device
// ============================================

class Remote {
protected:

    // Bridge between Remote and Device
    Device* device;

public:

    // Constructor receives any device
    Remote(Device* d) {
        device = d;
    }

    virtual void powerOn() = 0;

    virtual void powerOff() = 0;

    virtual ~Remote() {}
};


// ============================================
// STEP 4: REFINED ABSTRACTION
// BasicRemote provides basic functionality
// ============================================

class BasicRemote : public Remote {
public:

    BasicRemote(Device* d) : Remote(d) {}

    void powerOn() override {

        cout << "Basic Remote: ";

        device->turnOn();
    }

    void powerOff() override {

        cout << "Basic Remote: ";

        device->turnOff();
    }
};


// ============================================
// AdvancedRemote provides extra functionality
// ============================================

class AdvancedRemote : public Remote {
public:

    AdvancedRemote(Device* d) : Remote(d) {}

    void powerOn() override {

        cout << "Advanced Remote: ";

        device->turnOn();
    }

    void powerOff() override {

        cout << "Advanced Remote: ";

        device->turnOff();
    }

    // Extra functionality
    void increaseVolume() {

        cout << "Advanced Remote: ";

        device->setVolume(50);
    }
};


// ============================================
// STEP 5: CLIENT
// ============================================

int main() {

    // Create devices
    TV tv;
    Radio radio;


    // Basic Remote controlling TV
    cout << "Basic Remote + TV" << endl;

    BasicRemote basicTV(&tv);

    basicTV.powerOn();
    basicTV.powerOff();


    cout << endl;


    // Advanced Remote controlling TV
    cout << "Advanced Remote + TV" << endl;

    AdvancedRemote advancedTV(&tv);

    advancedTV.powerOn();
    advancedTV.increaseVolume();
    advancedTV.powerOff();


    cout << endl;


    // Basic Remote controlling Radio
    cout << "Basic Remote + Radio" << endl;

    BasicRemote basicRadio(&radio);

    basicRadio.powerOn();
    basicRadio.powerOff();


    cout << endl;


    // Advanced Remote controlling Radio
    cout << "Advanced Remote + Radio" << endl;

    AdvancedRemote advancedRadio(&radio);

    advancedRadio.powerOn();
    advancedRadio.increaseVolume();
    advancedRadio.powerOff();


    return 0;
}
