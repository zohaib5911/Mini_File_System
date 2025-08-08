#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

class Node{
protected:
    string name;
    Node * parent;
public: 
    Node():name("NULL"),parent(nullptr){}
    Node(string name, Node* parent = nullptr) : name(name), parent(parent) {}
    string getName() { return this->name; }
    virtual string getFulPath() = 0;
    Node * getParent(){ return this->parent; } 
    virtual void display() const = 0; 
    virtual void rename(const string& newName) = 0;
    virtual bool isDirectory() const = 0; 
    virtual void list(int depth) const = 0;
    virtual ~Node() = default;
    virtual Node* getChild(const string& chld) = 0 ;
    virtual Node* findByName(string nam) =0;
    virtual Node* clone(Node* toClone, Node* newParent) = 0;
};

#endif