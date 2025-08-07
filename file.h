#ifndef FILE_H
#define FILE_H
#include "Node.h"

class File : public Node{
    string content;
     void list (int depth = 0)const override{ return; }
public:
    File(const string& name,Node* parent):content(""){
        this->name =  name;
        this->parent = parent;
    }
    void addContent(const string& contnt){
        this->content.append(contnt);
    }
    bool isDirectory() const override{ return false; }
    void display() const override{
        cout<<this->name<<endl;
        cout<<"\t\t\t\t"<<content<<endl;
    }
    string getContent(){ return this->content; }
};


#endif // 