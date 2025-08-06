#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H
#include <iostream>
#include "Node.h"
#include <map>

class DirectoryNode: public Node{
    map<string,Node*> children;
public:
    DirectoryNode(const string& name, Node* parent = nullptr) {
        this->name = name;
        this->parent = parent;
    }
    void addChild(string nam,Node* child){
        children.insert_or_assign(nam,child);
    }
    void display() const override{
       cout<<this->name<<endl;
       for(auto i : this->children){
            cout<<i.first<<" -> "<<i.second->getName()<<endl;
       }
    }
    Node* findByName(string nam){
        auto it =  children.find(nam);
        if(it == children.end()){
            cout<<nam<<" not found";
            return nullptr;
        }
        return it->second;
    }
    bool isDirectory() const override {
        return true;
    }; 
    void list(int depth) const override{

    }
    ~DirectoryNode() override {
        for (auto& [_, child] : children) {
            delete child;
        }
    }
};

#endif