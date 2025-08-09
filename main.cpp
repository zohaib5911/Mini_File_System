#include <iostream>
#include <string>
#include "Node.h"
#include "file.h"
#include "DirectoryNode.h"

using namespace std;

int main() {
    DirectoryNode* root = new DirectoryNode("Root",nullptr);
    int choice;

    while (true) {
        cout << "\n===== File System Menu =====\n";
        cout << "1. Create Directory\n";
        cout << "2. Create File\n";
        cout << "3. Add Content to File\n";
        cout << "4. Display Structure\n";
        cout << "5. Search by Name\n";
        cout << "6. Rename Node\n";
        cout << "7. Delete Node\n";
        cout << "8. Copy Node\n";
        cout << "9. Move Node\n";
        cout << "10. Get Full Path\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        if (choice == 0) break;

        string name, parentName, content, newName, srcName, destName;
        Node* foundNode = nullptr;

        switch (choice) {
        case 1:
            cout << "Enter directory name: ";
            getline(cin, name);
            cout << "Enter parent directory name (or Root): ";
            getline(cin, parentName);
                
            // Special case: If parent is "Root", directly assign root
            if (parentName == "Root") {
                foundNode = root;
            } else {
                foundNode = root->findByName(parentName);
            }
        
            if (foundNode && foundNode->isDirectory()) {
                DirectoryNode* parentDir = dynamic_cast<DirectoryNode*>(foundNode);
                if (!parentDir->isValidChild(name)) { // prevent duplicates
                    DirectoryNode* newDir = new DirectoryNode(name, parentDir);
                    parentDir->addChild(name, newDir);
                    cout << "Directory created under " << parentDir->getName() << ".\n";
                } else {
                    cout << "Directory with this name already exists.\n";
                }
            } else {
                cout << "Parent directory not found. Directory not created.\n";
            }
            break;


        case 2:
            cout << "Enter file name: ";
            getline(cin, name);
            cout << "Enter parent directory name: ";
            getline(cin, parentName);
            foundNode = root->findByName(parentName);
            if (foundNode && foundNode->isDirectory()) {
                DirectoryNode* parentDir = dynamic_cast<DirectoryNode*>(foundNode);
                File* newFile = new File(name, parentDir);
                parentDir->addChild(name, newFile);
                cout << "File created.\n";
            } else {
                cout << "Parent directory not found.\n";
            }
            break;

        case 3:
            cout << "Enter parent directory name (or Root): ";
            getline(cin, parentName);

            if (parentName == "Root") {
                foundNode = root;
            } else {
                foundNode = root->findByName(parentName);
            }

            if (foundNode && foundNode->isDirectory()) {
                DirectoryNode* parentDir = dynamic_cast<DirectoryNode*>(foundNode);
                cout << "Enter file name: ";
                getline(cin, name);
            
                Node* fileNode = parentDir->getChild(name);
                if (fileNode && !fileNode->isDirectory()) {
                    cout << "Enter content: ";
                    getline(cin, content);
                    dynamic_cast<File*>(fileNode)->addContent(content);
                    cout << "Content added.\n";
                } else {
                    cout << "File not found in the specified folder.\n";
                }
            } else {
                cout << "Parent directory not found.\n";
            }


        case 4:
            root->list();
            break;

        case 5:
            cout << "Enter directory name to search in (or Root): ";
            getline(cin, parentName);

            if (parentName == "Root") {
                foundNode = root;
            } else {
                foundNode = root->findByName(parentName);
            }

            if (foundNode && foundNode->isDirectory()) {
                DirectoryNode* parentDir = dynamic_cast<DirectoryNode*>(foundNode);
            
                cout << "Enter name to search: ";
                getline(cin, name);
            
                Node* result = parentDir->findByName(name);
                if (result) {
                    cout << "Found:\n";
                    result->display();
                } else {
                    cout << "Not found in this directory.\n";
                }
            } else {
                cout << "Directory not found.\n";
            }


        case 6: {
            cout << "Enter directory name to search in (or Root): ";
            getline(cin, parentName);

            if (parentName == "Root") {
                foundNode = root;
            } else {
                foundNode = root->findByName(parentName);
            }
        
            if (foundNode && foundNode->isDirectory()) {
                DirectoryNode* parentDir = dynamic_cast<DirectoryNode*>(foundNode);
            
                cout << "Enter current name: ";
                getline(cin, name);
            
                Node* target = parentDir->getChild(name);
                if (target) {
                    cout << "Enter new name: ";
                    getline(cin, newName);
                    target->rename(newName);
                    cout << "Renamed.\n";
                } else {
                    cout << "Node not found in this directory.\n";
                }
            } else {
                cout << "Directory not found.\n";
            }
            break;
        }


        case 7:
            cout << "Enter parent directory name: ";
            getline(cin, parentName);
            cout << "Enter child name to delete: ";
            getline(cin, name);
            foundNode = root->findByName(parentName);
            if (foundNode && foundNode->isDirectory()) {
                DirectoryNode* parentDir = dynamic_cast<DirectoryNode*>(foundNode);
                if (parentDir->removeChild(name))
                    cout << "Deleted.\n";
                else
                    cout << "Delete failed.\n";
            } else {
                cout << "Parent directory not found.\n";
            }
            break;

        case 8:
            cout << "Enter name to copy: ";
            getline(cin, srcName);
            cout << "Enter destination directory name: ";
            getline(cin, destName);
            {
                Node* src = root->findByName(srcName);
                Node* dest = root->findByName(destName);
                if (src && dest && dest->isDirectory()) {
                    DirectoryNode* destDir = dynamic_cast<DirectoryNode*>(dest);
                    Node* copyNode = src->clone(src, destDir);
                    destDir->addChild(copyNode->getName(), copyNode);
                    cout << "Copied.\n";
                } else {
                    cout << "Copy failed.\n";
                }
            }
            break;

        case 9:
            cout << "Enter name to move: ";
            getline(cin, srcName);
            cout << "Enter destination directory name: ";
            getline(cin, destName);
            {
                Node* src = root->findByName(srcName);
                Node* dest = root->findByName(destName);
                if (src && dest && dest->isDirectory()) {
                    DirectoryNode* parentDir = dynamic_cast<DirectoryNode*>(src->getParent());
                    DirectoryNode* destDir = dynamic_cast<DirectoryNode*>(dest);
                    parentDir->move(src, destDir);
                } else {
                    cout << "Move failed.\n";
                }
            }
            break;

        case 10:
            cout << "Enter name: ";
            getline(cin, name);
            foundNode = root->findByName(name);
            if (foundNode) {
                cout << "Full Path: " << foundNode->getFulPath() << "\n";
            } else {
                cout << "Not found.\n";
            }
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
