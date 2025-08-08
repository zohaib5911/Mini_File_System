#ifndef FILE_H
#define FILE_H
#include "Node.h"
// #include "DirectoryNode.h"

class File : public Node{
private:
    string content;
    Node* getChild(const string& chld) override{ return nullptr; }
    void list (int depth = 0)const override{ return; }
    Node* findByName(string nam) override {return nullptr; }
public:
    // File() : Node() {}
    File(){
        this->name = "Null";
        content = "";
        this->parent = nullptr;
    }
    File(const string& name,Node* parent):content(""){
        this->name =  name;
        this->parent = parent;
    }
    void addContent(const string& contnt){
        this->content.append(contnt);
    }
    void rename(const string& newName) override{
        this->name = newName;
    }
    bool isDirectory() const override{ return false; }
    void display() const override{
        cout<<this->name<<endl;
        cout<<"\t\t\t\t"<<content<<endl;
    }
    string getContent(){ return this->content; }

    Node* clone(Node* other, Node* newParent) override {
        File* otherFile = dynamic_cast<File*>(other);
        if (!otherFile) return nullptr;

        File* copied = new File();
        copied->name = otherFile->name + "_Copy";
        copied->parent = newParent;
        copied->content = otherFile->content;
        return copied;
    }

};


#endif // 