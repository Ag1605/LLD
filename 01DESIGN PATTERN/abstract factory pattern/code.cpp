
#include <iostream>
using namespace std;


// ==========================================
// STEP 1: ABSTRACT PRODUCTS
// ==========================================

// Abstract Button
class Button {

public:

    // Pure virtual function
    virtual void click() = 0;

    // Virtual destructor
    virtual ~Button() {}
};


// Abstract Checkbox
class Checkbox {

public:

    // Pure virtual function
    virtual void check() = 0;

    // Virtual destructor
    virtual ~Checkbox() {}
};


// ==========================================
// STEP 2: CONCRETE PRODUCTS
// ==========================================

// Windows Button
class WindowsButton : public Button {

public:

    void click() override {

        cout << "Windows Button Clicked" << endl;
    }
};


// Mac Button
class MacButton : public Button {

public:

    void click() override {

        cout << "Mac Button Clicked" << endl;
    }
};


// Windows Checkbox
class WindowsCheckbox : public Checkbox {

public:

    void check() override {

        cout << "Windows Checkbox Checked" << endl;
    }
};


// Mac Checkbox
class MacCheckbox : public Checkbox {

public:

    void check() override {

        cout << "Mac Checkbox Checked" << endl;
    }
};


// ==========================================
// STEP 3: ABSTRACT FACTORY
// ==========================================

// Common interface for creating UI families
class GUIFactory {

public:

    // Create Button
    virtual Button* createButton() = 0;

    // Create Checkbox
    virtual Checkbox* createCheckbox() = 0;

    // Virtual destructor
    virtual ~GUIFactory() {}
};


// ==========================================
// STEP 4: CONCRETE FACTORIES
// ==========================================

// Windows Factory
class WindowsFactory : public GUIFactory {

public:

    Button* createButton() override {

        return new WindowsButton();
    }

    Checkbox* createCheckbox() override {

        return new WindowsCheckbox();
    }
};


// Mac Factory
class MacFactory : public GUIFactory {

public:

    Button* createButton() override {

        return new MacButton();
    }

    Checkbox* createCheckbox() override {

        return new MacCheckbox();
    }
};


// ==========================================
// STEP 5: CLIENT CLASS
// ==========================================

class Application {

private:

    Button* button;
    Checkbox* checkbox;

public:

    // Constructor receives Abstract Factory
    Application(GUIFactory* factory) {

        button = factory->createButton();

        checkbox = factory->createCheckbox();
    }

    // Use the created objects
    void render() {

        button->click();

        checkbox->check();
    }

    // Destructor to release memory
    ~Application() {

        delete button;

        delete checkbox;
    }
};


// ==========================================
// STEP 6: MAIN FUNCTION
// ==========================================

int main() {

    GUIFactory* factory = nullptr;

    int choice;

    cout << "Select Operating System:" << endl;

    cout << "1. Windows" << endl;

    cout << "2. Mac" << endl;

    cout << "Enter your choice: ";

    cin >> choice;


    // Select Concrete Factory
    if (choice == 1) {

        factory = new WindowsFactory();
    }

    else if (choice == 2) {

        factory = new MacFactory();
    }

    else {

        cout << "Invalid Choice!" << endl;

        return 0;
    }


    // Pass selected factory to Application
    Application app(factory);

    // Create and use UI components
    app.render();


    // Release factory memory
    delete factory;

    return 0;
}
