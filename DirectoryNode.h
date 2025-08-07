#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H
#include <iostream>
#include "Node.h"
#include "file.h"
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
       cout<<this->name<<endl;
       for(auto i : this->children){
            cout<<this->name<<" -> "<<i.first<<endl;
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

    ~DirectoryNode() override {
        for (auto& [_, child] : children) {
            delete child;
        }
    }
};

#endif