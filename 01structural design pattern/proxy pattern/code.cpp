
#include <iostream>
#include <string>
using namespace std;

// ============================================
// STEP 1: SUBJECT
// Common interface for Proxy and RealImage
// ============================================

class Image {
public:

    // Both classes must implement display()
    virtual void display() = 0;

    virtual ~Image() {}
};


// ============================================
// STEP 2: REAL SUBJECT
// Actual class responsible for loading image
// ============================================

class RealImage : public Image {
private:

    string fileName;

    // Simulate expensive image loading
    void loadFromDisk() {

        cout << "Loading image from disk: "
             << fileName << endl;
    }

public:

    // Constructor
    RealImage(string name) {

        fileName = name;

        // Image loads when RealImage is created
        loadFromDisk();
    }

    // Display actual image
    void display() override {

        cout << "Displaying image: "
             << fileName << endl;
    }
};


// ============================================
// STEP 3: PROXY
// Controls access to RealImage
// ============================================

class ProxyImage : public Image {
private:

    string fileName;

    // Pointer to actual image object
    RealImage* realImage;

public:

    // Constructor
    ProxyImage(string name) {

        fileName = name;

        // Initially, actual image is not created
        realImage = NULL;
    }

    // Control access to actual image
    void display() override {

        // Check whether image is already loaded
        if (realImage == NULL) {

            cout << "Proxy: Image not loaded yet."
                 << endl;

            // Create actual image only when required
            realImage = new RealImage(fileName);
        }

        // Forward request to actual image
        realImage->display();
    }

    // Destructor to release dynamically allocated memory
    ~ProxyImage() {

        delete realImage;
    }
};


// ============================================
// STEP 4: CLIENT
// ============================================

int main() {

    // Create proxy object
    Image* image = new ProxyImage("photo.jpg");

    cout << "Proxy object created." << endl;

    // First request
    cout << "\nFirst display request:" << endl;

    image->display();

    // Second request
    cout << "\nSecond display request:" << endl;

    image->display();

    // Release memory
    delete image;

    return 0;
}
