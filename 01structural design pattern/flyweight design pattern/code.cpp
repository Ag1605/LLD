
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
using namespace std;

// ============================================
// STEP 1: FLYWEIGHT
// Common interface for all tree types
// ============================================

class Tree {
public:

    // x and y are unique information
    virtual void display(int x, int y) = 0;

    virtual ~Tree() {}
};


// ============================================
// STEP 2: CONCRETE FLYWEIGHT
// Stores shared information (Intrinsic State)
// ============================================

class TreeType : public Tree {
private:

    // Intrinsic State: shared information
    string name;
    string color;
    string texture;

public:

    // Constructor
    TreeType(string n, string c, string t) {

        name = n;
        color = c;
        texture = t;
    }

    // Display tree using shared and unique data
    void display(int x, int y) override {

        cout << "Tree Type: " << name << endl;

        cout << "Color: " << color << endl;

        cout << "Texture: " << texture << endl;

        cout << "Position: (" << x << ", " << y << ")"
             << endl;

        cout << "------------------------" << endl;
    }
};


// ============================================
// STEP 3: FLYWEIGHT FACTORY
// Creates and reuses shared TreeType objects
// ============================================

class TreeFactory {
private:

    // Store one shared object for each tree type
    unordered_map<string, shared_ptr<TreeType>> treeTypes;

public:

    shared_ptr<TreeType> getTreeType(
        string name,
        string color,
        string texture
    ) {

        // Check whether this tree type already exists
        if (treeTypes.find(name) != treeTypes.end()) {

            cout << "Reusing existing tree: "
                 << name << endl;

            return treeTypes[name];
        }

        // Create a new tree type if it doesn't exist
        cout << "Creating new tree: " << name << endl;

        shared_ptr<TreeType> newTree =
            make_shared<TreeType>(name, color, texture);

        // Store the shared object in the factory
        treeTypes[name] = newTree;

        return newTree;
    }

    // Count how many shared tree types exist
    int getTreeTypeCount() {

        return treeTypes.size();
    }
};


// ============================================
// STEP 4: CLIENT-SIDE TREE
// Stores unique information (Extrinsic State)
// ============================================

class GameTree {
private:

    // Shared TreeType object
    shared_ptr<TreeType> treeType;

    // Unique information for each tree
    int x;
    int y;

public:

    GameTree(
        shared_ptr<TreeType> type,
        int posX,
        int posY
    ) {

        treeType = type;

        x = posX;
        y = posY;
    }

    void display() {

        treeType->display(x, y);
    }
};


// ============================================
// STEP 5: CLIENT
// ============================================

int main() {

    // Create factory
    TreeFactory factory;

    // Store individual trees
    vector<GameTree> forest;


    // Request Oak tree type
    shared_ptr<TreeType> oak =
        factory.getTreeType(
            "Oak",
            "Green",
            "Oak_Texture"
        );

    // Request Pine tree type
    shared_ptr<TreeType> pine =
        factory.getTreeType(
            "Pine",
            "Dark Green",
            "Pine_Texture"
        );

    // Request Oak again
    // Factory will reuse the existing Oak object
    shared_ptr<TreeType> oakAgain =
        factory.getTreeType(
            "Oak",
            "Green",
            "Oak_Texture"
        );


    // Create trees with different positions
    forest.push_back(GameTree(oak, 10, 20));

    forest.push_back(GameTree(pine, 30, 40));

    forest.push_back(GameTree(oakAgain, 50, 60));


    cout << "\nDisplaying Forest:\n";

    // Display all trees
    for (int i = 0; i < forest.size(); i++) {

        forest[i].display();
    }


    // Total shared tree types
    cout << "Total shared tree types: "
         << factory.getTreeTypeCount() << endl;

    cout << "Total tree objects: "
         << forest.size() << endl;

    return 0;
}
