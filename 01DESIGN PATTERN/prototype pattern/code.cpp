
#include <iostream>
#include <string>
using namespace std;


// ==========================================
// STEP 1: PROTOTYPE (ABSTRACT CLASS)
// ==========================================

class GameCharacter {

public:

    int health;
    int speed;
    int damage;

    // Constructor
    GameCharacter(int h, int s, int d) {

        health = h;
        speed = s;
        damage = d;
    }

    // Pure virtual clone function
    virtual GameCharacter* clone() const = 0;

    // Display character details
    virtual void showDetails() const {

        cout << "Health: " << health << endl;
        cout << "Speed: " << speed << endl;
        cout << "Damage: " << damage << endl;
    }

    // Virtual destructor
    virtual ~GameCharacter() {}
};


// ==========================================
// STEP 2: CONCRETE PROTOTYPE - WARRIOR
// ==========================================

class Warrior : public GameCharacter {

public:

    string weapon;

    // Constructor
    Warrior(int h, int s, int d, string w)
        : GameCharacter(h, s, d) {

        weapon = w;
    }

    // Clone function
    GameCharacter* clone() const override {

        // Create a copy of the current Warrior
        return new Warrior(*this);
    }

    void showDetails() const override {

        cout << "\n--- Warrior Details ---" << endl;

        GameCharacter::showDetails();

        cout << "Weapon: " << weapon << endl;
    }
};


// ==========================================
// STEP 3: CONCRETE PROTOTYPE - ZOMBIE
// ==========================================

class Zombie : public GameCharacter {

public:

    string type;

    // Constructor
    Zombie(int h, int s, int d, string t)
        : GameCharacter(h, s, d) {

        type = t;
    }

    // Clone function
    GameCharacter* clone() const override {

        // Create a copy of the current Zombie
        return new Zombie(*this);
    }

    void showDetails() const override {

        cout << "\n--- Zombie Details ---" << endl;

        GameCharacter::showDetails();

        cout << "Type: " << type << endl;
    }
};


// ==========================================
// STEP 4: CLIENT CODE
// ==========================================

int main() {

    // Create original Warrior object
    Warrior originalWarrior(100, 20, 50, "Sword");

    cout << "ORIGINAL WARRIOR:";
    originalWarrior.showDetails();


    // Clone the original Warrior
    GameCharacter* warriorClone = originalWarrior.clone();

    cout << "\nCLONED WARRIOR:";
    warriorClone->showDetails();


    // Modify cloned Warrior
    warriorClone->health = 200;

    cout << "\nAFTER MODIFYING CLONE:";

    cout << "\nOriginal Warrior Health: "
         << originalWarrior.health << endl;

    cout << "Cloned Warrior Health: "
         << warriorClone->health << endl;


    // Create original Zombie
    Zombie originalZombie(150, 10, 30, "Normal Zombie");

    cout << "\nORIGINAL ZOMBIE:";
    originalZombie.showDetails();


    // Clone the Zombie
    GameCharacter* zombieClone = originalZombie.clone();

    cout << "\nCLONED ZOMBIE:";
    zombieClone->showDetails();


    // Release dynamically allocated objects
    delete warriorClone;
    delete zombieClone;

    return 0;
}

