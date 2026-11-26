
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// ============================================
// STEP 1: COMPONENT
// Common interface for File and Folder
// ============================================

class FileSystem {
public:

    // Every child class must implement this method
    virtual void showDetails() = 0;

    // Virtual destructor for proper cleanup
    virtual ~FileSystem() {}
};


// ============================================
// STEP 2: LEAF
// File is an individual object
// It cannot contain other objects
// ============================================

class File : public FileSystem {
private:

    string fileName;

public:

    // Constructor
    File(string name) {
        fileName = name;
    }

    // Implement common interface
    void showDetails() override {

        cout << "File: " << fileName << endl;
    }
};


// ============================================
// STEP 3: COMPOSITE
// Folder can contain files and other folders
// ============================================

class Folder : public FileSystem {
private:

    string folderName;

    // Store both File and Folder objects
    // using the common FileSystem interface
    vector<shared_ptr<FileSystem>> children;

public:

    // Constructor
    Folder(string name) {
        folderName = name;
    }

    // Add a file or another folder
    void add(shared_ptr<FileSystem> item) {

        children.push_back(item);
    }

    // Display folder and its complete contents
    void showDetails() override {

        cout << "Folder: " << folderName << endl;

        // Traverse all child objects
        for (int i = 0; i < children.size(); i++) {

            // Polymorphism:
            // Calls File's or Folder's showDetails()
            children[i]->showDetails();
        }
    }
};


// ============================================
// STEP 4: CLIENT
// ============================================

int main() {

    // Create individual files (Leaf objects)
    shared_ptr<FileSystem> resume =
        make_shared<File>("Resume.pdf");

    shared_ptr<FileSystem> notes =
        make_shared<File>("Notes.txt");

    shared_ptr<FileSystem> photo =
        make_shared<File>("Photo.jpg");


    // Create folders (Composite objects)
    shared_ptr<Folder> documents =
        make_shared<Folder>("Documents");

    shared_ptr<Folder> photos =
        make_shared<Folder>("Photos");

    shared_ptr<Folder> root =
        make_shared<Folder>("Root");


    // Add files inside Documents folder
    documents->add(resume);
    documents->add(notes);


    // Add file inside Photos folder
    photos->add(photo);


    // Add folders inside Root folder
    root->add(documents);
    root->add(photos);


    // Display complete file system
    cout << "File System Structure:" << endl;

    root->showDetails();

    return 0;
}
