
#include <iostream>
#include <string>
using namespace std;

// STEP 1: Product Class
// This is the actual object we want to create.

class Computer {

public:

    int ram;
    int storage;
    string processor;
    bool graphicsCard;

    // Display final computer configuration
    void showDetails() {

        cout << "\n----- Computer Details -----" << endl;

        cout << "RAM: " << ram << " GB" << endl;

        cout << "Storage: " << storage << " GB" << endl;

        cout << "Processor: " << processor << endl;

        cout << "Graphics Card: "
             << (graphicsCard ? "Yes" : "No") << endl;
    }
};


// STEP 2: Builder Class
// Responsible for creating Computer objects step by step.

class ComputerBuilder {

private:

    // Computer object that we are constructing
    Computer computer;

public:

    // Constructor: Initialize default values
    ComputerBuilder() {

        computer.ram = 0;
        computer.storage = 0;
        computer.processor = "Not Selected";
        computer.graphicsCard = false;
    }

    // Set RAM
    ComputerBuilder& setRAM(int ram) {

        computer.ram = ram;

        // Return the same Builder object
        // This allows method chaining
        return *this;
    }

    // Set Storage
    ComputerBuilder& setStorage(int storage) {

        computer.storage = storage;

        return *this;
    }

    // Set Processor
    ComputerBuilder& setProcessor(string processor) {

        computer.processor = processor;

        return *this;
    }

    // Set Graphics Card
    ComputerBuilder& setGraphicsCard(bool value) {

        computer.graphicsCard = value;

        return *this;
    }

    // Build the final Computer object
    Computer build() {

        return computer;
    }
};


// STEP 3: Director Class
// Provides predefined configurations.

class Director {

public:

    // Create Gaming Computer
    Computer makeGamingPC(ComputerBuilder& builder) {

        return builder
                .setRAM(32)
                .setStorage(1000)
                .setProcessor("Intel i9")
                .setGraphicsCard(true)
                .build();
    }

    // Create Office Computer
    Computer makeOfficePC(ComputerBuilder& builder) {

        return builder
                .setRAM(8)
                .setStorage(256)
                .setProcessor("Intel i5")
                .setGraphicsCard(false)
                .build();
    }
};


// STEP 4: Client Code
// Main function uses Builder and Director.

int main() {

    // Create Builder object
    ComputerBuilder builder;

    // Create a Computer manually using Builder
    Computer gamingPC = builder
                        .setRAM(16)
                        .setStorage(512)
                        .setProcessor("Intel i7")
                        .setGraphicsCard(true)
                        .build();

    cout << "CUSTOM COMPUTER:";
    gamingPC.showDetails();


    // Create Director object
    Director director;

    // Create predefined Gaming PC
    Computer gaming = director.makeGamingPC(builder);

    cout << "\nGAMING COMPUTER:";
    gaming.showDetails();


    // Create predefined Office PC
    Computer office = director.makeOfficePC(builder);

    cout << "\nOFFICE COMPUTER:";
    office.showDetails();


    return 0;
}
