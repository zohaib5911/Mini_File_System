#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H
#include <iostream>
#include "Node.h"
#include <vector>
#include "file.h"
#include <map>

class DirectoryNode: public Node{
    map<string,Node*> children;

public:
    DirectoryNode(){
        this->name = "Null";
        this->parent = nullptr;
    }
    DirectoryNode(const string& name, Node* parent = nullptr) {
        this->name = name;
        this->parent = parent;
    }
    void addChild(string nam,Node* child){
        children.insert_or_assign(nam,child);
    }
    bool isValidChild(const string& chld) const{
        auto it =  children.find(chld);
        if(it == children.end()){
           return false;
        }
        return true;
    }
    bool removeChild(const string& chld){
        if(this->isValidChild(chld)){
            children.erase(chld);
            return true;
        }   
        return false;
    }
    void display() const override{
       cout<<"[DIR]"<<this->name<<endl;
       for(auto i : this->children){
            cout<<"         |-> "<<i.first<<endl;
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
    Node* getChild(const string& chld){
        auto it =  children.find(chld);
        if(it == children.end()){
            cout<<chld<<" not found";
            return nullptr;
        }
        return it->second;
    }
    bool isDirectory() const override {
        return true;
    };  
    void list(int depth=0) const override{
        for(int i=0;i<depth;i++){ cout<<"         ";}
        cout<<this->name<<endl;
        for(auto i:this->children){
            i.second->list(depth+1);
        }
    }
    string getFulPath(){
        vector<string> names;
        string path;
        Node * temp = this;
        while(temp!=nullptr){
            names.push_back(temp->getName());
            temp = temp->getParent();
        }
        for (int i = names.size() - 1; i >= 0; --i) {
            path.append(names[i]);
            if (i != 0) path.append(" -> ");
        }
        return path;
    }

    void duplicate(const string& doc) {
        Node* temp = findByName(doc);
        if (temp == nullptr) {
            cout << doc << " Not Found\n";
            return;
        }
        Node* cloned = nullptr;
        if (dynamic_cast<DirectoryNode*>(temp)) {
            cloned = new DirectoryNode();
        } else {
            cloned = new File();
        }
        cloned = cloned->clone(temp, this);
        this->addChild(cloned->getName(), cloned);
    }

    Node* clone(Node* other, Node* newParent) override {
        DirectoryNode* otherDir = dynamic_cast<DirectoryNode*>(other);
        DirectoryNode* newDir = dynamic_cast<DirectoryNode*>(newParent);        
        if (!otherDir) return nullptr;

        DirectoryNode* copied = new DirectoryNode();
        copied->name = otherDir->getName() + "_Copy";
        copied->parent = newDir;

        for (auto& [childName, childNode] : otherDir->children) {
            Node* clonedChild = nullptr;
            if (dynamic_cast<DirectoryNode*>(childNode)) {
                clonedChild = new DirectoryNode();
            } else {
                clonedChild = new File();
            }
            clonedChild = clonedChild->clone(childNode, copied);
            copied->addChild(childName, clonedChild);
        }

        return copied;
    }

    ~DirectoryNode() override {
        for (auto& [_, child] : children) {
            delete child;
        }
    }
};

#endif